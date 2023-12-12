// TextComparator.cpp
#include "TextComparator.h"
#include <iostream>
#include <fstream>

void TextComparator::compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream inputFile1(file1);
    std::ifstream inputFile2(file2);

    if (!inputFile1.is_open()) {
        std::cerr << "Error opening file: " << file1 << std::endl;
        return;
    }

    if (!inputFile2.is_open()) {
        std::cerr << "Error opening file: " << file2 << std::endl;
        inputFile1.close();
        return;
    }

    std::string line1, line2;
    int lineNumber = 0;

    while (std::getline(inputFile1, line1) && std::getline(inputFile2, line2)) {
        lineNumber++;

        if (line1 != line2) {
            std::cout << "Lines differ at line " << lineNumber << ":" << std::endl;
            std::cout << file1 << ": " << line1 << std::endl;
            std::cout << file2 << ": " << line2 << std::endl;
            return;
        }
    }

    if (std::getline(inputFile1, line1) || std::getline(inputFile2, line2)) {
        std::cout << "Files have different lengths." << std::endl;
        std::cout << file1 << ": " << line1 << std::endl;
        std::cout << file2 << ": " << line2 << std::endl;
    }
    else {
        std::cout << "Files are identical." << std::endl;
    }

    inputFile1.close();
    inputFile2.close();
}
