#include "playfair.hpp"
#include "util.hpp"
#include <cstddef>
#include <iostream>

PlayfairBigramForm::PlayfairBigramForm() {}

PlayfairBigramForm::PlayfairBigramForm(std::string str) {
    str = uppercase(str);
    str = filter_alphabet(str);
    std::string prep = playfair_preprocess(str);
    for (auto it = prep.begin(); it != prep.end(); it++) {
        char c1 = *it;
        char c2 = *(++it);
        this->bigrams.push_back(std::pair<char, char>(c1, c2));
    }
}

std::string PlayfairBigramForm::to_string() {
    std::string ret;
    for (auto it = this->bigrams.begin(); it != this->bigrams.end(); it++) {
        ret.push_back(it->first);
        ret.push_back(it->second);
        if (it + 1 != this->bigrams.end()) ret.push_back(' ');
    }
    return ret;
}

std::string playfair_convert_key(std::string k) {
    std::string ret;
    k = uppercase(k);
    k = filter_alphabet(k);
    for (std::string::iterator kit = k.begin(); kit !=k.end(); kit++) {
        if (*kit != 'J') {
            if (ret.find(*kit) == std::string::npos) {
                ret.push_back(*kit);
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J') {
            if (ret.find(c) == std::string::npos) {
                ret.push_back(c);
            }
        }
    }
    return ret;
}

std::string playfair_preprocess(std::string p) {
    std::string ret;
    size_t retsize = 0;
    for (auto it = p.begin(); it != p.end(); it++) {
        char c = *it;
        if (c == 'J') c = 'I';
        if (ret.size() % 2 != 0 && ret.back() == c) ret.push_back('X');
        ret.push_back(c);
        
    }
    if (ret.size() %2 != 0) ret.push_back('X');
    return ret;
}

std::pair<char, char> playfair_encrypt_pair(std::pair<char, char> bigram, std::string k) {
    size_t idx1 = k.find(bigram.first);
    size_t col1 = idx1 % 5;
    size_t row1 = idx1 / 5;
    size_t idx2 = k.find(bigram.second);
    size_t col2 = idx2 % 5;
    size_t row2 = idx2 / 5;

    std::pair<char, char> ret;

    if (col1 == col2) {
        ret.first = k[((row1 + 1) % 5) * 5 + col1];
        ret.second = k[((row2 + 1) % 5) * 5 + col2];
    } else if (row1 == row2) {
        ret.first = k[row1 * 5 + ((col1 + 1) % 5)];
        ret.second = k[row2 * 5 + ((col2 + 1) % 5)];
    } else {
        ret.first = k[row1 * 5 + col2];
        ret.second = k[row2 * 5 + col1];
    }
    return ret;
}

std::pair<char, char> playfair_decrypt_pair(std::pair<char, char> bigram, std::string k) {
    size_t idx1 = k.find(bigram.first);
    size_t col1 = idx1 % 5;
    size_t row1 = idx1 / 5;
    size_t idx2 = k.find(bigram.second);
    size_t col2 = idx2 % 5;
    size_t row2 = idx2 / 5;

    std::pair<char, char> ret;

    if (col1 == col2) {
        ret.first = k[((row1 + 4) % 5) * 5 + col1];
        ret.second = k[((row2 + 4) % 5) * 5 + col2];
    } else if (row1 == row2) {
        ret.first = k[row1 * 5 + ((col1 + 4) % 5)];
        ret.second = k[row2 * 5 + ((col2 + 4) % 5)];
    } else {
        ret.first = k[row1 * 5 + col2];
        ret.second = k[row2 * 5 + col1];
    }
    return ret;
}

std::string playfair_encrypt(std::string p, std::string k) {
    k = playfair_convert_key(k);
    PlayfairBigramForm pb(p);
    PlayfairBigramForm cb;
    for (auto it = pb.bigrams.begin(); it != pb.bigrams.end(); it++) {
       cb.bigrams.push_back(playfair_encrypt_pair(*it, k)); 
    }
    return cb.to_string();
}

std::string playfair_decrypt(std::string c, std::string k) {
    k = playfair_convert_key(k);
    PlayfairBigramForm cb(c);
    PlayfairBigramForm pb;
    for (auto it = cb.bigrams.begin(); it != cb.bigrams.end(); it++) {
       pb.bigrams.push_back(playfair_decrypt_pair(*it, k)); 
    }
    return pb.to_string();
}
