//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "../../Structures/abilities.h"
#include "../../Enumerators/chacter_class.h"
#include "../../Structures/energy.h"
#include "../../Modules/Dice/dice_roller.h"

class Player : public Abilities {
public:
    Player(bool new_player = false);
    std::string name;
    int level = 1;
    int experience = 0;
    int gold = 0;

    CharacterClass character_class = UNDEFINED;
    Energy health;
    Energy mana;
    std::vector<int> Roll(int count = 1, int sides = 6) {
        return DiceRoller::getInstance().Roll(count, sides);
    }

private:
    CharacterClass CheckClassAvailability();

    void OnCharacterCreation();

    void GenerateAbilities();
    int RollForAbility();

    static int CalculateBonus(int value) {
        return std::floor ((value - 10) / 2);
    }
    void SelectClass(CharacterClass list);
    void AssignClassAbilities();
};

#endif //PLAYER_HPP
