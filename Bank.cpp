// Bank.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>


Bank::Bank() {
    funds = 500;
    loanGiven = 0;
}

void Bank::giveLoan(int amount) {
    if (amount > 0 && amount <= funds) {
        funds -= amount;
        loanGiven += amount;
        std::cout << "[Bank] Loan of " << amount << " given.\n";
    }
    else {
        std::cout << "[Bank] Insufficient funds for loan.\n";
    }
}

void Bank::audit() {
    if (loanGiven > 200) {
        std::cout << "[Audit Warning] Excessive loans may indicate corruption!\n";
    }
    else {
        std::cout << "[Audit] All financials are clean.\n";
    }
}

