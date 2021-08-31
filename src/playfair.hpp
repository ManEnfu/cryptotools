#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <string>
#include <vector>

class PlayfairBigramForm {
public:
    std::vector<std::pair<char, char>> bigrams;
    PlayfairBigramForm();
    PlayfairBigramForm(std::string str);
    std::string to_string();
};

std::string playfair_convert_key(std::string k);
std::string playfair_preprocess(std::string p);
std::string playfair_encrypt(std::string p, std::string k);
std::string playfair_decrypt(std::string c, std::string k);

#endif
