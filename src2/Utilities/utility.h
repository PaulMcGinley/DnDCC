//
// Created by Paul McGinley on 12/09/2024.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

#include "../Modules/Player/player.h"
#include "../Enumerators/syllables.h"

namespace Utility {
    // cli out
    void PrintTitle();
    void PrintCharacterStatSheet(Player *player);
    void PrintHeader(std::string caption);
    void PrintSubHeader(std::string caption);
    void PrintPlayerListRow(int idx, Player *player);
    void PrintPlayerListHeader();

    // funcs
    bool IsNameUnique(const std::string& name, const std::vector<std::string>& names);
    std::string CharacterClassToString(CharacterClass characterClass);
    std::string SyllableToString(Syllables syllable);
}

#endif // UTILITY_H