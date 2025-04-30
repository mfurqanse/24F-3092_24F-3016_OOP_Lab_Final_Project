#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <fstream>

void logTurn(const Population& pop, const Economy& eco, const Army& army, const char* who) {
    std::ofstream log("log_turns.txt", std::ios::app);
    if (!log) return;

    log << who << " -- Population: " << pop.totalPopulation
        << ", Treasury: " << eco.treasury
        << ", Army: " << army.soldiers
        << ", Morale: " << army.morale << "\n";

    log.close();
}
