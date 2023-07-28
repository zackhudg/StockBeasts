#include <iostream>
#include <vector>
#include "Organism.h"
#include "Environment.h"
#include "StockAPI.h"
#include "config.h"

int main() {

    // Simulation parameters
    int numOrganisms = 10;
    int numCycles = 0;
    int height = 100;
    int width = 100;

    StockAPI stocks = StockAPI(API_KEY);
    std::unordered_map<std::string, StockData> stockData;
    if (!stocks.initStockMap(stockData, numOrganisms * (Organism::GENOTYPE_SIZE))) {
        std::cout << "Faile to initialize stock map.\n";
    }

        // Create initial population of organisms
    std::vector<Organism> organisms(numOrganisms);
    {
        int counter = 0;
        for (const auto& entry : stockData) {
            const std::string& key = entry.first;
            organisms[counter / Organism::GENOTYPE_SIZE].genotype[counter % Organism::GENOTYPE_SIZE] = key;
        }
    }

    // Create environment
    Environment environment(height,width);
    // Initialize environment (set up initial conditions, boundaries, etc.)
    environment.initialize();

    // Simulation loop
    // for (int cycle = 1; cycle <= numCycles; ++cycle) {
    //     std::cout << "Cycle " << cycle << std::endl;
    // 
    //     // Perform actions for each organism
    //     for (Organism& organism : organisms) {
    //         // Update organism's state
    //         organism.update();
    // 
    //         // Move organism
    //         organism.move();
    // 
    //         // Interact with environment and other organisms
    //         organism.interact(environment, organisms)
    //     }
    // 
    //     // Perform any additional simulation logic or analysis here
    // }

    return 0;
}
