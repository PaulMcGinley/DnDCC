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
        // I assume this is like C# where at compile time it will be optimized to a jump table
        // rather than a series of if-else statements
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
    std::cout << "Abilities: " << std::endl;
    std::cout << "Strength: " << player.Strength() << std::endl;
    std::cout << "Dexterity: " << player.Dexterity() << std::endl;
    std::cout << "Constitution: " << player.Constitution() << std::endl;
    std::cout << "Intelligence: " << player.Intelligence() << std::endl;
    std::cout << "Wisdom: " << player.Wisdom() << std::endl;
    std::cout << "Charisma: " << player.Charisma() << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    players->push_back(player);
}