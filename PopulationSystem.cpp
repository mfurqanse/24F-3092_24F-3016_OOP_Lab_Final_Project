// PopulationSystem.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>


Population::Population() {
    totalPopulation = 100;
    foodSupply = 100;
    shelter = 100;
    employment = 100;
}

void Population::updateGrowth() {
    if (foodSupply > 50 && shelter > 50) {
        totalPopulation += 5;
        std::cout << "[Growth] Population increased to " << totalPopulation << "\n";
    }
    else {
        totalPopulation -= 3;
        if (totalPopulation < 0) totalPopulation = 0;
        std::cout << "[Decline] Population dropped to " << totalPopulation << "\n";
    }
}

void Population::applyIllness() {
    totalPopulation -= 10;
    if (totalPopulation < 0) totalPopulation = 0;
}

void Population::revolt() {
    if (employment < 30) {
        std::cout << "[Revolt] Citizens are revolting due to unemployment!\n";
    }
}
