// TextStatistics.h
#ifndef TEXTSTATISTICS_H
#define TEXTSTATISTICS_H

#include <string>

class TextStatistics {
public:
    bool createInputFile();
    void writeStatisticsToFile(const std::string& filename);

    // ��������� ����������
    int getCharacterCount() const;
    int getLineCount() const;
    int getVowelCount() const;
    int getConsonantCount() const;
    int getDigitCount() const;

private:
    std::string text;

    // ������� ��� ���������� ����������
    void calculateCharacterCount();
    void calculateLineCount();
    void calculateVowelAndConsonantCount();
    void calculateDigitCount();
};

#endif
