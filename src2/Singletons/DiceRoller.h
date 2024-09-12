//
// Created by Paul McGinley on 12/09/2024.
//

#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <vector>
#include <mutex>

class DiceRoller {
public:
    static DiceRoller& getInstance();                                                                                   // Get instance of DiceRoller
    std::vector<int> Roll(int count, int sides);                                                                        // Roll a number of dice with a given number of sides

private:
    DiceRoller() = default;                                                                                             // Constructor
    ~DiceRoller() = default;                                                                                            // Destructor

    DiceRoller(const DiceRoller&) = delete;                                                                             // Delete copy constructor
    DiceRoller& operator=(const DiceRoller&) = delete;                                                                  // Delete copy assignment operator

    static std::mutex mtx;                                                                                              // Mutex for thread safety
};

#endif // DICEROLLER_H