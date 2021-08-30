#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

std::string vigenere_encrypt(std::string p, std::string k);
std::string vigenere_decrypt(std::string c, std::string k);

class VigenereCipher {
private:
    std::string _key;
public:
    void setkey(std::string k);
    std::string encrypt(std::string p);
    std::string decrypt(std::string c);
};

#endif
