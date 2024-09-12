//
// Created by Paul McGinley on 11/09/2024.
//
#pragma once // Preprocessor directive designed to cause the current source file to be included only once in a single compilation.

enum CharacterClass {
    UNDEFINED       =   0,
    Barbarian       =   1,
    Bard            =   2,
    Cleric          =   4,
    Druid           =   8,
    Fighter         =   16,
    Monk            =   32,
    Paladin         =   64,
    Ranger          =   128,
    Rogue           =   256,
    Sorcerer        =   512,
    Warlock         =   1024,
    Wizard          =   2048
};
