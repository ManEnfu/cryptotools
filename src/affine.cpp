#include "affine.hpp"
#include "util.hpp"

std::string affine_encrypt(std::string p, int m, int b) {
    p = uppercase(p);
    p = filter_alphabet(p);
    std::string ret;
    for (auto it = p.begin(); it != p.end(); it++) {
        int vp = *it - 'A';
        int vc = (m * vp + b) % 26;
        ret.push_back(vc + 'A');
    }
    return ret;
}

std::string affine_decrypt(std::string c, int m, int b) {
    c = uppercase(c);
    c = filter_alphabet(c);
    std::string ret;
    for (auto it = c.begin(); it != c.end(); it++) {
        int vc = *it - 'A';
        int vp = ((mod_inverse(m, 26) * (vc - b)) % 26 + 26) % 26;
        ret.push_back(vp + 'A');
    }
    return ret;
}

