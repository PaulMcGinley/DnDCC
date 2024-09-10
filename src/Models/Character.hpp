//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

#include "../Interfaces/IAbilities.hpp"
#include "../Interfaces/ILevel.hpp"

class Character : public IAbilities, public ILevel {
public:
    Character();
    std::string name = "New Player";

    std::vector<int> Roll(int count = 1, int sides = 6);
    void GenerateBaseAbilities();

private:
    int RollForAbility();
    int CalculateBonus(int);
};

#endif //CHARACTER_HPP
