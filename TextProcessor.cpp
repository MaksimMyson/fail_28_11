// TextProcessor.cpp
#include "TextProcessor.h"
#include <iostream>
#include <fstream>

void TextProcessor::addDashesToFile(const std::string& inputFileName, const std::string& outputFileName) {
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

    std::string line;
    std::string lastLineWithoutSpace;

    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;

        if (line.find(' ') == std::string::npos) {
            // �������� ������� ����� ��� ������
            lastLineWithoutSpace = line;
        }
    }

    // ������ ����� � ������������ ������� ���� ���������� ����� ��� ������ ��� � ���� �����
    if (!lastLineWithoutSpace.empty()) {
        outputFile << "------------" << std::endl;
    }
    else {
        // ���� ���� ����� ��� ������, ������ ����� ���� ���������� �����
        outputFile << std::endl << "------------" << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Processing complete. Results saved in " << outputFileName << std::endl;
}
