#include "Environment.h"

#ifdef _DEBUG
#include <iostream>
#endif

Environment::Environment(int width, int height) : width(width), height(height) {}
    // Initialize member variables of the environment

void Environment::initialize() {
    // Perform initialization steps for the environment
    nutrients.resize(width, std::vector<float>(height, 0.0f));
    obstacles.resize(width, std::vector<bool>(height, false));
    toxicZones.resize(width, std::vector<bool>(height, false));
    currentX.resize(width, std::vector<float>(height, 0.0f));
    currentY.resize(width, std::vector<float>(height, 0.0f));
    // lightZones.resize(width, std::vector<bool>(height, false));


    // TODO: replace magic numbers? namespaces? init?
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    // Big zones
    // threshold is for ranges (-1, 1)
    // 
    // float threshold = 0.0f;
    // noise.SetSeed(rand());
    // noise.SetFrequency(0.025f);
    // generateZone(lightZones, [noise, threshold](float x, float y) { return noise.GetNoise(x, y) > threshold; });

    float threshold = 0.3f;
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
    threshold = 0.5f;
    noise.SetFrequency(0.1f);
    generateZone(nutrients, [noise, threshold](float x, float y) {  float noiseValue = noise.GetNoise(x, y);  return (noiseValue > threshold) * noiseValue; });
    // Other potential speed improvements:  init this as a map datatype, with coordinate:value pairs since lots of 0s (wasted space)
    //                                      use SIMD instructions for basically matrix addition
    newNutrients = nutrients;

#ifdef _DEBUG
    std::string n = "Nutrients\n", o = "Obstacles\n", l = "Light\n", t = "Toxic\n", x = "CurrentX\n", y = "CurrentY\n";
    std::vector<std::string*> zones = { &n, &o, &l, &t, &x, &y };
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *zones[0] += " " + std::to_string(nutrients[i][j]);
            *zones[1] += " " + std::to_string(obstacles[i][j]);
            // *zones[2] += " " + std::to_string(lightZones[i][j]);
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
#endif

}

void Environment::update() {
    // potential speed improvements:  init this as a map datatype, with coordinate:value pairs since lots of 0s (wasted space)
    //                                      use SIMD instructions for basically matrix addition
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            nutrients[i][j] += newNutrients[i][j];
        }
    }
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

