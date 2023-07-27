#include "Environment.h"

#ifdef _DEBUG
#include <iostream>
#endif

Environment::Environment() {
    // Initialize member variables of the environment
    width = 50;
    height = 50;
}

void Environment::initialize() {
    // Perform initialization steps for the environment
    nutrients.resize(width, std::vector<float>(height, 0.0f));
    obstacles.resize(width, std::vector<bool>(height, false));
    toxicZones.resize(width, std::vector<bool>(height, false));
    lightZones.resize(width, std::vector<bool>(height, false));
    toxicZones.resize(width, std::vector<bool>(height, false));
    currentX.resize(width, std::vector<float>(height, 0.0f));
    currentY.resize(width, std::vector<float>(height, 0.0f));


    /*distributeNutrients();
    generateObstacles();
    generateToxicZones();*/

    // TODO: replace magic numbers?

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    
    // Big zones
    // threshold is for ranges (-1, 1)
    float threshold = 0.0f;
    noise.SetSeed(rand());
    noise.SetFrequency(0.025f);
    generateZone(lightZones, [noise, threshold](float x, float y) { return noise.GetNoise(x, y) > threshold; });
    
    threshold = 0.3f;
    noise.SetFrequency(0.05f);
    noise.SetSeed(rand());
    generateZone(obstacles, [noise, threshold](float x, float y) { return noise.GetNoise(x, y) > threshold; });

    noise.SetSeed(rand());
    generateZone(currentX, [noise](float x, float y) { return std::max(0.0f, (noise.GetNoise(x, y) + 1.0f)); });
    noise.SetSeed(rand());
    generateZone(currentY, [noise](float x, float y) { return std::max(0.0f, (noise.GetNoise(x, y) + 1.0f)); });

    noise.SetSeed(rand());
    threshold = 0.6f;
    generateZone(toxicZones, [noise, threshold](float x, float y) { return noise.GetNoise(x, y) > threshold; });

    // Smaller zones
    noise.SetSeed(rand());
    noise.SetFrequency(0.1f);
    generateZone(nutrients, [noise](float x, float y) {  float noiseValue = noise.GetNoise(x, y);  return (noiseValue > 0.5f) * noiseValue; });

    


   /* noise.SetFrequency(1.0f);
    generateZone(nutrients, [noise](float x, float y) { return (noise.GetNoise(x, y) + 1.0f) / 2.0f; });*/

    std::string n = "Nutrients\n", o="Obstacles\n", l="Light\n", t="Toxic\n", x="CurrentX\n", y="CurrentY\n";
    std::vector<std::string*> zones = { &n, &o, &l, &t, &x, &y };
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            *zones[0] += " " + std::to_string(nutrients[i][j]);
            *zones[1] += " " + std::to_string(obstacles[i][j]);
            *zones[2] += " " + std::to_string(lightZones[i][j]);
            *zones[3] += " " + std::to_string(toxicZones[i][j]);
            *zones[4] += " " + std::to_string(currentX[i][j]);
            *zones[5] += " " + std::to_string(currentY[i][j]);
        }
        for (std::string* zoneString : zones) {
            *zoneString += "\n";
        }
    }
    for (std::string* zoneString : zones) {
        std::cout << *zoneString << "\n";
    }


    //for (float t = -0.75f; t < 1.0f; t += 0.25f) {
    //    for (float f = 0.0f; f < 0.25; f += 0.05f) {
    //        std::cout << "Threshold: " << t << "\t Frequency: " << f << std::endl;
    //            noise.SetSeed(rand());
    //        noise.SetFrequency(f);
    //        generateZone(obstacles, [noise, t](float x, float y) { return noise.GetNoise(x, y) > t; });
    //            for (int i = 0; i < height; ++i) {
    //                for (int j = 0; j < width; ++j) {
    //                    std::cout << obstacles[i][j] << " ";
    //                }
    //                std::cout << std::endl;
    //            }std::cout << std::endl;
    //            
    //        std::cout << "\n\n\n\n";
    //        
    //    }
    //}
}

void Environment::update() {
    // Perform update steps for the environment
    // Update resource availability, handle environmental changes, etc.
    // ...
}

// Function template definition
template <typename T, typename DistributionFunc>
void Environment::generateZone(std::vector<std::vector<T>>& zone, DistributionFunc&& distributionFunc) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            zone[i][j] = distributionFunc(static_cast<float>(i), static_cast<float>(j));
        }
    }
}

//void Environment::distributeNutrients() {
//    // Distribute nutrients randomly or based on certain patterns throughout the environment
//    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
//    for (int i = 0; i < width; ++i) {
//        for (int j = 0; j < height; ++j) {
//            nutrients_[i][j] = distribution(rng_);
//        }
//    }
//}
//
//
//void Environment::generateObstacles() {
//    // Generate obstacles using Perlin noise to create clumping patterns
//    FastNoiseLite noise;
//    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
//    noise.SetFrequency(0.05f);  // Adjust the frequency to control the clumping scale
//
//    for (int i = 0; i < width; ++i) {
//        for (int j = 0; j < height; ++j) {
//            obstacles_[i][j] = noise.GetNoise(i, j) > 0.4f;  // Adjust the threshold to control obstacle density
//        }
//    }
//}
//
//void Environment::generateToxicZones() {
//    // Generate toxic zones using Perlin noise to create clumping patterns
//    FastNoiseLite noise;
//    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
//    noise.SetFrequency(0.1f);  // Adjust the frequency to control the clumping scale
//
//    for (int i = 0; i < width; ++i) {
//        for (int j = 0; j < height; ++j) {
//            toxicZones_[i][j] = noise.GetNoise(i, j) > 0.5f;  // Adjust the threshold to control toxic zone density
//        }
//    }
//}
