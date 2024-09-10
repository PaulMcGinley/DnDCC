//
// Created by Paul McGinley on 09/09/2024.
//

#include "Character.hpp"

#include <random>
#include <__random/random_device.h>

// Constructor
Character::Character() {
    this->GenerateAbilities();
}

// Roll a number of dice with a given number of sides
std::vector<int> Character::Roll(int count, int sides) {
    std::vector<int> output;

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;                                 // obtain a random number from hardware
    std::mt19937 gen(rd());                             // seed the generator
    std::uniform_int_distribution<> dis(1, sides);     // define the range

    output.reserve(count);                      // reserve the space for the output
    for (int i = 0; i < count; i++)             // Iterate through the number of dice to roll
        output.push_back(dis(gen));        // Roll the dice and add the result to the output

    return output;                              // return the results
}

// Generate the abilities for the character
void Character::GenerateAbilities() {

    this->Strength = this->RollForAbility();
    this->Dexterity = this->RollForAbility();
    this->Constitution = this->RollForAbility();
    this->Intelligence = this->RollForAbility();
    this->Wisdom = this->RollForAbility();
    this->Charisma = this->RollForAbility();
}

// Roll 4d6 and drop the lowest value
int Character::RollForAbility() {

    std:std::vector<int> results;               // store the results of the roll
    int sum = 0;                                // store the sum of the results

    results = this->Roll(4, 6);       // roll 4d6

    int lowest = results[0];                    // find the lowest value (Default to the first value)

    for (int i = 1; i < results.size(); i++)    // iterate through the results
        if (results[i] < lowest) {              // if the current value is lower than the lowest
            lowest = results[i];                // set the lowest to the current value
            sum += results[i];                  // add the current value to the sum
        }

    return sum - lowest;                        // return the sum of all numbers minus the lowest value
}

