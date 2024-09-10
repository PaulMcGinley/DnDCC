//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef IABILITIES_HPP
#define IABILITIES_HPP

class IAbilities {
public:
    virtual ~IAbilities() = default;

                        // Base, Bonus, and Modifier
    int strength[]      = {0, 0, 0};
    int dexterity[]     = {0, 0, 0};
    int constitution[]  = {0, 0, 0};
    int intelligence[]  = {0, 0, 0};
    int wisdom[]        = {0, 0, 0};
    int charisma[]      = {0, 0, 0};

    int Strength() { return this->strength[0] + this->strength[1] + this->strength[2]; }
    int Dexterity() { return this->dexterity[0] + this->dexterity[1] + this->dexterity[2]; }
    int Constitution() { return this->constitution[0] + this->constitution[1] + this->constitution[2]; }
    int Intelligence() { return this->intelligence[0] + this->intelligence[1] + this->intelligence[2]; }
    int Wisdom() { return this->wisdom[0] + this->wisdom[1] + this->wisdom[2]; }
    int Charisma() { return this->charisma[0] + this->charisma[1] + this->charisma[2]; }
};

#endif // IABILITIES_HPP