#include "FileCopy.h"
#include <iostream>
#include <fstream>
#include <string>

void FileCopy::getUserInputAndCopy(const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    std::string line;
    std::cout << "Enter lines (type 'exit' to finish):" << std::endl;

    while (true) {
        std::getline(std::cin, line);

        if (line == "exit") {
            break;
        }

        outputFile << line << std::endl;
    }

    outputFile.close();

    std::cout << "File copying complete. Results saved in " << outputFileName << std::endl;
}
