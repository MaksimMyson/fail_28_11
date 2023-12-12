// TextStatistics.cpp
#include "TextStatistics.h"
#include <iostream>
#include <fstream>
#include <cctype>

bool TextStatistics::createInputFile() {
    std::ofstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        return false;
    }

    // Записуємо текст у файл
    inputFile << "Hello, this is a sample text." << std::endl;
    // Додайте інші дані, які вам потрібні

    inputFile.close();
    return true;
}

void TextStatistics::writeStatisticsToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        // Записуємо статистику у файл
        outputFile << "Character count: " << getCharacterCount() << std::endl;
        outputFile << "Line count: " << getLineCount() << std::endl;
        outputFile << "Vowel count: " << getVowelCount() << std::endl;
        outputFile << "Consonant count: " << getConsonantCount() << std::endl;
        outputFile << "Digit count: " << getDigitCount() << std::endl;

        outputFile.close();
    }
    else {
        std::cerr << "Error opening output file: " << filename << std::endl;
    }
}

int TextStatistics::getCharacterCount() const {
    return text.length();
}

int TextStatistics::getLineCount() const {
    int count = 1; // Мінімум один рядок, навіть якщо текст порожній
    for (char ch : text) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

int TextStatistics::getVowelCount() const {
    int count = 0;
    for (char ch : text) {
        if (std::isalpha(ch) && (std::tolower(ch) == 'a' || std::tolower(ch) == 'e' ||
            std::tolower(ch) == 'i' || std::tolower(ch) == 'o' ||
            std::tolower(ch) == 'u')) {
            count++;
        }
    }
    return count;
}

int TextStatistics::getConsonantCount() const {
    int count = 0;
    for (char ch : text) {
        if (std::isalpha(ch) && !getVowelCount()) {
            count++;
        }
    }
    return count;
}

int TextStatistics::getDigitCount() const {
    int count = 0;
    for (char ch : text) {
        if (std::isdigit(ch)) {
            count++;
        }
    }
    return count;
}
