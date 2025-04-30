// Resource.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>


Resource::Resource(const char* type, int amount) {
    name = new char[strlen(type) + 1];
    strcpy(name, type);
    this->amount = amount;
}

Resource::~Resource() {
    delete[] name;
}

void Resource::gather(int qty) {
    amount += qty;
}

void Resource::consume(int qty) {
    amount -= qty;
    if (amount < 0) amount = 0;
}

int Resource::getAmount() const {
    return amount;
}
