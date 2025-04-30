
# Stronghold Kingdom Simulation Project

## 💻 Project Overview
This project simulates the management of a medieval stronghold kingdom using **Object-Oriented Programming (OOP)** concepts.  
Players can manage **population**, **economy**, **army**, and react to **random events** while competing against an **AI-controlled kingdom**.

---

## 🏗️ Project Structure

| File | Purpose |
|:-----|:--------|
| `main.cpp` | Main driver file (menu, game loop) |
| `Army.cpp`, `Army.h` | Manage army stats and morale |
| `Bank.cpp`, `Bank.h` | Loan and audit system |
| `Economy.cpp`, `Economy.h` | Manage taxation and treasury |
| `Leader.cpp`, `Leader.h` | Leader traits and crisis handling |
| `PopulationSystem.cpp`, `PopulationSystem.h` | Population and growth management |
| `Resource.cpp`, `Resource.h` | Food and supplies management |
| `SocialStructure.cpp`, `SocialStructure.h` | Peasant, Merchant, Noble classes |
| `Event.cpp`, `Event.h` | Random event handling |
| `FileManager.cpp`, `FileManager.h` | Save/Load system and logging |
| `TurnLogger.cpp` | Turn-based log system |

---

## 🧠 Key OOP Concepts Implemented

- **Classes and Objects**  
- **Inheritance and Polymorphism**  
- **Encapsulation and Abstraction**  
- **Dynamic Memory Management (`new`, `delete`)**
- **Exception Handling with Custom Exceptions**
- **Manual File Handling (Save, Load, Logs)**

---

## 📚 Special Features

- 🎭 **Leader Personality Traits**  
  - `GREEDY`, `WISE`, `WARLORD` dynamically affect the gameplay.

- 🔄 **Trait Evolution**  
  - Leader’s personality changes based on player decisions and events.

- 🤖 **AI Opponent**  
  - AI manages its own economy, army, and population independently.

- 💾 **Full Save & Load System**  
  - Supports multiple save slots (save to custom filenames).

- 📜 **Turn History Logging**  
  - Tracks all turns and logs them into `log_turns.txt`.

- 📝 **End-Game Summary**  
  - After 10 rounds, generates a detailed `summary.txt` with results.

- 🚫 **No STL Containers Used**  
  - No usage of `std::vector`, `std::list` as per lab instructions.

---

## 🔥 Additional Notes

- The project is structured modularly for easy future upgrades (GUI, multiplayer, etc.)
- Proper exception handling ensures safe gameplay (e.g., invalid inputs).
- Designed with scalability in mind (easy to add new social classes, events, resources).

---

## 🛠️ How to Compile

1. Open `labproject.vcxproj` in Visual Studio.
2. Set Configuration: **Debug | x64**.
3. Make sure `SFML` setup is correct (optional if adding GUI later).
4. Build Solution (`Ctrl + Shift + B`).
5. Run and enjoy!

---

# 🚀 Stronghold Awaits Your Command!

---

---
