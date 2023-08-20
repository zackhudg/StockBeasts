#include <iostream>
#include <vector>
#include <random>
#include "Organism.h"
#include "Environment.h"
#include "StockAPI.h"
#include "config.h"

int main() {

    // Simulation parameters
    int numOrganisms = 3;
    int numCycles = 0;
    int height = 20;
    int width = 20;

    StockAPI stocks = StockAPI(API_KEY);
    std::unordered_map<std::string, StockData> stockData;
    if (!stocks.initStockMap(stockData)) {
        std::cout << "Failed to initialize stock map.\n";
    }

    // Create initial population of organisms
    //TODO: shuffle the stock order probably.
    std::vector<Organism> organisms(numOrganisms);
    for (int i = 0; i < numOrganisms; i++) {
        for (int j = 0; j < Organism::GENOTYPE_SIZE; j++){
            auto randomIterator = std::next(stockData.begin(), std::rand() % stockData.size());
            const std::string& key = randomIterator->first;
            organisms[i].genotype.push_back(key);
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
