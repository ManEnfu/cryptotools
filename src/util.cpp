#include "util.hpp"
#include <iostream>

void uppercase(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it >= 'a' && *it <= 'z') *it -= 32;
    }
}

void filter_alphabet(std::string &str) {
    std::string::iterator j = str.begin();
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it < 'A' || (*it > 'Z' && *it < 'a') || *it > 'z') {
            std::string::iterator ot = it--;
            str.erase(ot);
        }
    }
}

GCDExtData gcd_extended(int a, int b) {
    GCDExtData ret;
    if (a == 0) {
        ret.gcd = b;
        ret.x = 0;
        ret.y = 1;
    } else {
        GCDExtData temp = gcd_extended(b % a, a);
        ret.gcd = temp.gcd;
        ret.x = temp.y - (b / a) * temp.x;
        ret.y = temp.x;
    }
    return ret;
}

int mod_inverse(int x, int m) {
    GCDExtData g = gcd_extended(x, m);
    if (g.gcd != 1) {
        return -1;
    }
    return ((g.x % m) + m) % m;
}
