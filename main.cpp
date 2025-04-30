#define _CRT_SECURE_NO_WARNINGS
#include "Stronghold.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>  // for timestamp


int turnCounter = 0;
int warCount = 0;
int famineCount = 0;

int main() {
    Population population;
    Bank bank;

    // ----- Setup -----
    char leaderName[50];
    float initialGold = 1000.0;
    int initialSoldiers = 20;
    int initialFood = 100;

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "=============================================\n";
    std::cout << "        Welcome to Stronghold Setup       \n";
    std::cout << "=============================================\n";
    std::cout << "Prepare your kingdom, name your leader, and\n";
    std::cout << "establish your strength before the first war.\n\n";

    std::cout << "Enter your leader's name: ";
    std::cin.ignore();
    std::cin.getline(leaderName, 50);

    std::cout << "Select Leader Personality:\n";
    std::cout << "1. Greedy\n2. Wise\n3. Warlord\nChoice: ";
    int traitChoice;
    std::cin >> traitChoice;

    Trait selectedTrait;
    switch (traitChoice) {
    case 1: selectedTrait = GREEDY; break;
    case 2: selectedTrait = WISE; break;
    case 3: selectedTrait = WARLORD; break;
    default: selectedTrait = WISE;
    }

    std::cout << "Set starting treasury (e.g., 1000): ";
    std::cin >> initialGold;

    std::cout << "Set starting soldiers (e.g., 20): ";
    std::cin >> initialSoldiers;

    std::cout << "Set starting food (e.g., 100): ";
    std::cin >> initialFood;

    Leader leader(leaderName, 75, selectedTrait);
    Economy economy;
    economy.treasury = static_cast<float>(initialGold);

    Army army;
    army.soldiers = initialSoldiers;

    Resource food("Food", initialFood);
    Event event("Chaos Strikes");
    FileManager fileManager;

    // ----- AI Setup -----
    Population aiPop;
    Army aiArmy;
    Economy aiEco;
    Leader aiLeader("Lord Raven", 65, WARLORD); // give AI a trait too
    Event aiEvent("Shadow Uprising");

    int choice;

    while (true) {
        std::cout << "\n--- Stronghold Kingdom Engine ---\n";
        std::cout << "1. Update Population Growth\n";
        std::cout << "2. Recruit & Train Army\n";
        std::cout << "3. Collect Taxes\n";
        std::cout << "4. Trigger Random Event\n";
        std::cout << "5. Save Game\n";
        std::cout << "6. Log Score\n";
        std::cout << "7. View Kingdom Stats\n";
        std::cout << "8. Simulate Full Turn\n";
        std::cout << "9. Give Loan\n";
        std::cout << "10. Audit Bank\n";
        std::cout << "11. Simulate AI Kingdom Turn\n";
        std::cout << "12. View Turn History\n";
        std::cout << "13. Reset Game\n";
        std::cout << "14. Save Full Game\n";
        std::cout << "15. Load Full Game\n";
        std::cout << "16. View Leader Personality\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                population.updateGrowth();
                break;
            case 2:
                army.recruit(population.totalPopulation);
                army.train();
                break;
            case 3:
                economy.collectTax(population.totalPopulation);
                break;
            case 4:
                event.trigger(population, army, leader);

                break;
            case 5:
                fileManager.saveGame(population, economy);
                break;
            case 6:
                fileManager.logScore(economy, army);
                break;
            case 7:
                std::cout << "\n[Kingdom Stats]\n";
                std::cout << "Population: " << population.totalPopulation << "\n";
                std::cout << "Army: " << army.soldiers << " soldiers, Morale: " << army.morale << "\n";
                std::cout << "Treasury: " << economy.treasury << "\n";
                std::cout << "Food: " << food.getAmount() << "\n";
                break;
            case 8:
                std::cout << "\n[Turn Simulation Started]\n";
                population.updateGrowth();
                economy.collectTax(population.totalPopulation);
                army.pay();
                event.trigger(population, army, leader);
                std::cout << "[Turn Complete]\n";

                logTurn(population, economy, army, "PLAYER");
                logTurn(aiPop, aiEco, aiArmy, "AI");

                turnCounter++;

                // Leader trait evolution (based on events like famineCount, warCount)
                switch (leader.getPersonality()) {
                case GREEDY:
                    economy.taxRate += 0.01f;
                    army.morale -= 5;
                    break;
                case WISE:
                    army.morale += 5;
                    economy.inflation -= 0.05f;
                    break;
                case WARLORD:
                    army.soldiers += 5;
                    economy.taxRate -= 0.01f;
                    break;
                }

                if (turnCounter >= 10) {
                    std::cout << "\n=== Final Round Complete! ===\n";
                    std::cout << " Final Scores:\n";
                    std::cout << "Player - Treasury: " << economy.treasury
                        << ", Soldiers: " << army.soldiers << "\n";
                    std::cout << "AI     - Treasury: " << aiEco.treasury
                        << ", Soldiers: " << aiArmy.soldiers << "\n";

                    float playerScore = economy.treasury + (army.soldiers * 5);
                    float aiScore = aiEco.treasury + (aiArmy.soldiers * 5);

                    if (playerScore > aiScore) {
                        std::cout << " You win the Stronghold!\n";
                        switch (leader.getPersonality()) {
                        case GREEDY:
                            std::cout << "[Ending] Your empire collapsed under its own corruption...\n";
                            break;
                        case WISE:
                            std::cout << "[Ending] Peace and prosperity bloomed under your wise rule...\n";
                            break;
                        case WARLORD:
                            std::cout << "[Ending] Your kingdom stands mighty, feared by all...\n";
                            break;
                        }

                        // Write summary.txt with full stats and result
                        std::time_t now = std::time(0);
                        char* dt = std::ctime(&now);

                        std::ofstream summary("summary.txt");
                        summary << "===== STRONGHOLD GAME SUMMARY =====\n";
                        summary << "Completed at: " << dt << "\n";

                        summary << "Leader Name: " << leaderName << "\n";
                        summary << "Final Trait: ";
                        switch (leader.getPersonality()) {
                        case GREEDY: summary << "GREEDY\nEnding: Collapsed by corruption.\n"; break;
                        case WISE: summary << "WISE\nEnding: Golden era of peace.\n"; break;
                        case WARLORD: summary << "WARLORD\nEnding: Feared by all.\n"; break;
                        }

                        summary << "\nPLAYER STATS:\n";
                        summary << "Treasury: " << economy.treasury << "\n";
                        summary << "Army: " << army.soldiers << "\n";

                        summary << "\nAI STATS:\n";
                        summary << "Treasury: " << aiEco.treasury << "\n";
                        summary << "Army: " << aiArmy.soldiers << "\n";

                        summary << "\nRESULT: Player wins.\n";
                        summary.close();
                    }
                    else if (playerScore < aiScore) {
                        std::cout << " AI wins the realm.\n";

                        std::ofstream summary("summary.txt");
                        summary << "===== STRONGHOLD GAME SUMMARY =====\n";
                        summary << "RESULT: AI wins.\n";
                        summary.close();
                    }
                    else {
                        std::cout << " It’s a draw. Peace... for now.\n";

                        std::ofstream summary("summary.txt");
                        summary << "===== STRONGHOLD GAME SUMMARY =====\n";
                        summary << "RESULT: Draw.\n";
                        summary.close();
                    }

                    return 0;
                }
                break;

            case 9: {
                int amount;
                std::cout << "Enter loan amount to give: ";
                std::cin >> amount;
                bank.giveLoan(amount);
                break;
            }
            case 10:
                bank.audit();
                break;
            case 11:
                std::cout << "\n[AI Turn Started]\n";
                aiPop.updateGrowth();
                aiEco.collectTax(aiPop.totalPopulation);
                aiArmy.pay();
                aiEvent.trigger(aiPop, aiArmy, aiLeader);
                std::cout << "[AI Turn Complete]\n";
                logTurn(aiPop, aiEco, aiArmy, "AI");
                break;
            case 12: {
                std::ifstream log("log_turns.txt");
                if (!log) {
                    std::cout << "[Error] log_turns.txt not found.\n";
                    break;
                }
                std::string line;
                std::cout << "\n[Turn History]\n";
                while (std::getline(log, line)) {
                    std::cout << line << "\n";
                }
                log.close();
                break;
            }
            case 13:
                population = Population();
                economy = Economy();
                army = Army();
                food = Resource("Food", 100);

                aiPop = Population();
                aiEco = Economy();
                aiArmy = Army();
                aiEvent = Event("Shadow Uprising");

                turnCounter = 0;

                {
                    std::ofstream log("log_turns.txt");
                    log << "[Game Reset]\n";
                    log.close();
                }

                std::cout << "\n[Game state reset successfully. Both kingdoms restored.]\n";
                break;
            case 14: {
                char filename[50];
                std::cout << "Enter filename to save (e.g., slot1.txt): ";
                std::cin >> filename;
                fileManager.saveFullGame(population, economy, army, turnCounter, filename);
                std::cout << "[Game saved to " << filename << "]\n";
                break;
            }

               
            case 15: {
                char filename[50];
                std::cout << "Enter filename to load (e.g., slot1.txt): ";
                std::cin >> filename;
                fileManager.loadFullGame(population, economy, army, turnCounter, filename);
                std::cout << "[Game loaded from " << filename << "]\n";
                break;
            }

            case 16:
                std::cout << "[Leader Personality] ";
                switch (leader.getPersonality()) {
                case GREEDY: std::cout << "Greedy\n"; break;
                case WISE: std::cout << "Wise\n"; break;
                case WARLORD: std::cout << "Warlord\n"; break;
                }
                break;

            case 0:
                std::cout << "Exiting game. Goodbye!\n";
                return 0;
            default:
                throw InvalidOperationException("Invalid menu option.");
            }
        }
        catch (const GameException& ex) {
            std::cout << "[Error] " << ex.what() << "\n";
        }
    }

    return 0;
}
