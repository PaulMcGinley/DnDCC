//
// Created by Paul McGinley on 13/09/2024.
//

#ifndef INPUT_H
#define INPUT_H

#include <iostream>

namespace InputUtils {
    void GetInt(int &variable, const std::string &prompt);
    void GetBool(bool &variable, const std::string &prompt);
    void GetFloat(float &variable, const std::string &prompt);
    void GetString(std::string &variable, const std::string &prompt);
}

#endif //INPUT_H
