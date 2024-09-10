//
// Created by Paul McGinley on 09/09/2024.
//

#include "Character.hpp"

#include <random>
#include <__random/random_device.h>

Character::Character() {
    this->name = "New Player";
    this->level = 1;
    this->experience = 0;
    this->health = 10;
    this->maxHealth = 10;
    this->GenerateAbilities();
}

std::vector<int> Character::Roll(int count, int sides) {

    std::vector<int> output;

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> dis(1, sides); // define the range

    for (int i = 0; i < count; i++)
        output.push_back(dis(gen));

    return output;
}

void Character::GenerateAbilities() {
    this->Strength = this->Roll(3, 6)[0];
    this->Dexterity = this->Roll(3, 6)[0];
    this->Constitution = this->Roll(3, 6)[0];
    this->Intelligence = this->Roll(3, 6)[0];
    this->Wisdom = this->Roll(3, 6)[0];
    this->Charisma = this->Roll(3, 6)[0];
}

