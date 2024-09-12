//
// Created by Paul McGinley on 12/09/2024.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

#include "../Modules/Player/player.h"

namespace Utility {
    // cli out
    void PrintTitle();
    void PrintCharacterStatSheet(Player *player);
    void PrintHeader(std::string caption);
    void PrintSubHeader(std::string caption);
    void PrintPlayerListRow(int idx, Player *player);

    // funcs
    bool IsNameUnique(const std::string& name, const std::vector<std::string>& names);
    std::string CharacterClassToString(CharacterClass characterClass);
}

#endif // UTILITY_H