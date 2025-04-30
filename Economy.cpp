// Economy.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>


Economy::Economy() {
    treasury = 1000;
    taxRate = 0.1f;
    inflation = 1.0f;
}

void Economy::collectTax(int population) {
    float tax = population * 10 * taxRate;
    treasury += tax;
    std::cout << "Collected tax: " << tax << "\n";
}

void Economy::adjustTaxRate(float rate) {
    if (rate >= 0 && rate <= 1.0) {
        taxRate = rate;
    }
}
