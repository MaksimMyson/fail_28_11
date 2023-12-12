// TextStatistics.h
#ifndef TEXTSTATISTICS_H
#define TEXTSTATISTICS_H

#include <string>

class TextStatistics {
public:
    bool createInputFile();
    void writeStatisticsToFile(const std::string& filename);

    // Отримання статистики
    int getCharacterCount() const;
    int getLineCount() const;
    int getVowelCount() const;
    int getConsonantCount() const;
    int getDigitCount() const;

private:
    std::string text;

    // Функції для обчислення статистики
    void calculateCharacterCount();
    void calculateLineCount();
    void calculateVowelAndConsonantCount();
    void calculateDigitCount();
};

#endif
