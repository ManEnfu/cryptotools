#ifndef PLAYFAIRKEYBOX_AREA_H
#define PLAYFAIRKEYBOX_AREA_H

#include "qtextedit.h"
#include "singlekeybox_area.hpp"

class PlayfairKeyBoxArea: public SingleKeyBoxArea {
public:
    PlayfairKeyBoxArea(QWidget *parent, QTextEdit *plaintextbox, QTextEdit* ciphertextbox);
    void encrypt();
    void decrypt();
};

#endif
