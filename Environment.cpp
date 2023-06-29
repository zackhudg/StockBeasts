#include "Environment.h"

Environment::Environment() : rng_(rd_()) {
    // Initialize member variables of the environment
    width_ = 100;
    height_ = 100;
}

void Environment::initialize() {
    // Perform initialization steps for the environment
    nutrients_.resize(width_, std::vector<float>(height_, 0.0f));
    obstacles_.resize(width_, std::vector<bool>(height_, false));
    toxicZones_.resize(width_, std::vector<bool>(height_, false));

    distributeNutrients();
    generateObstacles();
    generateToxicZones();
}

void Environment::update() {
    // Perform update steps for the environment
    // Update resource availability, handle environmental changes, etc.
    // ...
}

void Environment::distributeNutrients() {
    // Distribute nutrients randomly or based on certain patterns throughout the environment
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    for (int i = 0; i < width_; ++i) {
        for (int j = 0; j < height_; ++j) {
            nutrients_[i][j] = distribution(rng_);
        }
    }
}

void Environment::generateObstacles() {
    // Generate obstacles using Perlin noise to create clumping patterns
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(0.05f);  // Adjust the frequency to control the clumping scale

    for (int i = 0; i < width_; ++i) {
        for (int j = 0; j < height_; ++j) {
            obstacles_[i][j] = noise.GetNoise(i, j) > 0.4f;  // Adjust the threshold to control obstacle density
        }
    }
}

void Environment::generateToxicZones() {
    // Generate toxic zones using Perlin noise to create clumping patterns
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(0.1f);  // Adjust the frequency to control the clumping scale

    for (int i = 0; i < width_; ++i) {
        for (int j = 0; j < height_; ++j) {
            toxicZones_[i][j] = noise.GetNoise(i, j) > 0.5f;  // Adjust the threshold to control toxic zone density
        }
    }
}
