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
    int width;  // Width of the environment
    int height;  // Height of the environment

    template <typename T, typename DistributionFunc>
    void generateZone(std::vector<std::vector<T>>& zone, DistributionFunc&& distributionFunc);

    std::vector<std::vector<float>> nutrients;  // Nutrient distribution in the environment
    std::vector<std::vector<float>> currentX;
    std::vector<std::vector<float>> currentY;
    std::vector<std::vector<bool>> obstacles;  // Obstacle distribution in the environment
    std::vector<std::vector<bool>> toxicZones;  // Toxic zone distribution in the environment
    std::vector<std::vector<bool>> lightZones;

    /*void distributeNutrients();
    void generateObstacles();
    void generateToxicZones();*/


};

#endif  // ENVIRONMENT_H
