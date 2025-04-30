// Event.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>
#include <cstdlib>


Event::Event(const char* desc) {
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}

Event::~Event() {
    delete[] description;
}

void Event::trigger(Population& pop, Army& army, Leader& leader) {
    int roll = rand() % 3;

    switch (roll) {
    case 0: // Famine
        std::cout << "[Event: " << description << "] ? Famine strikes!\n";
        if (leader.getPersonality() == WISE)
            pop.totalPopulation -= 5;
        else
            pop.totalPopulation -= 10;
        if (pop.totalPopulation < 0) pop.totalPopulation = 0;
        break;

    case 1: // War
        std::cout << "[Event: " << description << "] ? Enemy invasion!\n";
        army.recruit(20);
        army.morale -= (leader.getPersonality() == WARLORD) ? 10 : 20;
        break;

    case 2: // Corruption
        std::cout << "[Event: " << description << "] ? Treasury audit!\n";
        if (leader.getPersonality() == GREEDY)
            std::cout << "[Leader Bonus] Embezzlement hidden... no penalty.\n";
        else
            army.isCorrupt = true;
        break;
    }

    //  ADD THIS TRAIT EVOLUTION BLOCK BELOW THE SWITCH:
    if (roll == 0) {  // famine
        famineCount++;
        if (famineCount >= 2 && leader.getPersonality() == GREEDY) {
            std::cout << "[Event Impact] Your suffering people have changed you...\n";
            leader.setPersonality(WISE);
        }
    }
    else if (roll == 1) {  // war
        warCount++;
        if (warCount >= 3 && leader.getPersonality() == WISE) {
            std::cout << "[Event Impact] War hardens you... you become a Warlord.\n";
            leader.setPersonality(WARLORD);
        }
    }
}

