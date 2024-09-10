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
    std::string name;
    int level;
    int experience;
    int health;
    int maxHealth;
    std::vector<int> Roll(int count = 1, int sides = 6);
    void GenerateAbilities();
};

#endif //CHARACTER_HPP
