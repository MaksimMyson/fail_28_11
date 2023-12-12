#include "FileIO.h"
#include "CaesarCipher.h"
#include <iostream>

int main() {
    FileIO fileIO;
    CaesarCipher caesarCipher;

    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    int key = 3; // ключ шифру Цезаря

    // Запитуємо користувача ввести текст
    std::cout << "Enter the text to be encrypted:\n";
    std::string originalText;
    std::getline(std::cin, originalText);

    // Записуємо введений текст у файл "input.txt"
    fileIO.writeToFile(inputFileName, originalText);

    // Зчитуємо текст з файлу
    originalText = fileIO.readFromFile(inputFileName);

    // Зашифруємо текст
    std::string encryptedText = caesarCipher.encrypt(originalText, key);

    // Записуємо зашифрований текст у файл "output.txt"
    fileIO.writeToFile(outputFileName, encryptedText);

    std::cout << "Encryption complete. Check the output file: " << outputFileName << std::endl;

    return 0;
}
