#include "FileIO.h"
#include <fstream>
#include <iostream>

std::string FileIO::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
    inputFile.close();
    return content;
}

void FileIO::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << filename << std::endl;
        return;
    }

    outputFile << content;
    outputFile.close();
}
