#include "TextStatistics.h"
#include <iostream>

int main() {
    TextStatistics textStats;

    // ��������� ����� "input.txt" �� ����� ����� � �����
    if (textStats.createInputFile()) {
        // �������� �� �������� ����������
        std::cout << "Character count: " << textStats.getCharacterCount() << std::endl;
        std::cout << "Line count: " << textStats.getLineCount() << std::endl;
        std::cout << "Vowel count: " << textStats.getVowelCount() << std::endl;
        std::cout << "Consonant count: " << textStats.getConsonantCount() << std::endl;
        std::cout << "Digit count: " << textStats.getDigitCount() << std::endl;

        // �������� ���������� � ���� "output.txt"
        textStats.writeStatisticsToFile("output.txt");
    }
    else {
        std::cerr << "Error creating input file: input.txt" << std::endl;
    }

    return 0;
}
