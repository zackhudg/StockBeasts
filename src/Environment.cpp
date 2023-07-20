#include "Environment.h"

Environment::Environment() {
    // Initialize member variables of the environment
    width = 100;
    height = 100;
}

void Environment::initialize() {
    // Perform initialization steps for the environment
    nutrients.resize(width, std::vector<float>(height, 0.0f));
    obstacles.resize(width, std::vector<bool>(height, false));
    toxicZones.resize(width, std::vector<bool>(height, false));

    /*distributeNutrients();
    generateObstacles();
    generateToxicZones();*/

    // TODO: replace magic numbers?

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    float threshold = 0.5f;
    
    noise.SetFrequency(2.0f);
    generateZone(nutrients, [noise](int x, int y) { return noise.GetNoise(x, y); });

    noise.SetSeed(rand());
    generateZone(obstacles, [noise, threshold](int x, int y) { return noise.GetNoise(x, y) > threshold; });

    noise.SetFrequency(0.5f);
    generateZone(lightZones, [noise, threshold](int x, int y) { return noise.GetNoise(x, y) > threshold; });

    noise.SetFrequency(8.0f);
    generateZone(toxicZones, [noise, threshold](int x, int y) { return noise.GetNoise(x, y) > threshold; });

    noise.SetFrequency(4.0f);
    noise.SetSeed(rand());
    generateZone(currentX, [noise](int x, int y) { return noise.GetNoise(x, y); });
    noise.SetSeed(rand());
    generateZone(currentY, [noise](int x, int y) { return noise.GetNoise(x, y); });

}

void Environment::update() {
    // Perform update steps for the environment
    // Update resource availability, handle environmental changes, etc.
    // ...
}

// Function template definition
template <typename T, typename DistributionFunc>
void Environment::generateZone(std::vector<std::vector<T>>& zone, DistributionFunc&& distributionFunc) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            zone[i][j] = distributionFunc(i, j);
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
