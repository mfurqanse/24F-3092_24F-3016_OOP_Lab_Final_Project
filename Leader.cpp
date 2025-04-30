#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>
#include <cstring>

Leader::Leader(const char* n, int s, Trait type) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    stability = s;
    personality = type;
}

Trait Leader::getPersonality() const {
    return personality;
}
void Leader::setPersonality(Trait newTrait) {
    personality = newTrait;
}


Leader::~Leader() {
    delete[] name;
}

void Leader::changePolicy() {
    std::cout << name << " enacts a new policy.\n";
}

void Leader::handleCrisis() {
    std::cout << name << " is handling a crisis in the kingdom.\n";
}
