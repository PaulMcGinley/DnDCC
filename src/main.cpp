#include <iostream>
#include <vector>
#include "Models/Character.hpp"

// Forward declaration because with all the updates and versions to C++ no one thought to add a way to handle this automatically -.-
void ListCharacters(std::vector<Character> *vector);
void NewCharacter(std::vector<Character> *vector);
void Loop();

int main() {
    std::vector<Character> players;

    std::cout << "Dungeons & Dragons - Character Creator, v.01" << std::endl;
    std::cout << "#\tDescription" << std::endl;
    std::cout << "1\tCreate a new character" << std::endl;
    std::cout << "2\tLoad an existing character" << std::endl;
    std::cout << "3\tExit" << std::endl;

    int choice;
    bool valid = false;

    while (!valid) {

        std::cin >> choice;

        switch (choice) {
            case 1: {
                valid = true;

                std::cout << "Creating a new character" << std::endl;
                Character player = Character();
                player.GenerateBaseAbilities();

                break;
            }
            case 2: {
                valid = true;
                std::cout << "Loading an existing character" << std::endl;
                ListCharacters(&players);

                break;
            }
            case 3: {
                //valid = true;

                std::cout << "Exiting" << std::endl;

                return 0; // Exit the program
            }
            default: {
                std::cout << "Invalid choice" << std::endl;

                break;
            }
        }
    }
}

void Loop() {

}




void ListCharacters(std::vector<Character> *players) {
    std::cout << "Listing all characters" << std::endl;

    if (!players->empty()) {
        for (int i = 0; i < players->size(); i++) {
            std::cout << i << "\t" << players->at(i).name << std::endl;
        }
    } else {
        std::cout << "No characters found" << std::endl;
    }
}

void NewCharacter(std::vector<Character> *players) {
    std::cout << "Creating a new character" << std::endl;
    Character player = Character();
    player.GenerateBaseAbilities();
    players->push_back(player);

}
