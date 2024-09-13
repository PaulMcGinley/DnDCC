//
// Created by Paul McGinley on 13/09/2024.
//

#include "name_generator.h"

#include <random>
#include <__random/random_device.h>

// Sylaballs for name generation
// There are duplicated and none starting with vowels, but its the best ChatGippity could do I guess
const std::vector<std::string> NameGenerator::components = {
    "pa", "ri", "ko", "la", "mi", "su", "zo", "ta", "na", "li",
    "fa", "ro", "mo", "da", "sha", "ka", "ti", "le", "no", "va",
    "si", "ke", "jo", "fi", "me", "ze", "hu", "bo", "wi", "xo",
    "ya", "lo", "chi", "do", "pi", "ga", "ve", "re", "ki", "to",
    "ne", "xi", "qua", "te", "ma", "ra", "sha", "lu", "je", "ri",
    "ni", "gu", "ti", "ba", "nu", "ka", "se", "fu", "chi", "za",
    "ho", "yu", "ji", "ma", "wa", "cu", "li", "ra", "pe", "no",
    "me", "xi", "lo", "ka", "ve", "to", "je", "si", "gi", "ha",
    "be", "so", "ja", "pi", "mu", "lu", "ze", "ce", "fa", "ra",
    "mi", "lo", "sha", "nu", "fi", "mo", "re", "ba", "xi", "do",
    "je", "ve", "ke", "xi", "zo", "la", "hu", "da", "so", "ru",
    "ma", "ta", "wi", "zu", "yo", "pe", "se", "na", "co", "xu",
    "lo", "re", "xi", "pu", "ge", "to", "li", "ru", "mu", "sa",
    "ke", "ta", "fa", "mi", "bu", "si", "na", "ja", "pa", "lu",
    "za", "me", "ra", "ki", "fu", "le", "du", "je", "xo", "ri"
};

// Static function to generate a name with random syllables
std::string NameGenerator::generateName(int minSyllables, int maxSyllables) {
    // Create a random device and a Mersenne Twister random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform distribution for the number of syllables
    std::uniform_int_distribution<> syllableDist(minSyllables, maxSyllables);
    int numSyllables = syllableDist(gen);

    std::string name = "";
    // Create a uniform distribution for the index of components
    std::uniform_int_distribution<> componentDist(0, components.size() - 1);
    for (int i = 0; i < numSyllables; ++i) {
        int randomIndex = componentDist(gen);  // Randomly pick a component
        name += components[randomIndex];
    }

    name[0] = std::toupper(name[0]);  // Capitalize the first letter
    return name;
}