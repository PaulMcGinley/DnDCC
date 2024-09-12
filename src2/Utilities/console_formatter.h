//
// Created by Paul McGinley on 12/09/2024.
//

#ifndef CONSOLE_FORMATTER_H
#define CONSOLE_FORMATTER_H
#include <iomanip>

class ConsoleFormat {
public:
    // Reset all formatting
    static constexpr const char* RESET = "\033[0m";

    // Text colors
    static constexpr const char* BLACK = "\033[30m";
    static constexpr const char* RED = "\033[31m";
    static constexpr const char* GREEN = "\033[32m";
    static constexpr const char* YELLOW = "\033[33m";
    static constexpr const char* BLUE = "\033[34m";
    static constexpr const char* MAGENTA = "\033[35m";
    static constexpr const char* CYAN = "\033[36m";
    static constexpr const char* WHITE = "\033[37m";

    // Background colors
    static constexpr const char* BG_BLACK = "\033[40m";
    static constexpr const char* BG_RED = "\033[41m";
    static constexpr const char* BG_GREEN = "\033[42m";
    static constexpr const char* BG_YELLOW = "\033[43m";
    static constexpr const char* BG_BLUE = "\033[44m";
    static constexpr const char* BG_MAGENTA = "\033[45m";
    static constexpr const char* BG_CYAN = "\033[46m";
    static constexpr const char* BG_WHITE = "\033[47m";

    // Text formatting
    static constexpr const char* BOLD = "\033[1m";
    static constexpr const char* UNDERLINE = "\033[4m";
    static constexpr const char* REVERSED = "\033[7m";

    // Print text aligned to the right
    static void PrintRightAligned(const std::string& text, const int width = 153) {
        std::cout << std::setw(width) << text << std::endl;
    }

    static void ClearConsole() {
        std::cout << "\033[2J\033[1;1H";
        std::cout << std::flush;
    }
};


#endif //CONSOLE_FORMATTER_H
