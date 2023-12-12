#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

class CaesarCipher {
public:
    std::string encrypt(const std::string& text, int key);
};

#endif
