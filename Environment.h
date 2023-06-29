#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <random>
#include "Organism.h"
#include "FastNoiseLite.h"

class Environment {
public:
    Environment();  // Constructor
    void initialize();
    void update();

private:
    // Define any necessary member variables for the environment
    int width_;  // Width of the environment
    int height_;  // Height of the environment
    std::vector<std::vector<float>> nutrients_;  // Nutrient distribution in the environment
    std::vector<std::vector<bool>> obstacles_;  // Obstacle distribution in the environment
    std::vector<std::vector<bool>> toxicZones_;  // Toxic zone distribution in the environment

    std::random_device rd_;  // Random device for generating random numbers
    std::mt19937 rng_;  // Random number generator

    void distributeNutrients();
    void generateObstacles();
    void generateToxicZones();
};

#endif  // ENVIRONMENT_H
