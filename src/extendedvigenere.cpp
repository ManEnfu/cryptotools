
#include "extendedvigenere.h"
#include "util.h"
#include <iostream>

std::string extended_vigenere_encrypt(std::string p, std::string k) {
    std::string c;
    for (std::string::iterator pit = p.begin(), kit = k.begin(); pit != p.end(); pit++, kit++) {
        if (kit == k.end()) kit = k.begin();
        char cc = *pit + *kit;
        c.push_back(cc);
    }
    return c;
}

std::string extended_vigenere_decrypt(std::string c, std::string k) {
    std::string p;
    for (std::string::iterator cit = c.begin(), kit = k.begin(); cit != c.end(); cit++, kit++) {
        if (kit == k.end()) kit = k.begin();
        char pc = *cit - *kit;
        p.push_back(pc);
    }
    return p;
}
