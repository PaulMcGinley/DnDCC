#include <iostream>

#include "Modules/Player/player.h"

void MainMenu(std::vector<Player> *players);
void CreateCharacter(std::vector<Player> *players);
void LoadCharacter(std::vector<Player> *players);
void Exit();

int main() {

    std::vector<Player> players;

    // std::cout << "Hello, World!" << std::endl;
    //
    // std::cout << "  ████████████  " << std::endl;
    // std::cout << "██            ██" << std::endl;
    // std::cout << "██    █   █   ██" << std::endl;
    // std::cout << "██            ██" << std::endl;
    // std::cout << "██      █     ██" << std::endl;
    // std::cout << "██            ██" << std::endl;
    // std::cout << "  ████████████  " << std::endl;
    // std::cout << "  █ ██ ██ ██ █  " << std::endl;
    // std::cout << "  ████████████  " << std::endl;

    std::cout << R"(
 ______            _        _______  _______  _______  _        _______          __        ______   _______  _______  _______  _______  _        _______
(  __  \ |\     /|( (    /|(  ____ \(  ____ \(  ___  )( (    /|(  ____ \        /__\      (  __  \ (  ____ )(  ___  )(  ____ \(  ___  )( (    /|(  ____ \
| (  \  )| )   ( ||  \  ( || (    \/| (    \/| (   ) ||  \  ( || (    \/       ( \/ )     | (  \  )| (    )|| (   ) || (    \/| (   ) ||  \  ( || (    \/
| |   ) || |   | ||   \ | || |      | (__    | |   | ||   \ | || (_____         \  /      | |   ) || (____)|| (___) || |      | |   | ||   \ | || (_____
| |   | || |   | || (\ \) || | ____ |  __)   | |   | || (\ \) |(_____  )        /  \/\    | |   | ||     __)|  ___  || | ____ | |   | || (\ \) |(_____  )
| |   ) || |   | || | \   || | \_  )| (      | |   | || | \   |      ) |       / /\  /    | |   ) || (\ (   | (   ) || | \_  )| |   | || | \   |      ) |
| (__/  )| (___) || )  \  || (___) || (____/\| (___) || )  \  |/\____) |      (  \/  \    | (__/  )| ) \ \__| )   ( || (___) || (___) || )  \  |/\____) |
(______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)\_______)       \___/\/    (______/ |/   \__/|/     \|(_______)(_______)|/    )_)\_______)
_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
 _______           _______ _________ _______  _______ _________ _______  _______           _______  _______  _        _______  _______  _______  _______
(  ____ \|\     /|(  ___  )\__   __/(  ___  )(  ____ \\__   __/(  ____ \(  ____ )         (       )(  ___  )( (    /|(  ___  )(  ____ \(  ____ \(  ____ )
| (    \/| )   ( || (   ) |   ) (   | (   ) || (    \/   ) (   | (    \/| (    )|         | () () || (   ) ||  \  ( || (   ) || (    \/| (    \/| (    )|
| |      | (___) || (___) |   | |   | (___) || |         | |   | (__    | (____)|   _____ | || || || (___) ||   \ | || (___) || |      | (__    | (____)|
| |      |  ___  ||  ___  |   | |   |  ___  || |         | |   |  __)   |     __)  (_____)| |(_)| ||  ___  || (\ \) ||  ___  || | ____ |  __)   |     __)
| |      | (   ) || (   ) |   | |   | (   ) || |         | |   | (      | (\ (            | |   | || (   ) || | \   || (   ) || | \_  )| (      | (\ (
| (____/\| )   ( || )   ( |   | |   | )   ( || (____/\   | |   | (____/\| ) \ \__         | )   ( || )   ( || )  \  || )   ( || (___) || (____/\| ) \ \__
(_______/|/     \||/     \|   )_(   |/     \|(_______/   )_(   (_______/|/   \__/         |/     \||/     \||/    )_)|/     \|(_______)(_______/|/   \__/

    )" << std::endl;

    std::cout << R"(
·▄▄▄▄  ▄• ▄▌ ▐ ▄  ▄▄ • ▄▄▄ .       ▐ ▄ .▄▄ ·      ▐ ▄     ·▄▄▄▄  ▄▄▄   ▄▄▄·  ▄▄ •        ▐ ▄ .▄▄ ·
██▪ ██ █▪██▌•█▌▐█▐█ ▀ ▪▀▄.▀·▪     •█▌▐█▐█ ▀.     •█▌▐█    ██▪ ██ ▀▄ █·▐█ ▀█ ▐█ ▀ ▪▪     •█▌▐█▐█ ▀.
▐█· ▐█▌█▌▐█▌▐█▐▐▌▄█ ▀█▄▐▀▀▪▄ ▄█▀▄ ▐█▐▐▌▄▀▀▀█▄    ▐█▐▐▌    ▐█· ▐█▌▐▀▀▄ ▄█▀▀█ ▄█ ▀█▄ ▄█▀▄ ▐█▐▐▌▄▀▀▀█▄
██. ██ ▐█▄█▌██▐█▌▐█▄▪▐█▐█▄▄▌▐█▌.▐▌██▐█▌▐█▄▪▐█    ██▐█▌    ██. ██ ▐█•█▌▐█ ▪▐▌▐█▄▪▐█▐█▌.▐▌██▐█▌▐█▄▪▐█
▀▀▀▀▀•  ▀▀▀ ▀▀ █▪·▀▀▀▀  ▀▀▀  ▀█▄▀▪▀▀ █▪ ▀▀▀▀     ▀▀ █▪    ▀▀▀▀▀• .▀  ▀ ▀  ▀ ·▀▀▀▀  ▀█▄▀▪▀▀ █▪ ▀▀▀▀
     ▄▄·  ▄ .▄ ▄▄▄· ▄▄▄▄▄ ▄▄▄·  ▄▄· ▄▄▄▄▄▄▄▄ .▄▄▄      • ▌ ▄ ·.  ▄▄▄·  ▐ ▄  ▄▄▄·  ▄▄ • ▄▄▄ .▄▄▄
    ▐█ ▌▪██▪▐█▐█ ▀█ •██  ▐█ ▀█ ▐█ ▌▪•██  ▀▄.▀·▀▄ █·    ·██ ▐███▪▐█ ▀█ •█▌▐█▐█ ▀█ ▐█ ▀ ▪▀▄.▀·▀▄ █·
    ██ ▄▄██▀▐█▄█▀▀█  ▐█.▪▄█▀▀█ ██ ▄▄ ▐█.▪▐▀▀▪▄▐▀▀▄     ▐█ ▌▐▌▐█·▄█▀▀█ ▐█▐▐▌▄█▀▀█ ▄█ ▀█▄▐▀▀▪▄▐▀▀▄
    ▐███▌██▌▐▀▐█ ▪▐▌ ▐█▌·▐█ ▪▐▌▐███▌ ▐█▌·▐█▄▄▌▐█•█▌    ██ ██▌▐█▌▐█ ▪▐▌██▐█▌▐█ ▪▐▌▐█▄▪▐█▐█▄▄▌▐█•█▌
    ·▀▀▀ ▀▀▀ · ▀  ▀  ▀▀▀  ▀  ▀ ·▀▀▀  ▀▀▀  ▀▀▀ .▀  ▀    ▀▀  █▪▀▀▀ ▀  ▀ ▀▀ █▪ ▀  ▀ ·▀▀▀▀  ▀▀▀ .▀  ▀
    )" << std::endl;

    MainMenu(&players);

    return 0;
}

void MainMenu(std::vector<Player> *players) {
    std::cout << "Dungeons & Dragons - Character Manager, v.01 | By Paul F. McGinley (2024)" << std::endl;
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
                CreateCharacter(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Load an existing character
            case 2: {
                valid = true;
                std::cout << "-----> Loading an existing character" << std::endl;
                //ListCharacters(players);
                break;
            }

            // ---------------------------------------------------------------------------------------------------------
            // Exit
            case 3: {
                std::cout << "-----> Exiting" << std::endl;
                //return false; // Exit the program
            }

            // ---------------------------------------------------------------------------------------------------------
            // Butter fingers
            default: {
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


    players->push_back(player);
}