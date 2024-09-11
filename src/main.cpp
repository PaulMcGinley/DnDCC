#include <iostream>
#include <vector>
#include "Models/Character.hpp"

// Forward declaration
bool Loop(std::vector<Character> *p);
void ListCharacters(std::vector<Character> *p);
void NewCharacter(std::vector<Character> *p);

int main() {
    std::vector<Character> players;

    bool running = true;
    while (running) {
        running = Loop(&players);
    }

    return 0;
}

// Main menu loop
bool Loop(std::vector<Character> *players) {
    std::cout << "Dungeons & Dragons - Character Creator, v.01" << std::endl;
    std::cout << "#\tDescription" << std::endl;
    std::cout << "1\tCreate a new character" << std::endl;
    std::cout << "2\tLoad an existing character" << std::endl;
    std::cout << "3\tExit" << std::endl;

    int choice;

    bool valid = false;
    while (!valid) {
        std::cin >> choice; // Get the user's choice

        // Switch on the user's choice
        // I assume this is like C# where at compile time it will be optimized to a jump table rather than a series of if-else statements
        switch (choice) {

            // ---------------------------------------------------------------------------------------------------------
            // Create a new character
            case 1: {
                valid = true;
                std::cout << "-----> Creating a new character" << std::endl;
                NewCharacter(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Load an existing character
            case 2: {
                valid = true;
                std::cout << "-----> Loading an existing character" << std::endl;
                ListCharacters(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Exit
            case 3: {
                std::cout << "-----> Exiting" << std::endl;
                return false; // Exit the program
            }

            // ---------------------------------------------------------------------------------------------------------
            // Butter fingers
            default: {
                std::cout << "-----> Invalid choice" << std::endl;
                break;
            }
        }
    }
    return true;
}

void ListCharacters(std::vector<Character> *players) {
    if (!players->empty()) {
        for (int i = 0; i < players->size(); i++) {
            std::cout << i << "\t" << players->at(i).name << "\t" << players->at(i).Class() << std::endl;
        }
    } else {
        std::cout << "No characters found" << std::endl;
    }
}

void NewCharacter(std::vector<Character> *players) {
    Character player = Character(); // Create a new character object

    bool unique = false; // Flag to check if the name is unique
    while (!unique) { // Loop until the name is unique
        std::cout << "Enter the name of the character: ";
        std::cin >> player.name; // Get the name from the user

        unique = true; // Assume the name is unique
        for (int i = 0; i < players->size(); i++) { // Loop through the list of players
            if (players->at(i).name == player.name) { // Check if the name already exists -- at(i) = players[i]
                std::cout << "Name already exists, please choose another one\n" << std::endl;
                unique = false; // You know what they say when you assume -.-
                break; // Lets ask again....
            }
        }
    }

    std::cout << "Character created: " << player.name << " [" << player.Class() << "]" << std::endl;
    std::cout << "Abilities:\t\tBase\tBonus\tModifier\tValue" << std::endl;
    printf("Health:\t\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.health[0], player.health[1], player.health[2], player.Health());
    printf("Max Health:\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.maxHealth[0], player.maxHealth[1], player.maxHealth[2], player.MaxHealth());
    printf("Strength:\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.strength[0], player.strength[1], player.strength[2], player.Strength());
    printf("Dexterity:\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.dexterity[0], player.dexterity[1], player.dexterity[2], player.Dexterity());
    printf("Constitution:\t%d\t\t%d\t\t%d\t\t\t%d\n", player.constitution[0], player.constitution[1], player.constitution[2], player.Constitution());
    printf("Intelligence:\t%d\t\t%d\t\t%d\t\t\t%d\n", player.intelligence[0], player.intelligence[1], player.intelligence[2], player.Intelligence());
    printf("Wisdom:\t\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.wisdom[0], player.wisdom[1], player.wisdom[2], player.Wisdom());
    printf("Charisma:\t\t%d\t\t%d\t\t%d\t\t\t%d\n", player.charisma[0], player.charisma[1], player.charisma[2], player.Charisma());

    std::cout << "------------------------------------------" << std::endl;

    players->push_back(player);
}