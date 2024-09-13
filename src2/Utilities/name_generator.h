//
// Created by Paul McGinley on 13/09/2024.
//

#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <vector>

class NameGenerator {
public:
    // Static function to generate a name with random syllables
    static std::string generateName(int minSyllables, int maxSyllables);

private:
    // Static list of components (syllables) for names
    static const std::vector<std::string> components;
};

#endif //NAME_GENERATOR_H
