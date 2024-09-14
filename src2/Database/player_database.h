//
// Created by Paul McGinley on 14/09/2024.
//

#ifndef PLAYER_DATABASE_H
#define PLAYER_DATABASE_H

#include "../Modules/Player/player.h"
#include "../Modules/CSV_Parser/csv_parser.h"
#include <vector>
#include <mutex>

namespace PlayerDatabase {

    extern std::vector<Player> players; // extern keyword allows declaration without definition (allows multiple files to use the same variable)
    extern std::mutex mtx;
    inline const extern std::string dbPath = "players.csv";
    extern CSVParser csvParser;

    void AddPlayer(const Player& player);
    void RemovePlayer(const std::string& name);
    void EditPlayer(const std::string& name, const Player& player);
    void SaveDB();
    void LoadDB();
    Player* GetPlayer(const std::string& name);
    std::vector<Player> GetAllPlayers();
}



#endif //PLAYER_DATABASE_H
