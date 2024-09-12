//
// Created by Paul McGinley on 11/09/2024.
//

#include "player.h"

#include <iostream>

#include "../../Utilities/console_formatter.h"
#include "../../Utilities/utility.h"

// Constructor
Player::Player(bool new_player) {

    this->name = "New Player";                                                                                          // Set the default name
    this->character_class = UNDEFINED;                                                                                  // Set the default class

    // Check if the player is new and run the character creation process
    if (new_player)
        OnCharacterCreation();
}

// Call the character creation process
void Player::OnCharacterCreation() {

    this->GenerateAbilities();                                                                                          // Roll to generate the abilities for the player

    CharacterClass available_classes = UNDEFINED;                                                                       // Initialize the available classes to UNDEFINED (We use this to check what classes are available)
    available_classes = CheckClassAvailability();                                                                       // Evaluate the available classes based on the abilities and set the available classes

    this->SelectClass(available_classes);                                                                               // Call the SelectClass function to prompt the user to select a class, passing the available classes

    // If we get here, the class has been selected
    this->AssignClassAbilities();                                                                                       // Assign the abilities for the selected class
}

// Randomly generate the abilities for the player
void Player::GenerateAbilities() {

    // Create an empty stat object
    Stat empty_stat = Stat();
    empty_stat.base = 0;
    empty_stat.bonus = 0;
    empty_stat.modifier = 0;

    // Initialize all stats to the empty stat
    this->strength = empty_stat;
    this->dexterity = empty_stat;
    this->constitution = empty_stat;
    this->intelligence = empty_stat;
    this->wisdom = empty_stat;
    this->charisma = empty_stat;

    // Roll for each ability and calculate the bonus
    this->strength.base = this->RollForAbility();
    this->strength.bonus = CalculateBonus(this->strength.base);

    this->dexterity.base = this->RollForAbility();
    this->dexterity.bonus = CalculateBonus(this->dexterity.base);

    this->constitution.base = this->RollForAbility();
    this->constitution.bonus = CalculateBonus(this->constitution.base);

    this->intelligence.base = this->RollForAbility();
    this->intelligence.bonus = CalculateBonus(this->intelligence.base);

    this->wisdom.base = this->RollForAbility();
    this->wisdom.bonus = CalculateBonus(this->wisdom.base);

    this->charisma.base = this->RollForAbility();
    this->charisma.bonus = CalculateBonus(this->charisma.base);

    // Print the generated abilities
    std::cout << ConsoleFormat::BOLD;                                                                                   // Set the console to bold for the header
    Utility::PrintSubHeader("Generated Abilities");                                                            // Print the header (it resets the console to normal)
    Utility::PrintCharacterStatSheet(this);                                                                       // Print the character stat sheet table
}

// Determine the available classes based on the attributes
CharacterClass Player::CheckClassAvailability() {
    CharacterClass available_classes = UNDEFINED;

    if (this->strength.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Barbarian);

    if (this->dexterity.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Rogue);

    if (this->intelligence.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Wizard);

    if (this->wisdom.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Cleric);

    // TODO: Find real requirements for the classes

    if (this->charisma.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Bard);

    if (this->strength.base > 12 && this->dexterity.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Fighter);

    if (this->strength.base > 12 && this->wisdom.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Paladin);

    if (this->dexterity.base > 12 && this->wisdom.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Ranger);

    if (this->dexterity.base > 12 && this->charisma.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Rogue);

    if (this->intelligence.base > 12 && this->charisma.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Sorcerer);

    if (this->wisdom.base > 12 && this->charisma.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Warlock);

    if (this->dexterity.base > 12 && this->wisdom.base > 12)
        available_classes = static_cast<CharacterClass>(available_classes | Monk);

    return available_classes;                                                                                           // Return the available classes (stored as a bitfield)
}

void Player::SelectClass(CharacterClass available_classes) {

    Utility::PrintSubHeader("Please select one of the available classes");

    CharacterClass selectedClass = UNDEFINED;                                                                           // Initialize the selected class to UNDEFINED so we can check if it has been set

    // Array of all possible CharacterClass values
    // TODO: Find a a better way to do this
    CharacterClass all_classes[] = {
        Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, Wizard
    };

    std::vector<CharacterClass> class_list;                                                                             // Initialize a vector to store the available classes

    // Loop through all possible classes and check if they are set in characterClass
    for (CharacterClass cls : all_classes)                                                                              // Loop through all classes in the array
        if (available_classes & cls)                                                                                    // Bitwise AND to check if the class is set
            class_list.push_back(cls);                                                                                  // Add the class to the available classes

    while (selectedClass == UNDEFINED) {

        // Print the possible classes
        for (size_t i = 0; i < class_list.size(); ++i)
            std::cout << i + 1 << "\t" << Utility::CharacterClassToString(class_list[i]) << std::endl;

        // Print the option to re-roll abilities
        std::cout << "99 " << "\t" << "Re-roll Abilities" << std::endl;

        // Get user input and select the class
        int choice;
        std::cin >> choice;
        if (choice == 99) {
            Utility::PrintHeader("(>'-')> Re-rolling attributes <('-'<)");
            this->OnCharacterCreation();                                                                                // Re-roll the abilities
            return;                                                                                                     // Exit the function
        }

        if (choice > 0 && choice <= class_list.size()) {                                                                // Check if the choice is valid
            selectedClass = class_list[choice - 1];                                                                     // Set the selected class (-1 to account for 0 index)
        } else {
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    this->character_class = selectedClass;                                                                              // Set the selected class
    AssignClassAbilities();                                                                                             // Assign the abilities for the selected class
}

void Player::AssignClassAbilities() {
    switch (this->character_class) {

        case Wizard: {
            this->health.modifier = 6 + this->constitution.value();
            break;
        }

        case Bard: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case Rogue: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case Fighter: {
            this->health.modifier = 10 + this->constitution.value();
            break;
        }

        case Barbarian: {
            this->health.modifier = 12 + this->constitution.value();
            break;
        }

        case Cleric: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case Druid: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case Monk: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case Paladin: {
            this->health.modifier = 10 + this->constitution.value();
            break;
        }

        case Ranger: {
            this->health.modifier = 10 + this->constitution.value();
            break;
        }

        case Sorcerer: {
            this->health.modifier = 6 + this->constitution.value();
            break;
        }

        case Warlock: {
            this->health.modifier = 8 + this->constitution.value();
            break;
        }

        case UNDEFINED: {
            std::cout << "No class selected" << std::endl;
            break;
        }
    }
}

// Roll 4d6 and drop the lowest value
int Player::RollForAbility() {
    std::vector<int> results;                                                                                           // store the results of the roll
    int sum = 0;                                                                                                        // store the sum of the results

    results = this->Roll(4, 6);                                                                               // roll 4d6

    //std::cout << "Rolled: " << results[0] << ", " << results[1] << ", " << results[2] << ", " << results[3] << std::endl; // DEBUG

    int lowest = INT_MAX;                                                                                               // store the lowest value, default to the highest possible value
    for (int result : results) {                                                                                        // iterate through the results
        sum += result;                                                                                                  // add the current value to the sum

        if (result < lowest)                                                                                            // check if the current value is lower than the lowest
            lowest = result;                                                                                            // set the lowest to the current value
    }

    return sum - lowest;                                                                                                // return the sum of all numbers minus the lowest value
}