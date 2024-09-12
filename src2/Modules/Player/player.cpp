//
// Created by Paul McGinley on 11/09/2024.
//

#include "player.h"

#include <iostream>

#include "../../Utilities/utility.h"

Player::Player(bool new_player) {
    this->name = "New Player";
    this->character_class = UNDEFINED;

    if (new_player)
        OnCharacterCreation();
}

void Player::OnCharacterCreation() {
    this->GenerateAbilities();

    CharacterClass available_classes = UNDEFINED;
    available_classes = CheckClassAvailability();

    Utility::PrintSpacer();
    this->SelectClass(available_classes);

    Utility::PrintSpacer();
    this->AssignClassAbilities();
}

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

    Utility::PrintCharacterStatSheet(this);
}


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

    return available_classes;
}

void Player::SelectClass(CharacterClass available_classes) {

    CharacterClass selectedClass = UNDEFINED;                                                                           // Initialize the selected class to UNDEFINED so we can check if it has been set

    // Array of all possible CharacterClass values
    // TODO: Find a a better way to do this
    CharacterClass all_classes[] = {
        Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, Wizard
    };

    std::vector<CharacterClass> class_list;                                                                      // Initialize a vector to store the available classes

    // Loop through all possible classes and check if they are set in characterClass
    for (CharacterClass cls : all_classes)                                                                              // Loop through all classes in the array
        if (available_classes & cls)                                                                                       // Bitwise AND to check if the class is set
            class_list.push_back(cls);                                                                           // Add the class to the available classes

    //std::cout << "Current Class " << Utility::CharacterClassToString(this->character_class) << std::endl;
    while (selectedClass == UNDEFINED) {
        // Print the possible classes
        std::cout << "Select a class:" << std::endl;
        for (size_t i = 0; i < class_list.size(); ++i) {
            std::cout << i + 1 << "\t" << Utility::CharacterClassToString( class_list[i]) << std::endl;
        }

        std::cout << "99 " << "\t" << "Re-roll Abilities" << std::endl;

        // Get user input and select the class
        int choice;
        std::cin >> choice;
        if (choice == 99) {
            this->OnCharacterCreation();
            return;
        }

        if (choice > 0 && choice <= class_list.size()) {
            selectedClass = class_list[choice - 1];
        } else {
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    this->character_class = selectedClass;
    AssignClassAbilities();
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

// Convert the CharacterClass enum to a string
// TODO: Move this to a utility class
// std::string Player::CharacterClassToString(CharacterClass characterClass) {
//     switch (characterClass) {
//         case UNDEFINED: return "UNDEFINED";
//         case Barbarian: return "Barbarian";
//         case Bard: return "Bard";
//         case Cleric: return "Cleric";
//         case Druid: return "Druid";
//         case Fighter: return "Fighter";
//         case Monk: return "Monk";
//         case Paladin: return "Paladin";
//         case Ranger: return "Ranger";
//         case Rogue: return "Rogue";
//         case Sorcerer: return "Sorcerer";
//         case Warlock: return "Warlock";
//         case Wizard: return "Wizard";
//         default: return "Unknown";
//     }
// }

// Roll 4d6 and drop the lowest value
int Player::RollForAbility() {
    std::vector<int> results;                   // store the results of the roll
    int sum = 0;                                // store the sum of the results

    results = this->Roll(4, 6);       // roll 4d6

    int lowest = INT_MAX;                       // store the lowest value
    for (int result : results) {                // iterate through the results
        sum += result;                   // add the current value to the sum

        if (result < lowest)
            lowest = result;                // set the lowest to the current value
    }

    return sum - lowest;                        // return the sum of all numbers minus the lowest value
}

// Calculate the bonus for an ability score
int Player::CalculateBonus(int value) {
    return std::floor ((value - 10) / 2);
}
