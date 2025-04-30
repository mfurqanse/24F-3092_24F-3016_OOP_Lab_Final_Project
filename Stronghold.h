// Stronghold.h
#ifndef STRONGHOLD_H
#define STRONGHOLD_H
extern int famineCount;
extern int warCount;

#include <iostream>
#include <cstring>

// ------------------ Exceptions ------------------
class GameException {
public:
    virtual const char* what() const = 0;
};

class InvalidOperationException : public GameException {
    const char* msg;
public:
    InvalidOperationException(const char* m) {
        msg = m;
    }
    const char* what() const override {
        return msg;
    }
};


class FileIOException : public GameException {
    const char* what() const override {
        return "File operation failed.";
    }
};

// ------------------ Population ------------------
class Population {
public:
    int totalPopulation;
    int foodSupply;
    int shelter;
    int employment;

    Population();
    void updateGrowth();
    void applyIllness();
    void revolt();
};

// ------------------ Army ------------------
class Army {
public:
    int soldiers;
    int morale;
    bool isCorrupt;

    Army();
    void recruit(int population);
    void train();
    void pay();
};

// ------------------ Social Classes ------------------
class SocialClass {
protected:
    char* name;

public:
    SocialClass(const char* name);
    virtual ~SocialClass();
};

class Peasant : public SocialClass {
public:
    Peasant();
    void complain();
};

class Merchant : public SocialClass {
public:
    Merchant();
    void trade();
};

class Noble : public SocialClass {
public:
    Noble();
    void scheme();
};

// ------------------ Leader ------------------
enum Trait { GREEDY, WISE, WARLORD };

class Leader {
private:
    char* name;
    int stability;
    Trait personality;  //  New

public:
    Leader(const char* name, int stability, Trait type);
    ~Leader();
    void changePolicy();
    void handleCrisis();
    Trait getPersonality() const; // Getter
    void setPersonality(Trait newTrait);

};


// ------------------ Economy ------------------
class Economy {
public:
    float treasury;
    float taxRate;
    float inflation;

    Economy();
    void collectTax(int population);
    void adjustTaxRate(float rate);
};

// ------------------ Bank ------------------
class Bank {
public:
    int funds;
    int loanGiven;

    Bank();
    void giveLoan(int amount);
    void audit();
};

// ------------------ Resource ------------------
class Resource {
    char* name;
    int amount;

public:
    Resource(const char* type, int amount);
    ~Resource();
    void gather(int qty);
    void consume(int qty);
    int getAmount() const;
};

// ------------------ Event ------------------
class Event {
    char* description;

public:
    Event(const char* desc);
    ~Event();
    void trigger(Population& pop, Army& army, Leader& leader);

};

// ------------------ File Manager ------------------
class FileManager {
public:
    void saveGame(const Population& pop, const Economy& eco);
    void logScore(const Economy& eco, const Army& army);
    void saveFullGame(const Population& pop, const Economy& eco, const Army& army, int turn, const char* filename);
    void loadFullGame(Population& pop, Economy& eco, Army& army, int& turn, const char* filename);

};
// Utility Logger (Global function declaration)
void logTurn(const Population& pop, const Economy& eco, const Army& army, const char* who);


#endif // STRONGHOLD_H
