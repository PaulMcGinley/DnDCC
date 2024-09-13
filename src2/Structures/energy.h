//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef ENERGY_H
#define ENERGY_H

#include <string>

struct Energy {
    int base;
    int bonus;
    int modifier;
    int remaining;

    int Max() const {
        return base + bonus + modifier;
    };

    int Percent() const {
        return remaining / Max();
    };

    void Add(int amount) {
        remaining += amount;
        if (remaining > Max())
            remaining = Max();
    };

    void Subtract(int amount) {
        remaining -= amount;
        if (remaining < 0)
            remaining = 0;
    };

    // Returns a string representation of the energy Min/Max ( 10/10 )
    std::string ToString() {
        return std::to_string(remaining) + "/" + std::to_string(Max());
    }
};

#endif //ENERGY_H
