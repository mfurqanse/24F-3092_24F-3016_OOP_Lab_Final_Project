#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <fstream>


void FileManager::saveGame(const Population& pop, const Economy& eco) {
    std::ofstream out("game_save.txt");
    if (!out) throw FileIOException();
    out << pop.totalPopulation << "\n" << eco.treasury << "\n";
    out.close();
}

void FileManager::logScore(const Economy& eco, const Army& army) {
    std::ofstream log("score.txt", std::ios::app);
    if (!log) throw FileIOException();
    log << "Score Log -- Treasury: " << eco.treasury
        << ", Army: " << army.soldiers << "\n";
    log.close();
    std::cout << "[Log] Score written to score.txt\n";
}
void FileManager::saveFullGame(const Population& pop, const Economy& eco, const Army& army, int turn, const char* filename) {
    std::ofstream out(filename);
    if (!out) throw FileIOException();

    out << pop.totalPopulation << "\n"
        << pop.foodSupply << "\n"
        << pop.shelter << "\n"
        << pop.employment << "\n";

    out << eco.treasury << "\n"
        << eco.taxRate << "\n"
        << eco.inflation << "\n";

    out << army.soldiers << "\n"
        << army.morale << "\n"
        << army.isCorrupt << "\n";

    out << turn << "\n";

    out.close();
}

void FileManager::loadFullGame(Population& pop, Economy& eco, Army& army, int& turn, const char* filename) {
    std::ifstream in(filename);
    if (!in) throw FileIOException();

    in >> pop.totalPopulation >> pop.foodSupply >> pop.shelter >> pop.employment;
    in >> eco.treasury >> eco.taxRate >> eco.inflation;
    in >> army.soldiers >> army.morale >> army.isCorrupt;
    in >> turn;

    in.close();
}

