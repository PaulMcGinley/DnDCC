//
// Created by Paul McGinley on 13/09/2024.
//

#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>

class CSVParser {
public:
    CSVParser(const std::string& filename);
    std::vector<std::vector<std::string>> parse();

private:
    std::string filename;
    std::vector<std::string> parseLine(const std::string& line);
    std::string trimQuotes(const std::string& field);
};

#endif // CSV_PARSER_H