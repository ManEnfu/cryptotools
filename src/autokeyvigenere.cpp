#include "autokeyvigenere.h"
#include "util.h"
#include <iostream>

std::string autokey_vigenere_encrypt(std::string p, std::string k) {
    uppercase(k);
    filter_alphabet(k);
    uppercase(p);
    filter_alphabet(p);
   
    std::string c;
    for (std::string::iterator pit = p.begin(), kit = k.begin(); pit != p.end(); pit++, kit++) {
        if (kit == k.end()) kit = p.begin();
        char cc = *pit + (*kit - 'A');
        if (cc > 'Z') cc -= 26;
        c.push_back(cc);
    }
    return c;
}

std::string autokey_vigenere_decrypt(std::string c, std::string k) {
    uppercase(k);
    filter_alphabet(k);
    uppercase(c);
    filter_alphabet(c);
   
    std::string p;
    for (std::string::iterator cit = c.begin(), kit = k.begin(); cit != c.end(); cit++, kit++) {
        if (kit == k.end()) kit = p.begin();
        std::cout << *cit << " " << *kit << "\n";
        char pc = *cit - (*kit - 'A');
        if (pc < 'A') pc += 26;
        p.push_back(pc);
    }
    return p;
}
