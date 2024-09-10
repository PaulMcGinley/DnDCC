//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef IABILITIES_HPP
#define IABILITIES_HPP

class IAbilities {
public:
    virtual ~IAbilities() = default;

    int Strength = 0;
    int Dexterity = 0;
    int Constitution = 0;
    int Intelligence = 0;
    int Wisdom = 0;
    int Charisma = 0;
};

#endif // IABILITIES_HPP