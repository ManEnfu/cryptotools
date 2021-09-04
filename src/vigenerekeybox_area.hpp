#ifndef VIGENEREKEYBOX_AREA_H
#define VIGENEREKEYBOX_AREA_H

#include "qtextedit.h"
#include "singlekeybox_area.hpp"

class VigenereKeyBoxArea: public SingleKeyBoxArea {
public:
    VigenereKeyBoxArea(QWidget *parent, QTextEdit *plaintextbox, QTextEdit* ciphertextbox);
    void encrypt();
    void decrypt();
};

#endif
