#include "autokeyvigenere.hpp"
#include "util.hpp"
#include <iostream>

std::string autokey_vigenere_encrypt(std::string p, std::string k) {
    k = uppercase(k);
    k = filter_alphabet(k);
    p = uppercase(p);
    p = filter_alphabet(p);
   
    std::string c;
    for (std::string::iterator pit = p.begin(), kit = k.begin(); 
            pit != p.end(); pit++, kit++) {
        if (kit == k.end()) kit = p.begin();
        char cc = *pit + (*kit - 'A');
        if (cc < 'A') cc += 26;
        if (cc > 'Z') cc -= 26;
        c.push_back(cc);
    }
    return c;
}

std::string autokey_vigenere_decrypt(std::string c, std::string k) {
    k = uppercase(k);
    k = filter_alphabet(k);
    c = uppercase(c);
    c = filter_alphabet(c);
    size_t j = 0;
    bool use_p = false;
   
    std::string p;
    for (std::string::iterator cit = c.begin(); cit != c.end(); cit++, j++) {
        if (j == k.size() && !use_p) {
            j = 0;
            use_p = true;
        }
        char kc = use_p ? p[j] : k[j]; 
        char pc = *cit - (kc - 'A');
        if (pc < 'A') pc += 26;
        if (pc > 'Z') pc -= 26;

        p.push_back(pc);
    }
    return p;
}
