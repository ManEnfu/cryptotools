#ifndef FULLVIGENERE_H
#define FULLVIGENERE_H

#include <string>

void print_fvt();
void generate_fvt();
std::string full_vigenere_encrypt(std::string p, std::string k);
std::string full_vigenere_decrypt(std::string c, std::string k);

#endif
