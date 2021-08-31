#ifndef AFFINE_H
#define AFFINE_H

#include <string>

std::string affine_encrypt(std::string p, int m, int b);
std::string affine_decrypt(std::string c, int m, int b);

#endif
