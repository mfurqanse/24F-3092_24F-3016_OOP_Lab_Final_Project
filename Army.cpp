// Army.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>


Army::Army() {
    soldiers = 0;
    morale = 100;
    isCorrupt = false;
}

void Army::recruit(int population) {
    if (population >= 10) {
        soldiers += 10;
        std::cout << "10 Soldiers recruited.\n";
    }
}

void Army::train() {
    if (soldiers > 0) {
        morale += 5;
        if (morale > 100) morale = 100;
        std::cout << "Soldiers trained.\n";
    }
}

void Army::pay() {
    if (soldiers > 0) {
        morale += 10;
        std::cout << "Army paid. Morale increased.\n";
    }
    else {
        isCorrupt = true;
    }
}
