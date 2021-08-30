#include "vigenere.h"
#include "util.h"
#include <iostream>

int main() {

    std::string plain("attackatdawn");
    std::string key("lemon");

    std::string asd("aAsfkkG a22 A/s");
    
    std::cout << asd << "\n";
    uppercase(asd);
    std::cout << asd << "\n";
    filter_alphabet(asd);
    std::cout << asd << "\n";

    std::string crypt = vigenere_encrypt(plain, key);
    std::cout << plain << "\n";
    std::cout << key << "\n";
    std::cout << crypt << "\n";
    std::cout << vigenere_decrypt(crypt, key) << "\n";

    

}
