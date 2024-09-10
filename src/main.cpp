#include <iostream>

#include "Models/Character.hpp"

int main() {

    // Create a new character
    Character player = Character();

    // Test rolls
    std::vector<int> rolls = player.Roll();
    for (int roll : rolls) {
        std::cout << roll << std::endl;
    }



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
