//
// Created by Paul McGinley on 13/09/2024.
//

#ifndef LOOT_TABLE_H
#define LOOT_TABLE_H

#include <string>
#include <vector>
#include <map>

struct LootItem {
    int chance;
    std::string item_name;
    int count;
};

class LootTable {
public:
    void LoadLootTable(const std::string& filename);
    std::vector<std::pair<std::string, int>> CalculateLoot(const std::vector<std::string>& tableKeys);

private:
    std::map<std::string, std::vector<LootItem>> lootTables;
    std::vector<LootItem> ParseLootTable(const std::string& filename);
    int RollForLoot(int chance, int count);
};

#endif //LOOT_TABLE_H
