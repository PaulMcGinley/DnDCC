//
// Created by Paul McGinley on 13/09/2024.
//

#include "loot_table.h"

#include <fstream>
#include <random>
#include <sstream>
#include <__random/random_device.h>

// Load a loot table from a file
void LootTable::LoadLootTable(const std::string& filename) {
    lootTables[filename] = ParseLootTable(filename);                                                                    // Assigns the parsed loot table to the lootTables map
}

// Parse a loot table from a file
std::vector<LootItem> LootTable::ParseLootTable(const std::string& filename) {
    std::vector<LootItem> lootItems;                                                                                    // Create a vector of LootItem structs
    std::ifstream file(filename);                                                                                       // Open the file
    std::string line;                                                                                                   // Create a string to hold each line of the file

    while (std::getline(file, line)) {                                                                              // Read each line of the file
        std::istringstream stream(line);                                                                                // Create a string stream from the line
        LootItem item;                                                                                                  // Create a LootItem struct to hold the parsed data
        stream >> item.chance >> item.item_name >> item.count;                                                          // Parse the line into the LootItem struct
        lootItems.push_back(item);                                                                                      // Add the LootItem struct to the vector
    }

    return lootItems;                                                                                                   // Return the vector of LootItem structs
}

// Roll for loot
int LootTable::RollForLoot(int chance, int count) {
    static std::random_device rd;                                                                                       // Create a random device
    static std::mt19937 gen(rd());                                                                                   // Create a random number generator
    std::uniform_int_distribution<> dis(1, chance);                                                                 // Create a uniform distribution between 1 and the chance value
    int roll = dis(gen);                                                                                             // Roll the dice

    return std::min(roll, count);                                                                                   // Return the minimum of the roll and the count
}

// Calculate the loot from a list of table keys
std::vector<std::pair<std::string, int>> LootTable::CalculateLoot(const std::vector<std::string>& tableKeys) {
    std::vector<std::pair<std::string, int>> wonItems;                                                                  // Create a vector of pairs to hold the won items

    for (const auto& key : tableKeys) {                                                                      // Iterate through the table keys
        if (lootTables.find(key) != lootTables.end()) {                                                                 // Check if the key exists in the lootTables map
            for (const auto& item : lootTables[key]) {                                                                  // Iterate through the loot items
                int wonCount = RollForLoot(item.chance, item.count);                                                    // Roll for the loot count
                if (wonCount > 0)                                                                                       // Check if the player won any items
                    wonItems.emplace_back(item.item_name, wonCount);                                                 // Add the won item to the vector
            }
        }
    }

    return wonItems;                                                                                                    // Return the vector of won items
}