#include "fullvigenere.h"
#include "vigenere.h"
#include "autokeyvigenere.h"
#include "playfair.h"
#include "util.h"
#include <iostream>

int main() {

    std::string plain("attackatdawn");
    std::string key("lemon");
    std::string key2("queenly");

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
    
    std::cout << "\n";
    generate_fvt();
    print_fvt();
    std::cout << "\n";

    std::string crypt2 = full_vigenere_encrypt(plain, key2);
    std::cout << plain << "\n";
    std::cout << key2 << "\n";
    std::cout << crypt2 << "\n";
    std::cout << full_vigenere_decrypt(crypt2, key2) << "\n";

    std::string plt("temuj jbu nanti malam");
    std::cout << plt << "\n";
    PlayfairBigramForm pbf(plt);
    std::cout << pbf.to_string() << "\n";

    std::string pk("jalanganeshasepuluh");
    std::cout << pk << "\n";
    pk = playfair_convert_key(pk);
    std::cout << pk << "\n";

    std::string pke = playfair_encrypt(plt, pk);
    std::cout << pke << "\n";
    std::cout << playfair_decrypt(pke, pk) << "\n";


}
