#ifndef UTIL_H
#define UTIL_H

#include <string>

void uppercase(std::string& str);
void filter_alphabet(std::string& str);

struct GCDExtData {
    unsigned int gcd;
    int x, y;
};

GCDExtData gcd_extended(int a, int b);

int mod_inverse(int x, int m);

#endif
