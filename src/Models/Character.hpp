//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

#include "../Interfaces/IAbilities.hpp"

class Character : public IAbilities {
public:
    Character();
    std::string name = "New Player";
    int level = 1;
    int experience = 0;
    int health = 10;
    int maxHealth = 10;
    std::vector<int> Roll(int count = 1, int sides = 6);
    void GenerateAbilities();

private:
    int RollForAbility();
    int CalculateBonus();
};

#endif //CHARACTER_HPP
