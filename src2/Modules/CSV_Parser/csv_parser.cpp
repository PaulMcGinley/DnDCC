//
// Created by Paul McGinley on 13/09/2024.
//

#include "csv_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

CSVParser::CSVParser(const std::string& filename) : filename(filename) {}                                             // Constructor

// Parse the CSV file
std::vector<std::vector<std::string>> CSVParser::parse() {

    std::vector<std::vector<std::string>> data;                                                                         // Create a vector of vectors to hold the parsed data
    std::ifstream file(filename);                                                                                       // Open the file
    std::string line;                                                                                                   // Create a string to hold each line of the file

    bool header = true;
    // Read each line of the file
    while (std::getline(file, line)) {
        // Skip the header
        if (header) {
            header = false;
            continue;
        }
        data.push_back(parseLine(line));                                                                              // Parse the line and add it to the data vector
    }

    return data;
}

// Parse a line of the CSV file
std::vector<std::string> CSVParser::parseLine(const std::string& line) {

    std::vector<std::string> result;                                                                                    // Create a vector of strings to hold the parsed fields
    std::istringstream stream(line);                                                                                    // Create a string stream from the line so we can iterate through each character
    std::string field;                                                                                                  // Create a string to hold the current field
    bool inQuotes = false;                                                                                              // Create a flag to track if we are inside quotes
    std::string currentField;                                                                                           // Create a string to hold the current field

    constexpr char delimiter = ',';                                                                                     // Set the delimiter to a comma

    // Iterate through each character in the line
    for (char ch : line) {
        if (ch == '"') {                                                                                                // Check if the character is a quote
            inQuotes = !inQuotes;                                                                                       // Toggle the inQuotes flag
            currentField += ch;                                                                                         // Add the quote to the current field
        } else if (ch == delimiter && !inQuotes) {                                                                      // Check if the character is a comma and we are not inside quotes
            result.push_back(trimQuotes(currentField));                                                               // Add the current field to the result vector
            currentField.clear();                                                                                       // Clear the current field
        } else {
            currentField += ch;                                                                                         // Add the character to the current field
        }
    }

    result.push_back(trimQuotes(currentField));                                                                       // Add the last field to the result vector
    return result;                                                                                                      // Return the vector of parsed fields
}

// Trim quotes from a field
std::string CSVParser::trimQuotes(const std::string& field) {

    if (field.size() >= 2 && field.front() == '"' && field.back() == '"') {                                             // Check if the field is enclosed in quotes
        std::string trimmed = field.substr(1, field.size() - 2);                                                  // Trim the quotes
        std::string result;                                                                                             // Create a string to hold the result

        // Iterate through the trimmed string
        for (size_t i = 0; i < trimmed.size(); ++i) {
            if (trimmed[i] == '"' && i + 1 < trimmed.size() && trimmed[i + 1] == '"') {                                 // Check for escaped quotes ("")
                result += '"';                                                                                          // Add a single quote to the result
                ++i;                                                                                                    // Skip the next quote
            } else {
                result += trimmed[i];                                                                                   // Add the character to the result
            }
        }
        return result;                                                                                                  // Return the trimmed field
    }

    // If the field is not enclosed in quotes, return it as is
    return field;                                                                                                     // Return the field as is
}