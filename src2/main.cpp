#include <iostream>

#include "Utilities/utility.h"
#include "Modules/Player/player.h"
#include "Utilities/console_formatter.h"

bool MainLoop(std::vector<Player> *players);
void MainMenu(std::vector<Player> *players);
void CreateCharacter(std::vector<Player> *players);
void ListCharacters(std::vector<Player> *players);
void Exit();

int main() {

    Utility::PrintTitle();
    ConsoleFormat::PrintRightAligned("v.01 By Paul F. McGinley (2024)");

    std::vector<Player> players;

    bool running = true;
    while (running) {
        running = MainLoop(&players);
    }

    return 0;
}

bool MainLoop(std::vector<Player> *players) {
    MainMenu(players);
    return true;
}

void MainMenu(std::vector<Player> *players) {
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
                ConsoleFormat::ClearConsole();
                CreateCharacter(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Load an existing character
            case 2: {
                valid = true;
                std::cout << "-----> Loading an existing character" << std::endl;
                Utility::PrintSpacer();
                ListCharacters(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Exit
            case 3: {
                Utility::PrintSpacer();
                std::cout << "-----> Exiting" << std::endl;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Butter fingers
            default: {
                Utility::PrintSpacer();
                std::cout << "-----> Invalid choice" << std::endl;
                break;
            }
        }
    }
}

void CreateCharacter(std::vector<Player> *players) {
    Player player = Player(true); // Create a new character object

    bool unique = false; // Flag to check if the name is unique
    while (!unique) {
        // Loop until the name is unique
        std::cout << "Enter the name of the character: ";
        std::cin >> player.name; // Get the name from the user

        unique = true; // Assume the name is unique
        for (int i = 0; i < players->size(); ++i) { // Loop through the list of players
            if (players->at(i).name == player.name) { // Check if the name already exists -- at(i) = players[i]
                std::cout << "Name already exists, please choose another one\n" << std::endl;
                unique = false; // You know what they say when you assume -.-
                break; // Lets ask again....
            }
        }
    }
    Utility::PrintCharacterStatSheet(&player);
    players->push_back(player);
}

void ListCharacters(std::vector<Player> *players) {
    if (!players->empty()) {
        for (int i = 0; i < players->size(); i++) {
            std::cout << i << "\t" << players->at(i).name << "\t" << Utility::CharacterClassToString(players->at(i).character_class) << std::endl;
        }
    } else {
        std::cout << "No characters found" << std::endl;
    }
}
