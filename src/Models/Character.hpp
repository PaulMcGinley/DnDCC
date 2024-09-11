//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

#include "../Interfaces/IAbilities.hpp"
#include "../Interfaces/ILevel.hpp"
#include "../Enums/CharacterClass.h"

class Character : public IAbilities, public ILevel {
public:
    Character();
    std::string name = "New Player";
    CharacterClass characterClass = UNDEFINED;
    std::string Class() { return CharacterClassToString(characterClass); }
    std::vector<int> Roll(int count = 1, int sides = 6);
    void GenerateBaseAbilities();

private:
    int RollForAbility();
    int CalculateBonus(int);
    CharacterClass DetermineClass();
    void SelectClass(CharacterClass);
    std::string CharacterClassToString(CharacterClass characterClass);
    void AssignClassAbilities();
};

#endif //CHARACTER_HPP
