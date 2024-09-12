//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef IDRAW_H
#define IDRAW_H

#include <iostream>
#include <string>

class IDraw {
public:
    std::string Image;
    void Create(std::string &image) {
        Image = image;
    }
    void Draw() {
        std::cout << Image << std::endl;
    }
};

#endif //IDRAW_H
