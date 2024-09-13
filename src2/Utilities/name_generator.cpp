//
// Created by Paul McGinley on 13/09/2024.
//

#include "name_generator.h"

#include <random>
#include <__random/random_device.h>

// Sylaballs for name generation
// There are duplicated and none starting with vowels, but its the best ChatGippity could do I guess
const std::vector<std::string> NameGenerator::GENERIC_SYLLABLES = {
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

const std::vector<std::string> NameGenerator::ELVISH_SYLLABLES_MALE = {
    "el", "dar", "ion", "fë", "a", "nor", "gand", "alf", "glor", "find",
    "el", "leg", "olas", "thran", "du", "il", "ell", "adan", "el", "ro",
    "hir", "ce", "le", "born", "ar", "a", "gorn", "hal", "dir", "tu",
    "rin", "fin", "rod", "ber", "en", "ec", "the", "lion", "tur", "gon",
    "rú", "mil", "am", "dir", "sa", "eros", "o", "rod", "reth"

};

const std::vector<std::string> NameGenerator::ELVISH_SYLLABLES_FEMALE = {
    "ar", "wen", "ga", "lad", "ri", "el", "lu", "thien", "eo", "wyn",
    "id", "ril", "nim", "ro", "del", "me", "li", "an", "ya", "van",
    "va", "dar", "he", "ru", "mi", "el", "fi", "nd", "uil", "as",
    "ni", "el", "i", "th", "il", "wen", "ri", "an", "non", "a",
    "great", "queen", "ith", "il", "wen", "jo", "el", "la", "ri"

};

const std::vector<std::string> NameGenerator::ORCISH_SYLLABLES = {
    "gash", "zug", "rak", "dur", "gorg",
    "naz", "thok", "krag", "snag", "mok",
    "ulg", "gro", "zag", "thra", "gul",
    "lug", "brok", "urt", "krul", "dug",
    "zog", "mog", "nar", "burz", "gurz",
    "buz", "rug"
};

const std::vector<std::string> NameGenerator::TROLLISH_SYLLABLES = {
    "grum", "bor", "ugh", "throg", "mog",
    "bruk", "dur", "grak", "ur", "log",
    "rag", "gor", "thar", "gro", "bru",
    "mok", "zag", "lur", "frum", "zug",
    "krug", "gra", "nar", "trog", "brog",
    "dro"
};

const std::vector<std::string> NameGenerator::ENTISH_SYLLABLES = {
    "a-lala", "rum", "ta-runda", "la",
    "um", "hoom", "hom", "bor", "oom",
    "lah", "hoom", "tar", "lam", "oom",
    "bur", "rum", "ram", "arunda", "lam",
    "lah", "borom", "turu", "lah", "haloom",
    "ra"
};

const std::vector<std::string> NameGenerator::GAELIC_SYLLABLES = {
    "ba", "lo", "ri", "mo",
    "sa", "na", "te", "da",
    "ra", "la", "ca", "fi",
    "ra", "go", "ve", "ma",
    "ne", "so", "ra", "di",
    "le", "to", "mi", "fa",
    "do", "ma", "na", "li"
};

const std::vector<std::string> NameGenerator::DWARVISH_SYLLABLES_MALE = {
    "thrain", "iron", "foot", "ba", "lin", "stone", "ham", "mer",
    "dwa", "dark", "axe", "thor", "grim", "gold", "beard", "o", "rin",
    "fire", "forge", "du", "rock", "helm", "dor", "heart", "ki", "li",
    "storm", "blade", "bo", "deep", "del", "ver", "grim", "nar", "black", "stone"
};

const std::vector<std::string> NameGenerator::DWARVISH_SYLLABLES_FEMALE = {
    "hel", "ga", "fire", "braid", "hil", "da", "fist", "bry", "nja", "grip",
    "rag", "na", "forge", "tho", "ra", "earth", "shaper", "fre", "ya", "mine",
    "sig", "rid", "flint", "shield", "dri", "fa", "guard", "as", "trid", "thun",
    "der", "ul", "gold", "breaker", "dis", "a", "iron", "heart", "gri", "ma"
};

// Static function to generate a name with random syllables
std::string NameGenerator::generateName(int minSyllables, int maxSyllables, std::vector<std::string> syllables) {
    // Create a random device and a Mersenne Twister random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform distribution for the number of syllables
    std::uniform_int_distribution<> syllableDist(minSyllables, maxSyllables);
    int numSyllables = syllableDist(gen);

    std::string name = "";
    // Create a uniform distribution for the index of components
    std::uniform_int_distribution<> componentDist(0, syllables.size() - 1);
    for (int i = 0; i < numSyllables; ++i) {
        int randomIndex = componentDist(gen);  // Randomly pick a component
        name += syllables[randomIndex];
    }

    name[0] = std::toupper(name[0]);  // Capitalize the first letter
    return name;
}