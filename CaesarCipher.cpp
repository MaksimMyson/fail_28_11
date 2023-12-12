#include "CaesarCipher.h"

std::string CaesarCipher::encrypt(const std::string& text, int key) {
    std::string result = text;

    for (char& ch : result) {
        if (std::isalpha(ch)) {
            char base = (std::isupper(ch)) ? 'A' : 'a';
            ch = base + (ch - base + key) % 26;
        }
    }

    return result;
}
