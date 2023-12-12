#include "TextComparator.h"
#include <iostream>
#include <fstream>

int main() {
    // Створення файлу "input.txt" та запис даних у нього
    std::ofstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error creating input file." << std::endl;
        return 1;
    }

    std::cout << "Enter text for input.txt (type 'end' on a new line to finish):" << std::endl;
    std::string line;
    while (std::getline(std::cin, line) && line != "end") {
        inputFile << line << std::endl;
    }

    inputFile.close();

    // Порівняння файлів "input.txt" та "output.txt"
    TextComparator textComparator;
    textComparator.compareFiles("input.txt", "output.txt");

    return 0;
}
