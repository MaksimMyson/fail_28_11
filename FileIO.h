#ifndef FILEIO_H
#define FILEIO_H

#include <string>

class FileIO {
public:
    std::string readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename, const std::string& content);
};

#endif
