#include <iostream>

#include "Enumerators/syllables.h"
#include "Utilities/utility.h"
#include "Modules/Player/player.h"
#include "Utilities/console_formatter.h"
#include "Utilities/input.h"
#include "Utilities/name_generator.h"

bool MainLoop(std::vector<Player> *players);
void MainMenu(std::vector<Player> *players);
void CreateCharacter(std::vector<Player> *players);
void ListCharacters(std::vector<Player> *players);
void ViewCharacter(Player *player);
void Exit();

int main() {

    std::cout << std::endl << ConsoleFormat::BOLD << "Trollish:" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(1,2, NameGenerator::TROLLISH_SYLLABLES) + " " + NameGenerator::generateName(2,3,NameGenerator::TROLLISH_SYLLABLES) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Orcish:" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(1,2, NameGenerator::ORCISH_SYLLABLES) + " " + NameGenerator::generateName(2,2,NameGenerator::ORCISH_SYLLABLES) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Entish:" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,4, NameGenerator::ENTISH_SYLLABLES) + " " + NameGenerator::generateName(2,5,NameGenerator::ENTISH_SYLLABLES) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Elvish (Male):" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,3, NameGenerator::ELVISH_SYLLABLES_MALE) + " " + NameGenerator::generateName(2,4,NameGenerator::ELVISH_SYLLABLES_MALE) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Elvish (Female):" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,3, NameGenerator::ELVISH_SYLLABLES_FEMALE) + " " + NameGenerator::generateName(2,4,NameGenerator::ELVISH_SYLLABLES_FEMALE) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Gaelic:" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,4, NameGenerator::GAELIC_SYLLABLES) + " " + NameGenerator::generateName(2,5,NameGenerator::GAELIC_SYLLABLES) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Generic:" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(1,4) + " " + NameGenerator::generateName(1,5) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Drawrvish (Male):" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,2, NameGenerator::DWARVISH_SYLLABLES_MALE) + " " + NameGenerator::generateName(2,3,NameGenerator::DWARVISH_SYLLABLES_MALE) << std::endl;

    std::cout << std::endl << ConsoleFormat::BOLD << "Drawrvish (Female):" << std::endl << ConsoleFormat::RESET;
    for (int i = 0; i < 10; i++)
        std::cout << NameGenerator::generateName(2,2, NameGenerator::DWARVISH_SYLLABLES_FEMALE) + " " + NameGenerator::generateName(2,3,NameGenerator::DWARVISH_SYLLABLES_FEMALE) << std::endl;



    // Headers
    Utility::PrintTitle();
    ConsoleFormat::PrintRightAligned("v.01 By Paul F. McGinley (2024)");

    std::vector<Player> players;
    // Loot tables
    // Encounter tables

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
        std::cout << ConsoleFormat::BG_WHITE << ConsoleFormat::BLACK;                                                   // Set the text color
        InputUtils::GetInt(choice, "Enter the number of the option you wish to select: ");                               // Ask the user for their choice
        std::cout << ConsoleFormat::RESET;                                                                              // Reset the text color
        //std::cin >> choice;                                                                                             // Get the user's choice

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

        InputUtils::GetString(player.name, "Enter the name of the character: ");                                         // Ask the user for the name
        //std::cout << "Enter the name of the character: ";
        //std::cin >> player.name;                                                                                        // Get the name from the user

        if (player.name.empty()) {                                                                                      // Check if the name is empty

            // std::cout << Syllables::Generic << " " << Utility::SyllableToString(Syllables::Generic) << std::endl;                // Print the syllable
            // std::cout << Syllables::Entish << " " << Utility::SyllableToString(Syllables::Entish) << std::endl;                  // Print the syllable
            // std::cout << Syllables::Gaelic << " " << Utility::SyllableToString(Syllables::Gaelic) << std::endl;                  // Print the syllable
            // std::cout << Syllables::Trollish << " " << Utility::SyllableToString(Syllables::Trollish) << std::endl;              // Print the syllable
            // std::cout << Syllables::Orcish << " " << Utility::SyllableToString(Syllables::Orcish) << std::endl;                  // Print the syllable
            // std::cout << Syllables::Elvish_Female << " " << Utility::SyllableToString(Syllables::Elvish_Female) << std::endl;    // Print the syllable
            // std::cout << Syllables::Elvish_Male << " " << Utility::SyllableToString(Syllables::Elvish_Male) << std::endl;        // Print the syllable



            player.name = NameGenerator::generateName(2,4) + " " + NameGenerator::generateName(2,5);                                                                // Generate a random name
            std::cout << "Random name generated: " << player.name << std::endl;                                          // Print the random name// Ask again....
        }

        unique = true;                                                                                                  // Assume the name is unique
        for (auto & p : *players)                                                                                // Loop through the list of players
            if (p.name == player.name) {                                                                                // Check if the name matches
                std::cout << "Name already exists, please choose another one\n" << std::endl;
                unique = false;                                                                                         // You know what they say when you assume -.-
                break;                                                                                                  // Lets ask again....
            }
    }

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

    Utility::PrintPlayerListHeader();                                                                                   // Print the header for the list of players

    for (int i = 0; i < players->size(); i++)
        Utility::PrintPlayerListRow(i, &players->at(i));

    int choice;                                                                                                         // User's choice
    bool valid = false;                                                                                                 // Flag to check if the choice is valid
    while (!valid) {                                                                                                    // Loop until the choice is valid
        InputUtils::GetInt(choice, "Enter the number of the character you wish to view: ");                              // Ask the user for their choice
        //std::cout << "Enter the number of the character you wish to view: ";                                            // Ask the user for their choice
        //std::cin >> choice;                                                                                             // Get the user's choice
        std::cout << std::endl;
        if (choice >= 0 && choice < players->size()) {                                                                   // Check if the choice is valid
            valid = true;                                                                                               // Set the flag to true
            ViewCharacter(&players->at(choice));                                                                         // View the character
        } else {
            std::cout << "-----> Invalid choice" << std::endl;                                                           // Print an error message
        }
    }
}

void ViewCharacter(Player *player) {

    ConsoleFormat::ClearConsole();                                                                                      // Clear the console
    Utility::PrintHeader("Character Viewer : " + player->name);                                                     // Print the header
    Utility::PrintCharacterStatSheet(player);                                                                            // Print the character's stats
}
