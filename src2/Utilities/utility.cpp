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
    void PrintTitle() {

        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"( ______            _        _______  _______  _______  _        _______          __        ______   _______  _______  _______  _______  _        _______ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((  __  \ |\     /|( (    /|(  ____ \(  ____ \(  ___  )( (    /|(  ____ \        /__\      (  __  \ (  ____ )(  ___  )(  ____ \(  ___  )( (    /|(  ____ \)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (  \  )| )   ( ||  \  ( || (    \/| (    \/| (   ) ||  \  ( || (    \/       ( \/ )     | (  \  )| (    )|| (   ) || (    \/| (   ) ||  \  ( || (    \/)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   ) || |   | ||   \ | || |      | (__    | |   | ||   \ | || (_____         \  /      | |   ) || (____)|| (___) || |      | |   | ||   \ | || (_____ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   | || |   | || (\ \) || | ____ |  __)   | |   | || (\ \) |(_____  )        / \ \     | |   | ||     __)|  ___  || | ____ | |   | || (\ \) || (_____))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |   ) || |   | || | \   || | \_  )| (      | |   | || | \   |      ) |       / /  /     | |   ) || (\ (   | (   ) || | \_  )| |   | || | \   |      ) |)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (__/  )| (___) || )  \  || (___) || (____/\| (___) || )  \  |/\____) |      ( \/  \     | (__/  )| ) \ \__| )   ( || (___) || (___) || )  \  |/\____) |)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)\_______)      \___/\/     (______/ |/   \__/|/     \|(_______)(_______)|/    )_)\_______))" << ConsoleFormat::RESET << std::endl;

        std::cout <<  ConsoleFormat::BG_BLACK << ConsoleFormat::RED                       << R"(-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-)" << ConsoleFormat::RESET << std::endl;

        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"( _______           _______  _______  _______  _______ _________ _______  _______           _______  _______  _        _______  _______  _______  _______ )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((  ____ \|\     /|(  ___  )(  ____ )(  ___  )(  ____ \\__   __/(  ____ \(  ____ )         (       )(  ___  )( (    /|(  ___  )(  ____ \(  ____ \(  ____ ))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (    \/| )   ( || (   ) || (    )|| (   ) || (    \/   ) (   | (    \/| (    )|         | () () || (   ) ||  \  ( || (   ) || (    \/| (    \/| (    )|)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      | (___) || (___) || (____)|| (___) || |         | |   | (__    | (____)|   _____ | || || || (___) ||   \ | || (___) || |      | (__    | (____)|)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      |  ___  ||  ___  ||     __)|  ___  || |         | |   |  __)   |     __)  (_____)| |(_)| ||  ___  || (\ \) ||  ___  || | ____ |  __)   |     __))" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| |      | (   ) || (   ) || (\ (   | (   ) || |         | |   | (      | (\ (            | |   | || (   ) || | \   || (   ) || | \_  )| (      | (\ (   )" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"(| (____/\| )   ( || )   ( || ) \ \__| )   ( || (____/\   | |   | (____/\| ) \ \__         | )   ( || )   ( || )  \  || )   ( || (___) || (____/\| ) \ \__)" << ConsoleFormat::RESET << std::endl;
        std::cout << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << R"((_______/|/     \||/     \||/   \__/|/     \|(_______/   )_(   (_______/|/   \__/         |/     \||/     \||/    )_)|/     \|(_______)(_______/|/   \__/)" << ConsoleFormat::RESET << std::endl;

//         std::cout << R"(
//  ______            _        _______  _______  _______  _        _______          __        ______   _______  _______  _______  _______  _        _______
// (  __  \ |\     /|( (    /|(  ____ \(  ____ \(  ___  )( (    /|(  ____ \        /__\      (  __  \ (  ____ )(  ___  )(  ____ \(  ___  )( (    /|(  ____ \
// | (  \  )| )   ( ||  \  ( || (    \/| (    \/| (   ) ||  \  ( || (    \/       ( \/ )     | (  \  )| (    )|| (   ) || (    \/| (   ) ||  \  ( || (    \/
// | |   ) || |   | ||   \ | || |      | (__    | |   | ||   \ | || (_____         \  /      | |   ) || (____)|| (___) || |      | |   | ||   \ | || (_____
// | |   | || |   | || (\ \) || | ____ |  __)   | |   | || (\ \) |(_____  )        /  \/\    | |   | ||     __)|  ___  || | ____ | |   | || (\ \) |(_____  )
// | |   ) || |   | || | \   || | \_  )| (      | |   | || | \   |      ) |       / /\  /    | |   ) || (\ (   | (   ) || | \_  )| |   | || | \   |      ) |
// | (__/  )| (___) || )  \  || (___) || (____/\| (___) || )  \  |/\____) |      (  \/  \    | (__/  )| ) \ \__| )   ( || (___) || (___) || )  \  |/\____) |
// (______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)\_______)       \___/\/    (______/ |/   \__/|/     \|(_______)(_______)|/    )_)\_______)
// -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//  _______           _______  _______  _______  _______ _________ _______  _______           _______  _______  _        _______  _______  _______  _______
// (  ____ \|\     /|(  ___  )(  ____ )(  ___  )(  ____ \\__   __/(  ____ \(  ____ )         (       )(  ___  )( (    /|(  ___  )(  ____ \(  ____ \(  ____ )
// | (    \/| )   ( || (   ) || (    )|| (   ) || (    \/   ) (   | (    \/| (    )|         | () () || (   ) ||  \  ( || (   ) || (    \/| (    \/| (    )|
// | |      | (___) || (___) || (____)|| (___) || |         | |   | (__    | (____)|   _____ | || || || (___) ||   \ | || (___) || |      | (__    | (____)|
// | |      |  ___  ||  ___  ||     __)|  ___  || |         | |   |  __)   |     __)  (_____)| |(_)| ||  ___  || (\ \) ||  ___  || | ____ |  __)   |     __)
// | |      | (   ) || (   ) || (\ (   | (   ) || |         | |   | (      | (\ (            | |   | || (   ) || | \   || (   ) || | \_  )| (      | (\ (
// | (____/\| )   ( || )   ( || ) \ \__| )   ( || (____/\   | |   | (____/\| ) \ \__         | )   ( || )   ( || )  \  || )   ( || (___) || (____/\| ) \ \__
// (_______/|/     \||/     \||/   \__/|/     \|(_______/   )_(   (_______/|/   \__/         |/     \||/     \||/    )_)|/     \|(_______)(_______/|/   \__/
//         )" << std::endl;
//         std::cout << ConsoleFormat::RESET;
    }

    void PrintCharacterStatSheet(Player *player) {
        auto &strength = player->strength;
        auto &dexterity = player->dexterity;
        auto &constitution = player->constitution;
        auto &intelligence = player->intelligence;
        auto &wisdom = player->wisdom;
        auto &charisma = player->charisma;

        std::cout << "----- " << player->name << " (" << CharacterClassToString(player->character_class) << ") -------------------|" << std::endl;
        std::cout << "Attribute\t\tBase\tBonus\tModifier\tTotal" << std::endl;
        std::cout << ConsoleFormat::BOLD << "Strength\t\t" << ConsoleFormat::RESET << strength.base << "\t\t" << strength.bonus << "\t\t" << strength.modifier << "\t\t\t" << player->strength.value() << std::endl;
        std::cout << "Dexterity\t\t" << dexterity.base << "\t\t" << dexterity.bonus << "\t\t" << dexterity.modifier << "\t\t\t" << dexterity.value() << std::endl;
        std::cout << "Constitution\t" << constitution.base << "\t\t" << constitution.bonus << "\t\t" << constitution.modifier << "\t\t\t" << constitution.value() << std::endl;
        std::cout << "Intelligence\t" << intelligence.base << "\t\t" << intelligence.bonus << "\t\t" << intelligence.modifier << "\t\t\t" << intelligence.value() << std::endl;
        std::cout << "Wisdom\t\t\t" << wisdom.base << "\t\t" << wisdom.bonus << "\t\t" << wisdom.modifier << "\t\t\t" << wisdom.value() << std::endl;
        std::cout << "Charisma\t\t" << charisma.base << "\t\t" << charisma.bonus << "\t\t" << charisma.modifier << "\t\t\t" << charisma.value() << std::endl;
    }

    void PrintSpacer() {
        std::cout << ConsoleFormat::RESET << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
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
