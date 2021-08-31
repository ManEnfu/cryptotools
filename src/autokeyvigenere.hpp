#ifndef AUTOKEYVIGENERE_H
#define AUTOKEYVIGENERE_H

#include <string>

std::string autokey_vigenere_encrypt(std::string p, std::string k);
std::string autokey_vigenere_decrypt(std::string c, std::string k);

#endif
