#include "util.hpp"
#include <iostream>

std::string uppercase(std::string str) {
    std::string ret;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it >= 'a' && *it <= 'z') ret.push_back(*it - 32);
    }
    return ret;
}

std::string filter_alphabet(std::string str) {
    std::string ret;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if ((*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z')) {
            ret.push_back(*it);
        }
    }
    return ret;
}

std::string blockof5(std::string str) {
    std::string ret;
    int j = 0;
    for (auto it = str.begin(); it != str.end(); it++) {
        ret.push_back(*it);
        if (j >= 5) {
            ret.push_back(' ');
            j = 0;
        }
        j++;
    }
    return ret;
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
