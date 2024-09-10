//
// Created by Paul McGinley on 10/09/2024.
//

#ifndef ILEVEL_HPP
#define ILEVEL_HPP

class ILevel {
public:
    virtual ~ILevel() = default;

    int level = 1;
    int experiance = 0;
};

#endif //ILEVEL_HPP
