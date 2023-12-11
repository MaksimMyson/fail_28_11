#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>

class TextProcessor {
public:
    void getUserInput(const std::string& inputFileName, const std::string& outputFileName);
    void processText(const std::string& inputFileName, const std::string& outputFileName);
};

#endif
