//
// Created by Paul McGinley on 11/09/2024.
//
#pragma once // Preprocessor directive designed to cause the current source file to be included only once in a single compilation.

enum CharacterClass {
    UNDEFINED       =   0,
    Barbarian       =   1 << 0,  // 1
    Bard            =   1 << 1,  // 2
    Cleric          =   1 << 2,  // 4
    Druid           =   1 << 3,  // 8
    Fighter         =   1 << 4,  // 16
    Monk            =   1 << 5,  // 32
    Paladin         =   1 << 6,  // 64
    Ranger          =   1 << 7,  // 128
    Rogue           =   1 << 8,  // 256
    Sorcerer        =   1 << 9,  // 512
    Warlock         =   1 << 10, // 1024
    Wizard          =   1 << 11  // 2048
};
