#include <iostream>

#include "Enumerators/syllables.h"
#include "Utilities/utility.h"
#include "Modules/Player/player.h"
#include "Utilities/Console/console_formatter.h"
#include "Utilities/Input/input.h"
#include "Modules/Name_Generator/name_generator.h"

bool MainLoop(std::vector<Player> *players);
void MainMenu(std::vector<Player> *players);
void CreateCharacter(std::vector<Player> *players);
void ListCharacters(std::vector<Player> *players);
void ViewCharacter(Player *player);
void Exit();

int main() {

    // Headers
    //Utility::PrintTitle();
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

    std::cout << ConsoleFormat::BOLD << "#\t" << "Description" << ConsoleFormat::RESET << std::endl;
    std::cout                        << "1\t" << "Create a new character" << std::endl;
    std::cout                        << "2\t" << "Load an existing character" << std::endl;
    std::cout                        << "3\t" << "Exit" << std::endl << std::endl;

    int choice;                                                                                                         // User's choice
    bool valid = false;                                                                                                 // Flag to check if the choice is valid
    while (!valid) {                                                                                                    // Loop until the choice is valid
        InputUtils::GetInt(choice, "Option > ");                                                             // Ask the user for their choice
        std::cout << std::endl;

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

        Utility::PrintSubHeader("Enter the name of the character");                                              // Print the subheader
        std::cout  << "Enter a unique name or alternatively leave the field blank to use the Name Generator." << std::endl << std::endl;                       // Ask the user for the name
        InputUtils::GetString(player.name, "Name > ");                                         // Ask the user for the name
        std::cout << std::endl;
        //std::cout << "Enter the name of the character: ";
        //std::cin >> player.name;                                                                                        // Get the name from the user

        if (player.name.empty()) {                                                                                      // Check if the name is empty

            Utility::PrintHeader("Name Generator");                                                             // Print the subheader

            std::cout << std::endl << "Please select the language origin of the name to be generated." << std::endl << std::endl;                                   // Ask the user for the language origin
            std::cout << ConsoleFormat::BOLD << "Option\tLanguage Origin" << ConsoleFormat::RESET << std::endl;                                                        // Print the subheader
            std::cout << Syllables::Generic << "\t\t" << Utility::SyllableToString(Syllables::Generic) << std::endl;                // Print the syllable
            std::cout << Syllables::Entish << "\t\t" << Utility::SyllableToString(Syllables::Entish) << std::endl;                  // Print the syllable
            std::cout << Syllables::Gaelic << "\t\t" << Utility::SyllableToString(Syllables::Gaelic) << std::endl;                  // Print the syllable
            std::cout << Syllables::Trollish << "\t\t" << Utility::SyllableToString(Syllables::Trollish) << std::endl;              // Print the syllable
            std::cout << Syllables::Orcish << "\t\t" << Utility::SyllableToString(Syllables::Orcish) << std::endl;                  // Print the syllable
            std::cout << Syllables::Elvish_Male << "\t\t" << Utility::SyllableToString(Syllables::Elvish_Male) << std::endl;        // Print the syllable
            std::cout << Syllables::Elvish_Female << "\t\t" << Utility::SyllableToString(Syllables::Elvish_Female) << std::endl;    // Print the syllable
            std::cout << Syllables::Dwarvish_Male << "\t\t" << Utility::SyllableToString(Syllables::Dwarvish_Male) << std::endl;    // Print the syllable
            std::cout << Syllables::Dwarvish_Female << "\t\t" << Utility::SyllableToString(Syllables::Dwarvish_Female) << std::endl;// Print the syllable
            std::cout << std::endl;
            int choice;                                                                                                 // User's choice
            bool valid = false;                                                                                         // Flag to check if the choice is valid
            while (!valid) {

                InputUtils::GetInt(choice, "Option > ");                                       // Ask the user for their choice

                if (choice < 0 || choice > Syllables::Dwarvish_Female) {
                    std::cout << "-----> Invalid choice" << std::endl;
                    continue;
                }

                valid = true;                                                                                           // Set the flag to true

            }

            std::vector<std::string> syllables;  // Create a vector to hold the syllables
            int first_name_min = 0;
            int first_name_max = 0;
            int last_name_min = 0;
            int last_name_max = 0;
            switch (choice) {

                case 0:
                    syllables = NameGenerator::GENERIC_SYLLABLES;
                first_name_min = 1;
                first_name_max = 4;
                last_name_min = 1;
                last_name_max = 5;
                break;

                case 1:
                    syllables = NameGenerator::ENTISH_SYLLABLES;
                first_name_min = 2;
                first_name_max = 4;
                last_name_min = 2;
                last_name_max = 5;
                break;

                case 2:
                    syllables = NameGenerator::GAELIC_SYLLABLES;
                first_name_min = 2;
                first_name_max = 4;
                last_name_min = 2;
                last_name_max = 5;
                break;

                case 3:
                    syllables = NameGenerator::TROLLISH_SYLLABLES;
                first_name_min = 1;
                first_name_max = 2;
                last_name_min = 2;
                last_name_max = 3;
                break;

                case 4:
                    syllables = NameGenerator::ORCISH_SYLLABLES;
                first_name_min = 1;
                first_name_max = 2;
                last_name_min = 2;
                last_name_max = 2;
                break;

                case 5:
                    syllables = NameGenerator::ELVISH_SYLLABLES_MALE;
                first_name_min = 2;
                first_name_max = 3;
                last_name_min = 2;
                last_name_max = 4;
                break;

                case 6:
                    syllables = NameGenerator::ELVISH_SYLLABLES_FEMALE;
                first_name_min = 2;
                first_name_max = 3;
                last_name_min = 2;
                last_name_max = 4;
                break;

                case 7:
                    syllables = NameGenerator::DWARVISH_SYLLABLES_MALE;
                first_name_min = 2;
                first_name_max = 2;
                last_name_min = 2;
                last_name_max = 3;
                break;

                case 8:
                    syllables = NameGenerator::DWARVISH_SYLLABLES_FEMALE;
                first_name_min = 2;
                first_name_max = 2;
                last_name_min = 2;
                last_name_max = 3;
                break;

                default:
                    std::cout << "Invalid choice" << std::endl;
                break;
            }

            player.name = NameGenerator::generateName(first_name_min,first_name_max,syllables) + " " + NameGenerator::generateName(last_name_min,last_name_max,syllables);                                                                // Generate a random name
            std::cout<< std::endl << "Welcome to the world, " << player.name <<"!"<< std::endl<< std::endl;                                          // Print the random name// Ask again....
        }

        unique = true;                                                                                                  // Assume the name is unique
        for (auto const & p : *players)                                                                                // Loop through the list of players
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
        std::cout << std::endl;
        InputUtils::GetInt(choice, "Idx > ");                              // Ask the user for their choice
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
    std::cout << std::endl << "A full information set is listed blow:" << std::endl << std::endl;
    std::cout <<"Class: " << Utility::CharacterClassToString(player->character_class) << std::endl;
    std::cout <<"Level: " << player->level << std::endl;
    std::cout <<"Experience: " << player->experience << std::endl;
    std::cout <<"Health: (" << player->health.remaining << "/" << player->health.Max() << ") " << player->health.Percent()*100 << "%" << std::endl;
    std::cout <<"Mana: (" << player->mana.remaining << "/" << player->mana.Max() << ") " << player->mana.Percent()*100 << "%" << std::endl;
    std::cout << std::endl;
    Utility::PrintCharacterStatSheet(player);                                                                            // Print the character's stats
    std::cout << std::endl;
}
