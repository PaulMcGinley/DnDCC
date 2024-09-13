//
// Created by Paul McGinley on 13/09/2024.
//

#include "input.h"
#include <algorithm>

#include "../Enumerators/syllables.h"

namespace InputUtils {

    // Get an integer from the user
    void GetInt(int &variable, const std::string &prompt) {

        // Loop until we get a valid integer
        while (true) {
            std::cout << prompt;                                                                                        // Print the inline prompt
            std::cin >> variable;                                                                                       // Get the user's input

            if (std::cin.fail()) {                                                                                      // If the input failed
                std::cin.clear();                                                                                       // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                               // Ignore the rest of the input
                std::cout << "int expected" << std::endl;                                                               // Print an error message
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                               // Ignore after newline
                break;                                                                                                  // Exit the loop
            }
        }
    }

    // Get a boolean from the user
    void GetBool(bool &variable, const std::string &prompt) {

        // Loop until we get a valid boolean
        while (true) {
            std::cout << prompt << " (true/false): ";                                                                   // Print the inline prompt
            std::string input;                                                                                          // Create a string to store the user's input
            std::cin >> input;                                                                                          // Get the user's input

            // Convert input to lowercase
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);

            // Check if the input is true or false
            if (input == "true" || input == "1") {
                variable = true;                                                                                        // Set the variable to true
                break;                                                                                                  // Exit the loop
            } else if (input == "false" || input == "0") {
                variable = false;                                                                                       // Set the variable to false
                break;                                                                                                  // Exit the loop
            } else {
                std::cin.clear();                                                                                       // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                               // Ignore the rest of the input
                std::cout << "Invalid input. Please enter true/false." << std::endl;                                    // Print an error message
            }
        }
    }

    // Get a float from the user
    void GetFloat(float &variable, const std::string &prompt) {

        // Loop until we get a valid float
        while (true) {
            std::cout << prompt;                                                                                        // Print the inline prompt
            std::cin >> variable;                                                                                       // Get the user's input

            // Check if the input failed
            if (std::cin.fail()) {
                std::cin.clear();                                                                                       // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                               // Ignore the rest of the input
                std::cout << "Invalid input. Please enter a valid float." << std::endl;                                 // Print an error message
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                               // Ignore after newline
                break;                                                                                                  // Exit the loop
            }
        }
    }

    // Get a string from the user
    void GetString(std::string &variable, const std::string &prompt) {

        std::cout << prompt;                                                                                            // Print the inline prompt
        std::getline(std::cin, variable);                                                                         // Get the user's input
    }
}
