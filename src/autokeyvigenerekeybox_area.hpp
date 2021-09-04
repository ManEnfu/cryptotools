#ifndef AUTOKEYVIGENEREKEYBOX_AREA_H
#define AUTOKEYVIGENEREKEYBOX_AREA_H

#include "qtextedit.h"
#include "singlekeybox_area.hpp"

class AutoKeyVigenereKeyBoxArea: public SingleKeyBoxArea {
public:
    AutoKeyVigenereKeyBoxArea(QWidget *parent, QTextEdit *plaintextbox, QTextEdit* ciphertextbox);
    void encrypt();
    void decrypt();
};

#endif
