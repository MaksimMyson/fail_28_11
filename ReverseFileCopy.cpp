#include "ReverseFileCopy.h"
#include <iostream>
#include <fstream>
#include <stack>

void ReverseFileCopy::copyReversedFile(const std::string& outputFileName) {
    std::stack<std::string> words;

    // Введення слова з клавіатури
    std::string word;
    std::cout << "Enter words (type 'exit' to finish input):\n";
    while (true) {
        std::cin >> word;

        // Перевірка на вихід
        if (word == "exit") {
            break;
        }

        words.push(word);
    }

    // Відкриваємо вихідний файл для запису в нього слів у зворотньому порядку
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    // Виводимо слова в зворотньому порядку у вихідний файл
    while (!words.empty()) {
        outputFile << words.top() << std::endl;
        words.pop();
    }

    outputFile.close();

    std::cout << "File writing complete. Results saved in " << outputFileName << std::endl;
}
