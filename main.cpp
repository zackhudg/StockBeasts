#include <iostream>
#include <vector>
#include "Organism.h"
#include "Environment.h"

int main() {
    // Simulation parameters
    int numOrganisms = 100;
    int numCycles = 100;

    // Create initial population of organisms
    std::vector<Organism> organisms;
    for (int i = 0; i < numOrganisms; ++i) {
        organisms.push_back(Organism());
    }

    // Create environment
    Environment environment;
    // Initialize environment (set up initial conditions, boundaries, etc.)
    environment.initialize();

    // Simulation loop
    for (int cycle = 1; cycle <= numCycles; ++cycle) {
        std::cout << "Cycle " << cycle << std::endl;

        // Perform actions for each organism
        for (Organism& organism : organisms) {
            // Update organism's state
            organism.update();

            // Move organism
            organism.move();

            // Interact with environment and other organisms
            organism.interact(environment, organisms)
        }

        // Perform any additional simulation logic or analysis here
    }

    return 0;
}
