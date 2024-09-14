//
// Created by Paul McGinley on 14/09/2024.
//

#ifndef PLAYER_ROW_H
#define PLAYER_ROW_H
#include <string>

#include "../abilities.h"
#include "../energy.h"
#include "../../Modules/Player/player.h"


[[deprecated("Use Modules/Player/player.h instead.")]]
struct PlayerEntry {
    std::string name;
    int character_class;
    int level;
    int experience;
    int gold;
    Energy health;
    Energy mana;
    Abilities abilities;

    [[nodiscard]] Player ToPlayer() const {
        Player p = Player();
        p.name = name;
        p.character_class = static_cast<CharacterClass>(character_class);
        p.level = level;
        p.experience = experience;
        p.health = health;
        p.mana = mana;
        p.strength = abilities.strength;
        p.dexterity = abilities.dexterity;
        p.constitution = abilities.constitution;
        p.intelligence = abilities.intelligence;
        p.wisdom = abilities.wisdom;
        p.charisma = abilities.charisma;
        return p;
    }
};

#endif //PLAYER_ROW_H
