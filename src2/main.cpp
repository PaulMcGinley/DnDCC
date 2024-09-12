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

    ConsoleFormat::ClearConsole();                                                                                      // Clear the console
    Utility::PrintHeader("Main Menu");                                                                         // Print the header

    std::cout << std::endl << "Please select an option:"  << std::endl  << std::endl;

    std::cout << ConsoleFormat::BOLD << "#\tDescription" << ConsoleFormat::RESET << std::endl;
    std::cout << "1\t" << "Create a new character" << std::endl;
    std::cout << "2\t" << "Load an existing character" << std::endl;
    std::cout << "3\t" << ConsoleFormat::BOLD << ConsoleFormat::BG_RED << ConsoleFormat::BLACK << "Exit" << ConsoleFormat::RESET << std::endl;

    int choice;                                                                                                         // User's choice
    bool valid = false;                                                                                                 // Flag to check if the choice is valid
    while (!valid) {                                                                                                    // Loop until the choice is valid
        std::cin >> choice;                                                                                             // Get the user's choice

        // Switch on the user's choice
        // I assume this is like C# where at compile time it will be optimized to a jump table rather than a series of if-else statements
        switch (choice) {

            // Create a new character
            case 1: {
                valid = true;
                CreateCharacter(players);
                break;
            }

            // List existing characters
            case 2: {
                valid = true;
                ListCharacters(players);
                break;
            }

            // Exit
            case 3: {
                std::cout << ConsoleFormat::RED;
                std::cout << "-----> Exiting" << std::endl;
            }

            // Butter fingers
            default: {
                std::cout << "-----> Invalid choice" << std::endl;
                break;
            }
        }
    }
}

void CreateCharacter(std::vector<Player> *players) {

    ConsoleFormat::ClearConsole();                                                                                      // Clear the console
    Utility::PrintHeader("Character Creator");                                                                 // Print the header

    std::cout << std::endl << "Welcome to the character creator!" << std::endl;
    std::cout              << "Below is a table containing your randomly generated attributes." << std::endl;
    std::cout              << "If you would like to keep those attributes then please select an available class." << std::endl;
    std::cout              << "If the attributes are not to your liking you are welcome to try your luck again." << std::endl << std::endl;

    auto player = Player(true);                                                                                         // Create a new character object

    bool unique = false;                                                                                                // Flag to check if the name is unique
    while (!unique) {                                                                                                   // Loop until the name is unique

        std::cout << "Enter the name of the character: ";
        std::cin >> player.name;                                                                                        // Get the name from the user

        unique = true;                                                                                                  // Assume the name is unique
        for (auto & p : *players)                                                                                // Loop through the list of players
            if (p.name == player.name) {                                                                                // Check if the name matches
                std::cout << "Name already exists, please choose another one\n" << std::endl;
                unique = false;                                                                                         // You know what they say when you assume -.-
                break;                                                                                                  // Lets ask again....
            }
    }

    //Utility::PrintCharacterStatSheet(&player);                                                                          // Print the character's stats DEBUG

    // The name is unique, so we can continue
    players->push_back(player);                                                                                         // Add the character to the list of players
}

void ListCharacters(std::vector<Player> *players) {
    ConsoleFormat::ClearConsole();                                                                                      // Clear the console
    Utility::PrintHeader("Character List");                                                                    // Print the header

    // Guard clause - Skip the rest if there are no players
    if (players->empty()) {
        std::cout << std::endl << "No characters found" << std::endl << std::endl;
        return;
    }

    std::cout << std::endl << "Below is a list of created characters." << std::endl;
    std::cout              << "Select the character you with to interact with." << std::endl << std::endl;

    std::cout << ConsoleFormat::BOLD << std::left
          << std::setw(5) << "Idx"
          << std::setw(30) << "Name"
          << std::setw(20) << "Class"
          << std::setw(10) << "Level"
          << std::setw(10) << "Experience"
          //<< std::setw(78) << " " // Fill the remaining space with spaces
          << ConsoleFormat::RESET << std::endl;

    for (int i = 0; i < players->size(); i++) {
        Utility::PrintPlayerListRow(i, &players->at(i));
        //std::cout << i << "\t" << players->at(i).name << "\t" << Utility::CharacterClassToString(players->at(i).character_class) << std::endl;
    }
}
