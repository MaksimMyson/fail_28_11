#include "FileIO.h"
#include "CaesarCipher.h"
#include <iostream>

int main() {
    FileIO fileIO;
    CaesarCipher caesarCipher;

    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    int key = 3; // ���� ����� ������

    // �������� ����������� ������ �����
    std::cout << "Enter the text to be encrypted:\n";
    std::string originalText;
    std::getline(std::cin, originalText);

    // �������� �������� ����� � ���� "input.txt"
    fileIO.writeToFile(inputFileName, originalText);

    // ������� ����� � �����
    originalText = fileIO.readFromFile(inputFileName);

    // ��������� �����
    std::string encryptedText = caesarCipher.encrypt(originalText, key);

    // �������� ������������ ����� � ���� "output.txt"
    fileIO.writeToFile(outputFileName, encryptedText);

    std::cout << "Encryption complete. Check the output file: " << outputFileName << std::endl;

    return 0;
}
