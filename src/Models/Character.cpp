//
// Created by Paul McGinley on 09/09/2024.
//

#include "Character.hpp"

#include <iostream>
#include <random>
#include <__random/random_device.h>

// Constructor
Character::Character() {
    this->GenerateBaseAbilities();
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
void Character::GenerateBaseAbilities() {

    this->strength[0] = this->RollForAbility();
    this->strength[1] = this->CalculateBonus(this->strength[0]);

    this->dexterity[0] = this->RollForAbility();
    this->dexterity[1] = this->CalculateBonus(this->dexterity[0]);

    this->constitution[0] = this->RollForAbility();
    this->constitution[1] = this->CalculateBonus(this->constitution[0]);

    this->intelligence[0] = this->RollForAbility();
    this->intelligence[1] = this->CalculateBonus(this->intelligence[0]);

    this->wisdom[0] = this->RollForAbility();
    this->wisdom[1] = this->CalculateBonus(this->wisdom[0]);

    this->charisma[0] = this->RollForAbility();
    this->charisma[1] = this->CalculateBonus(this->charisma[0]);

    CharacterClass possible_classes = DetermineClass();

    SelectClass(possible_classes);
    AssignClassAbilities();
}

// Roll 4d6 and drop the lowest value
int Character::RollForAbility() {
    std::vector<int> results;                   // store the results of the roll
    int sum = 0;                                // store the sum of the results

    results = this->Roll(4, 6);       // roll 4d6

    int lowest = 0;
    for (int i = 0; i < results.size(); i++) {  // iterate through the results
        sum += results.at(i);                   // add the current value to the sum

        if (results[i] < lowest)
            lowest = results[i];                // set the lowest to the current value
    }

    return sum - lowest;                        // return the sum of all numbers minus the lowest value
}

// Calculate the bonus for an ability score
int Character::CalculateBonus(int value) {
    return std::floor ((value - 10) / 2);
}

// Determine the class of the character
CharacterClass Character::DetermineClass() {
    CharacterClass output = UNDEFINED;

    if (this->Strength()        > 13)   output = static_cast<CharacterClass>(output | Fighter);
    if (this->Dexterity()       > 13)   output = static_cast<CharacterClass>(output | Rogue);
    if (this->Intelligence()    > 13)   output = static_cast<CharacterClass>(output | Wizard);
    if (this->Charisma()        > 13)   output = static_cast<CharacterClass>(output | Bard);

    return output;
}

// Select the class of the character
void Character::SelectClass(CharacterClass characterClass) {

    CharacterClass selectedClass = UNDEFINED;                                                                           // Initialize the selected class to UNDEFINED so we can check if it has been set

    // Array of all possible CharacterClass values
    // TODO: Find a a better way to do this
    CharacterClass all_classes[] = {
        Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, Wizard
    };

    std::vector<CharacterClass> available_classes;                                                                      // Initialize a vector to store the available classes

    // Loop through all possible classes and check if they are set in characterClass
    for (CharacterClass cls : all_classes)                                                                              // Loop through all classes in the array
        if (characterClass & cls)                                                                                       // Bitwise AND to check if the class is set
            available_classes.push_back(cls);                                                                           // Add the class to the available classes

    std::cout << "Current Class " << CharacterClassToString(this->characterClass) << std::endl;
    while (selectedClass == UNDEFINED) {
        // Print the possible classes
        std::cout << "Select a class:" << std::endl;
        for (size_t i = 0; i < available_classes.size(); ++i) {
            std::cout << i + 1 << "\t" << CharacterClassToString( available_classes[i]) << std::endl;
        }

        std::cout << "99 " << "\t" << "Re-roll Abilities" << std::endl;

        // Get user input and select the class
        int choice;
        std::cin >> choice;
        if (choice == 99) {
            this->GenerateBaseAbilities();
            return;
        }

        if (choice > 0 && choice <= available_classes.size()) {
            selectedClass = available_classes[choice - 1];
        } else {
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    this->characterClass = selectedClass;
}

void Character::AssignClassAbilities() {
    switch (this->characterClass) {

        case Wizard: {
            this->health[2] = 6 + this->Constitution();
            break;
        }

        case Bard: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case Rogue: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case Fighter: {
            this->health[2] = 10 + this->Constitution();
            break;
        }

        case Barbarian: {
            this->health[2] = 12 + this->Constitution();
            break;
        }

        case Cleric: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case Druid: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case Monk: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case Paladin: {
            this->health[2] = 10 + this->Constitution();
            break;
        }

        case Ranger: {
            this->health[2] = 10 + this->Constitution();
            break;
        }

        case Sorcerer: {
            this->health[2] = 6 + this->Constitution();
            break;
        }

        case Warlock: {
            this->health[2] = 8 + this->Constitution();
            break;
        }

        case UNDEFINED: {
            std::cout << "No class selected" << std::endl;
            break;
        }
    }
}


// Convert the CharacterClass enum to a string
// TODO: Move this to a utility class
std::string Character::CharacterClassToString(CharacterClass characterClass) {
    switch (characterClass) {
        case UNDEFINED: return "UNDEFINED";
        case Barbarian: return "Barbarian";
        case Bard: return "Bard";
        case Cleric: return "Cleric";
        case Druid: return "Druid";
        case Fighter: return "Fighter";
        case Monk: return "Monk";
        case Paladin: return "Paladin";
        case Ranger: return "Ranger";
        case Rogue: return "Rogue";
        case Sorcerer: return "Sorcerer";
        case Warlock: return "Warlock";
        case Wizard: return "Wizard";
        default: return "Unknown";
    }
}