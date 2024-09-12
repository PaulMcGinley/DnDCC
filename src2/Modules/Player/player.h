//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "../../Structures/abilities.h"
#include "../../Enumerators/chacter_class.h"
#include "../../Structures/energy.h"
#include "../../Singletons/DiceRoller.h"

class Player : public Abilities {
public:
    Player(bool new_player = false);
    std::string name;
    CharacterClass character_class = CharacterClass::UNDEFINED;
    Energy health;
    Energy mana;
    std::vector<int> Roll(int count = 1, int sides = 6) {
        return DiceRoller::getInstance().Roll(count, sides);
    }
    void PrintStats();

private:
    CharacterClass CheckClassAvailability();

    void OnCharacterCreation();

    void GenerateAbilities();
    int RollForAbility();

    static int CalculateBonus(int value);
    void SelectClass(CharacterClass list);
    void AssignClassAbilities();

    //std::string CharacterClassToString(CharacterClass characterClass);
};

#endif //PLAYER_HPP
