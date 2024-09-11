//
// Created by Paul McGinley on 09/09/2024.
//

#ifndef IABILITIES_HPP
#define IABILITIES_HPP

class IAbilities {
public:
    virtual ~IAbilities() = default;

                                     // Base, Bonus, and Modifier
    std::array<int, 3> health        = {0, 0, 0};
    std::array<int, 3> maxHealth     = {0, 0, 0};

                                     // Base, Bonus, and Modifier
    std::array<int, 3> strength      = {0, 0, 0};
    std::array<int, 3> dexterity     = {0, 0, 0};
    std::array<int, 3> constitution  = {0, 0, 0};
    std::array<int, 3> intelligence  = {0, 0, 0};
    std::array<int, 3> wisdom        = {0, 0, 0};
    std::array<int, 3> charisma      = {0, 0, 0};

    [[nodiscard]] int Health() const { return this->health[0] + this->health[1] + this->health[2]; }
    [[nodiscard]] int MaxHealth() const { return this->maxHealth[0] + this->maxHealth[1] + this->maxHealth[2]; }

    [[nodiscard]] int Strength() const { return this->strength[0] + this->strength[1] + this->strength[2]; }
    [[nodiscard]] int Dexterity() const { return this->dexterity[0] + this->dexterity[1] + this->dexterity[2]; }
    [[nodiscard]] int Constitution() const { return this->constitution[0] + this->constitution[1] + this->constitution[2]; }
    [[nodiscard]] int Intelligence() const { return this->intelligence[0] + this->intelligence[1] + this->intelligence[2]; }
    [[nodiscard]] int Wisdom() const { return this->wisdom[0] + this->wisdom[1] + this->wisdom[2]; }
    [[nodiscard]] int Charisma() const { return this->charisma[0] + this->charisma[1] + this->charisma[2]; }

    void SetStrength(int base, int bonus, int modifier) { this->strength[0] = base; this->strength[1] = bonus; this->strength[2] = modifier; }
    void SetDexterity(int base, int bonus, int modifier) { this->dexterity[0] = base; this->dexterity[1] = bonus; this->dexterity[2] = modifier; }
    void SetConstitution(int base, int bonus, int modifier) { this->constitution[0] = base; this->constitution[1] = bonus; this->constitution[2] = modifier; }
    void SetIntelligence(int base, int bonus, int modifier) { this->intelligence[0] = base; this->intelligence[1] = bonus; this->intelligence[2] = modifier; }
    void SetWisdom(int base, int bonus, int modifier) { this->wisdom[0] = base; this->wisdom[1] = bonus; this->wisdom[2] = modifier; }
    void SetCharisma(int base, int bonus, int modifier) { this->charisma[0] = base; this->charisma[1] = bonus; this->charisma[2] = modifier; }

    void AddStrength(int base, int bonus, int modifier) { this->strength[0] += base; this->strength[1] += bonus; this->strength[2] += modifier; }
    void AddDexterity(int base, int bonus, int modifier) { this->dexterity[0] += base; this->dexterity[1] += bonus; this->dexterity[2] += modifier; }
    void AddConstitution(int base, int bonus, int modifier) { this->constitution[0] += base; this->constitution[1] += bonus; this->constitution[2] += modifier; }
    void AddIntelligence(int base, int bonus, int modifier) { this->intelligence[0] += base; this->intelligence[1] += bonus; this->intelligence[2] += modifier; }
    void AddWisdom(int base, int bonus, int modifier) { this->wisdom[0] += base; this->wisdom[1] += bonus; this->wisdom[2] += modifier; }
    void AddCharisma(int base, int bonus, int modifier) { this->charisma[0] += base; this->charisma[1] += bonus; this->charisma[2] += modifier; }
};

#endif // IABILITIES_HPP