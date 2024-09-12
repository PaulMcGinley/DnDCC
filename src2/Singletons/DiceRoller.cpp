//
// Created by Paul McGinley on 12/09/2024.
//

#include "DiceRoller.h"
#include <random>

std::mutex DiceRoller::mtx;                                                                                             // Initialize the mutex

// Constructor
DiceRoller& DiceRoller::getInstance() {
    static DiceRoller instance;                                                                                         // Guaranteed to be destroyed. Instantiated on first use.
    return instance;                                                                                                    // Return the instance
}

// Roll a number of dice with a given number of sides
std::vector<int> DiceRoller::Roll(int count, int sides) {
    std::scoped_lock lock(mtx);                                                                                      // Lock the mutex

    std::vector<int> output;                                                                                            // Vector to store the results
    std::random_device rd;                                                                                              // obtain a random number from hardware
    std::mt19937 gen(rd());                                                                                          // seed the generator
    std::uniform_int_distribution<> dis(1, sides);                                                                  // define the range

    output.reserve(count);                                                                                              // reserve the memory for the output
    for (int i = 0; i < count; i++)                                                                                     // Iterate through the number of dice to roll
        output.push_back(dis(gen));                                                                                // Roll the dice and add the result to the output

    return output;                                                                                                      // return the results
}
