#ifndef FULLVIGENEREKEYBOX_AREA_H
#define FULLVIGENEREKEYBOX_AREA_H

#include "singlekeybox_area.hpp"

class FullVigenereKeyBoxArea: public SingleKeyBoxArea {
public:
    FullVigenereKeyBoxArea(
        QWidget *parent, 
        QTextEdit *plaintextbox, 
        QTextEdit* ciphertextbox
    );
    void encrypt();
    void decrypt();
};

#endif
