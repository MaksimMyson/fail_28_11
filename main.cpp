#include "TextStatistics.h"
#include <iostream>

int main() {
    TextStatistics textStats;

    // Створення файлу "input.txt" та запис даних у нього
    if (textStats.createInputFile()) {
        // Отримуємо та виводимо статистику
        std::cout << "Character count: " << textStats.getCharacterCount() << std::endl;
        std::cout << "Line count: " << textStats.getLineCount() << std::endl;
        std::cout << "Vowel count: " << textStats.getVowelCount() << std::endl;
        std::cout << "Consonant count: " << textStats.getConsonantCount() << std::endl;
        std::cout << "Digit count: " << textStats.getDigitCount() << std::endl;

        // Записуємо статистику у файл "output.txt"
        textStats.writeStatisticsToFile("output.txt");
    }
    else {
        std::cerr << "Error creating input file: input.txt" << std::endl;
    }

    return 0;
}
