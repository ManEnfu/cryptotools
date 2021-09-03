#ifndef UTIL_H
#define UTIL_H

#include <string>

std::string uppercase(std::string str);
std::string filter_alphabet(std::string str);
std::string blockof5(std::string str);

struct GCDExtData {
    unsigned int gcd;
    int x, y;
};

GCDExtData gcd_extended(int a, int b);

int mod_inverse(int x, int m);

#endif
