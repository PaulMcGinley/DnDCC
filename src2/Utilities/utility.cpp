//
// Created by Paul McGinley on 12/09/2024.
//

#include "utility.h"
#include <iostream>
#include <algorithm>

#include "console_formatter.h"
#include "../Modules/Player/player.h"
#include "../Enumerators/chacter_class.h"

namespace Utility {

    // Print the title of the game
    void PrintTitle() {

        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"( ______            _        _______  _______  _______  _        _______          __        ______   _______  _______  _______  _______  _        _______ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((  __  \ |\     /|( (    /|(  ____ \(  ____ \(  ___  )( (    /|(  ____ \        /__\      (  __  \ (  ____ )(  ___  )(  ____ \(  ___  )( (    /|(  ____ \)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (  \  )| )   ( ||  \  ( || (    \/| (    \/| (   ) ||  \  ( || (    \/       ( \/ )     | (  \  )| (    )|| (   ) || (    \/| (   ) ||  \  ( || (    \/)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   ) || |   | ||   \ | || |      | (__    | |   | ||   \ | || (_____         \  /      | |   ) || (____)|| (___) || |      | |   | ||   \ | || (_____ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   | || |   | || (\ \) || | ____ |  __)   | |   | || (\ \) |(_____  )        / \ \     | |   | ||     __)|  ___  || | ____ | |   | || (\ \) || (_____))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   ) || |   | || | \   || | \_  )| (      | |   | || | \   |      ) |       / /  /     | |   ) || (\ (   | (   ) || | \_  )| |   | || | \   |      ) |)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (__/  )| (___) || )  \  || (___) || (____/\| (___) || )  \  |/\____) |      ( \/  \     | (__/  )| ) \ \__| )   ( || (___) || (___) || )  \  |/\____) |)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)\_______)      \___/\/     (______/ |/   \__/|/     \|(_______)(_______)|/    )_)\_______))" << ConsoleFormat::RESET << std::endl;

        std::cout << ConsoleFormat::BG_BLACK << ConsoleFormat::RED                        << R"(-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-)" << ConsoleFormat::RESET << std::endl;

        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"( _______           _______  _______  _______  _______ _________ _______  _______           _______  _______  _        _______  _______  _______  _______ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((  ____ \|\     /|(  ___  )(  ____ )(  ___  )(  ____ \\__   __/(  ____ \(  ____ )         (       )(  ___  )( (    /|(  ___  )(  ____ \(  ____ \(  ____ ))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (    \/| )   ( || (   ) || (    )|| (   ) || (    \/   ) (   | (    \/| (    )|         | () () || (   ) ||  \  ( || (   ) || (    \/| (    \/| (    )|)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      | (___) || (___) || (____)|| (___) || |         | |   | (__    | (____)|   _____ | || || || (___) ||   \ | || (___) || |      | (__    | (____)|)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      |  ___  ||  ___  ||     __)|  ___  || |         | |   |  __)   |     __)  (_____)| |(_)| ||  ___  || (\ \) ||  ___  || | ____ |  __)   |     __))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      | (   ) || (   ) || (\ (   | (   ) || |         | |   | (      | (\ (            | |   | || (   ) || | \   || (   ) || | \_  )| (      | (\ (   )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (____/\| )   ( || )   ( || ) \ \__| )   ( || (____/\   | |   | (____/\| ) \ \__         | )   ( || )   ( || )  \  || )   ( || (___) || (____/\| ) \ \__)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((_______/|/     \||/     \||/   \__/|/     \|(_______/   )_(   (_______/|/   \__/         |/     \||/     \||/    )_)|/     \|(_______)(_______/|/   \__/)" << ConsoleFormat::RESET << std::endl;
    }

    // Print the character's stat sheet in a table format
    void PrintCharacterStatSheet(Player *player) {

        // Set the width of each column
        const int attributeWidth = 15;
        const int baseWidth = 10;
        const int bonusWidth = 10;
        const int modifierWidth = 10;
        const int totalWidth = 10;

        // Print the header of the table
        std::cout << ConsoleFormat::BOLD
                  << std::left << std::setw(attributeWidth) << "Attribute"
                  << std::setw(baseWidth) << "Base"
                  << std::setw(bonusWidth) << "Bonus"
                  << std::setw(modifierWidth) << "Modifier"
                  << std::setw(totalWidth) << "Total"
                  << ConsoleFormat::RESET << std::endl;

        // Lambda function to print a row of the stat sheet (will only be used here so makes sense to create it here)
        // [&] captures all variables by reference, so we can use the variables from the outer scope
        auto printRow = [&](const std::string& attribute, int base, int bonus, int modifier, int total) {
            std::cout << std::left << std::setw(attributeWidth) << attribute
                      << std::setw(baseWidth) << base
                      << std::setw(bonusWidth) << bonus
                      << std::setw(modifierWidth) << modifier
                      << std::setw(totalWidth) << total
                      << std::endl;
        };

        // Print each row of the table
        printRow("Strength", player->strength.base, player->strength.bonus, player->strength.modifier, player->strength.value());
        printRow("Dexterity", player->dexterity.base, player->dexterity.bonus, player->dexterity.modifier, player->dexterity.value());
        printRow("Constitution", player->constitution.base, player->constitution.bonus, player->constitution.modifier, player->constitution.value());
        printRow("Intelligence", player->intelligence.base, player->intelligence.bonus, player->intelligence.modifier, player->intelligence.value());
        printRow("Wisdom", player->wisdom.base, player->wisdom.bonus, player->wisdom.modifier, player->wisdom.value());
        printRow("Charisma", player->charisma.base, player->charisma.bonus, player->charisma.modifier, player->charisma.value());
    }

    void PrintHeader(std::string caption) {
        const int length = 153; // Width of game is 153 characters because of the ASCII art
        std::string glyphs(length, '_'); // Create a string filled with underscores

        glyphs[5] = ']';
        glyphs[6] = ' ';

        int maxLength = 100; // Limit the input to 100 characters
        int captionLength = std::min(static_cast<int>(caption.length()), maxLength); // Clamp the length if it exceeds the max
        glyphs.replace(7, captionLength, caption.substr(0, captionLength)); // Replace part of the string with the caption

        glyphs[captionLength + 7] = ' ';
        glyphs[captionLength + 8] = '[';

        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_BLACK << ConsoleFormat::WHITE << glyphs << ConsoleFormat::RESET << std::endl;
    }

    // TODO: Refactor this into the updated PrintHeader function, add optional params for the color and glyph
    void PrintSubHeader(std::string caption) {
        // Note, I wrote this with the intention of using hyphens, but I used underscores instead... Not renaming the variable now xD
        const int length = 153; // Width of game is 153 characters because of the ASCII art
        char hyphens[length + 1]; // +1 for the null terminator (\0)
        std::memset(hyphens, '-', length); // Fill the array with hyphens
        hyphens[length] = '\0'; // Add a null terminator to the end of the array (C-style string)

        hyphens[5] = ' ';
        hyphens[6] = ' ';

        int maxLength = 100; // Limit the input to 100 characters
        int captionLength = std::min(static_cast<int>(caption.length()), maxLength); // Clap the length if it exceeds the max
        for (int i = 0; i < captionLength; i++)
            hyphens[i + 7] = caption[i];

        hyphens[captionLength + 7] = ' ';
        hyphens[captionLength + 8] = ' ';

        std::cout << ConsoleFormat::CYAN << hyphens << ConsoleFormat::RESET << std::endl;
    }

    void PrintPlayerListRow(int idx, Player *player) {
        const int totalLength = 153;
        const int idxWidth = 5;
        const int nameWidth = 30;
        const int classWidth = 20;
        const int levelWidth = 10;
        const int experienceWidth = 10;
        const int remainingWidth = totalLength - (idxWidth + nameWidth + classWidth + levelWidth + experienceWidth);

        std::string truncatedName = player->name.substr(0, nameWidth);
        std::string truncatedClass = Utility::CharacterClassToString(player->character_class).substr(0, classWidth);

        std::cout << std::left << std::setw(idxWidth) << idx
                  << std::setw(nameWidth) << truncatedName
                  << std::setw(classWidth) << truncatedClass
                  << std::setw(levelWidth) << player->level
                  << std::setw(experienceWidth) << player->experience
                  << std::setw(remainingWidth) << " " // Fill the remaining space with spaces
                  << std::endl;

    }



    bool IsNameUnique(const std::string& name, const std::vector<std::string>& names) {
        return std::find(names.begin(), names.end(), name) == names.end();
    }

    std::string CharacterClassToString(CharacterClass characterClass) {
        switch (characterClass) {
            case UNDEFINED: return "UNDEFINED";
            case Barbarian: return "Barbarian";
            case Bard: return "Bard";
            case Cleric: return "Cleric";
            case Druid: return "Druid";
            case Fighter: return "Fighter";
            case Monk: return "Monk";
            case Paladin: return "Paladin";
            case Ranger: return "Ranger";
            case Rogue: return "Rogue";
            case Sorcerer: return "Sorcerer";
            case Warlock: return "Warlock";
            case Wizard: return "Wizard";
            default: return "Unknown";
        }
    }


}
