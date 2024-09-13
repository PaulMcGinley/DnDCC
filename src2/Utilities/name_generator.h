//
// Created by Paul McGinley on 13/09/2024.
//

#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#include <vector>

class NameGenerator {
public:
    // Static function to generate a name with random syllables
    static std::string generateName(int minSyllables, int maxSyllables, std::vector<std::string> syllables = GENERIC_SYLLABLES);

    static const std::vector<std::string> GENERIC_SYLLABLES;
    static const std::vector<std::string> ENTISH_SYLLABLES;
    static const std::vector<std::string> GAELIC_SYLLABLES;
    static const std::vector<std::string> TROLLISH_SYLLABLES;
    static const std::vector<std::string> ORCISH_SYLLABLES;
    static const std::vector<std::string> ELVISH_SYLLABLES_MALE;
    static const std::vector<std::string> ELVISH_SYLLABLES_FEMALE;
    static const std::vector<std::string> DWARVISH_SYLLABLES_MALE;
    static const std::vector<std::string> DWARVISH_SYLLABLES_FEMALE;
};

#endif //NAME_GENERATOR_H
