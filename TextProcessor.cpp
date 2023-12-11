#include "TextProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>

void TextProcessor::getUserInput(const std::string& inputFileName, const std::string& outputFileName) {
    std::ofstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }

    std::string userInput;
    std::cout << "Enter words (type 'exit' to finish):" << std::endl;

    while (true) {
        std::cin >> userInput;

        if (userInput == "exit") {
            break;
        }

        inputFile << userInput << " ";
    }

    inputFile.close();

    processText(inputFileName, outputFileName);
}

void TextProcessor::processText(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        inputFile.close();
        return;
    }

    std::string word;
    std::cout << "Words with 7 or more letters: ";

    while (inputFile >> word) {
        if (word.length() >= 7) {
            outputFile << word << " ";
            std::cout << word << " ";
        }
    }

    std::cout << std::endl;

    inputFile.close();
    outputFile.close();

    std::cout << "Text processing complete. Results saved in " << outputFileName << std::endl;
}
