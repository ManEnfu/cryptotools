#include "fullvigenere.hpp"
#include "util.hpp"
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <iostream>

#define SEED 897987568

static char fvt[26][26];
static bool fvt_generated = false;

void shuffle(char* arr, size_t n) {
    for (size_t i = n - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        char temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

void generate_fvt() {
    srand(SEED);
    for (size_t i = 0; i < 26; i++) {
        for (size_t j = 0; j < 26; j++) {
            fvt[i][j] = 'A' + j;
        }
        shuffle(fvt[i], 26);
    }
    fvt_generated = true;
}

void print_fvt() {
    for (size_t i = 0; i < 26; i++) {
        std::cout << (char)('a' + i) << " ";
        for (size_t j = 0; j < 26; j++) {
            std::cout << fvt[i][j];
        }
        std::cout << "\n";
    }
}

std::string full_vigenere_encrypt(std::string p, std::string k) {
    if (!fvt_generated) generate_fvt();
    k = uppercase(k);
    k = filter_alphabet(k);
    p = uppercase(p);
    p = filter_alphabet(p);
   
    std::string c;
    for (std::string::iterator pit = p.begin(), kit = k.begin(); 
            pit != p.end(); pit++, kit++) {
        if (kit == k.end()) kit = k.begin();
        char cc = fvt[*kit - 'A'][*pit -'A'];
        c.push_back(cc);
    }
    return c;
}

std::string full_vigenere_decrypt(std::string c, std::string k) {
    if (!fvt_generated) generate_fvt();
    k = uppercase(k);
    k = filter_alphabet(k);
    c = uppercase(c);
    c = filter_alphabet(c);
   
    std::string p;
    for (std::string::iterator cit = c.begin(), kit = k.begin(); 
            cit != c.end(); cit++, kit++) {
        if (kit == k.end()) kit = k.begin();
        char pc = 0;
        for (; fvt[*kit -'A'][pc] != *cit; pc++);
        pc += 'A';
        p.push_back(pc);
    }
    return p;
}
