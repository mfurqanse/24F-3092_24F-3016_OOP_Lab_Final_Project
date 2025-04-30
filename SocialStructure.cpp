// SocialStructure.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "Stronghold.h"
#include <iostream>

// Base Class
SocialClass::SocialClass(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
SocialClass::~SocialClass() {
    delete[] name;
}

// Derived Classes
Peasant::Peasant() : SocialClass("Peasant") {}
void Peasant::complain() {
    std::cout << "Peasant complains about taxes.\n";
}

Merchant::Merchant() : SocialClass("Merchant") {}
void Merchant::trade() {
    std::cout << "Merchant trades in the market.\n";
}

Noble::Noble() : SocialClass("Noble") {}
void Noble::scheme() {
    std::cout << "Noble is plotting political schemes.\n";
}
