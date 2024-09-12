//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef STAT_H
#define STAT_H

struct Stat {
    int base;
    int bonus;
    int modifier;

    // Calculate the value of the stat
    // This is fine... Addition is a fast operation... This is not a problem.
    int value() {
        base + bonus + modifier;
    };
    // Having a single variable to store the value of the stat may cause issues
    // If the value of the stat is changed, the modifier will not be updated,
    // would need to make sure I do that myself. If I mess up then boom! Nightmare!
    // Just leave it as a function, it's not a problem.
};

#endif //STAT_H
