//
// Created by Paul McGinley on 14/09/2024.
//


#include <sstream>
#include "player_database.h"

#include <iostream>
#include <filesystem>
#include <fstream>

#include "../Utilities/utility.h"


namespace PlayerDatabase {
    CSVParser csvParser(dbPath);
    std::vector<Player> players;
    std::mutex mtx;

    // Add a player to the database
    void AddPlayer(const Player& player) {

        std::unique_lock lock(mtx);

        players.emplace_back(player);

        lock.unlock();
        PlayerDatabase::SaveDB();
    }

    void RemovePlayer(const std::string& name) {

        std::unique_lock lock(mtx);

        // Lambda function to remove player with matching name
        std::erase_if(players, [&name](const Player& player) { return player.name == name; });

        lock.unlock();
    }

    void EditPlayer(const std::string& name, const Player& player) {

        std::unique_lock lock(mtx);

        for (Player& p : players)
            if (p.name == name) p = player;

        lock.unlock();
    }

    Player* GetPlayer(const std::string& name) {

        std::unique_lock lock(mtx);

        for (auto& player : players)
            if (player.name == name) return &player;

        lock.unlock();
        return nullptr;
    }

    std::vector<Player> GetAllPlayers() {

        std::unique_lock lock(mtx);
        std::vector<Player> playersCopy = players;
        lock.unlock();

        return playersCopy;
    }

    void LoadDB() {
        std::unique_lock lock(mtx);

        // Check if the db exists
        if (!std::filesystem::exists(dbPath)) {
            return;
        }

        std::vector<std::vector<std::string>> data = csvParser.parse();

        for (const std::vector<std::string>& row : data) {
            Player player;

            player.name = row[0];

            player.health.remaining = std::stoi(row[1]); // Convert string to int
            player.health.base = std::stoi(row[2]);
            player.health.bonus = std::stoi(row[3]);
            player.health.modifier = std::stoi(row[4]);

            player.mana.remaining = std::stoi(row[5]);
            player.mana.base = std::stoi(row[6]);
            player.mana.bonus = std::stoi(row[7]);
            player.mana.modifier = std::stoi(row[8]);

            player.strength.base = std::stoi(row[9]);
            player.strength.bonus = std::stoi(row[10]);
            player.strength.modifier = std::stoi(row[11]);

            player.dexterity.base = std::stoi(row[12]);
            player.dexterity.bonus = std::stoi(row[13]);
            player.dexterity.modifier = std::stoi(row[14]);

            player.constitution.base = std::stoi(row[15]);
            player.constitution.bonus = std::stoi(row[16]);
            player.constitution.modifier = std::stoi(row[17]);

            player.intelligence.base = std::stoi(row[18]);
            player.intelligence.bonus = std::stoi(row[19]);
            player.intelligence.modifier = std::stoi(row[20]);

            player.wisdom.base = std::stoi(row[21]);
            player.wisdom.bonus = std::stoi(row[22]);
            player.wisdom.modifier = std::stoi(row[23]);

            player.charisma.base = std::stoi(row[24]);
            player.charisma.bonus = std::stoi(row[25]);
            player.charisma.modifier = std::stoi(row[26]);

            player.level = std::stoi(row[27]);
            player.experience = std::stoi(row[28]);

            player.gold = std::stoi(row[29]);
            player.character_class = static_cast<CharacterClass>(std::stoi(row[30]));

            players.emplace_back(player);
        }

        lock.unlock();
    }

    void SaveDB() {
        std::unique_lock lock(mtx);

        //std::ofstream file(dbPath, std::ios::app); // open file stream, input/output stream, append mode (appends to the end of the file)
        std::ofstream file(dbPath, std::ios::trunc); // open file stream, input/output stream, trunc mode (clears the file)
        if (!file.is_open()) {
            std::cerr << "Failed to open file for writing: " << dbPath << std::endl;
            return;
        }

        // Write the header
        file << "name,health_remaining,health_base,health_bonus,health_modifier,"
             << "mana_remaining,mana_base,mana_bonus,mana_modifier,"
             << "strength_base,strength_bonus,strength_modifier,"
             << "dexterity_base,dexterity_bonus,dexterity_modifier,"
             << "constitution_base,constitution_bonus,constitution_modifier,"
             << "intelligence_base,intelligence_bonus,intelligence_modifier,"
             << "wisdom_base,wisdom_bonus,wisdom_modifier,"
             << "charisma_base,charisma_bonus,charisma_modifier,"
             << "level,experience,gold,class\n";

        // Write player data
        for (const Player& player : players) {
            file << player.name << ","
                 << player.health.remaining << "," << player.health.base << "," << player.health.bonus << "," << player.health.modifier << ","
                 << player.mana.remaining << "," << player.mana.base << "," << player.mana.bonus << "," << player.mana.modifier << ","
                 << player.strength.base << "," << player.strength.bonus << "," << player.strength.modifier << ","
                 << player.dexterity.base << "," << player.dexterity.bonus << "," << player.dexterity.modifier << ","
                 << player.constitution.base << "," << player.constitution.bonus << "," << player.constitution.modifier << ","
                 << player.intelligence.base << "," << player.intelligence.bonus << "," << player.intelligence.modifier << ","
                 << player.wisdom.base << "," << player.wisdom.bonus << "," << player.wisdom.modifier << ","
                 << player.charisma.base << "," << player.charisma.bonus << "," << player.charisma.modifier << ","
                 << player.level << "," << player.experience << "," << player.gold << "," << player.character_class << "\n";
        }

        file.close();
        lock.unlock();
    }

}