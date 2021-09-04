#include "playfairkeybox_area.hpp"
#include "playfair.hpp"
#include "util.hpp"
#include <iostream>

PlayfairKeyBoxArea::PlayfairKeyBoxArea(QWidget* parent, QTextEdit* plaintextbox, QTextEdit* ciphertextbox) : SingleKeyBoxArea(parent, plaintextbox, ciphertextbox) {}

void PlayfairKeyBoxArea::encrypt() {
    std::string p = this->_plain->toPlainText().toStdString();
    std::string k = this->keybox->toPlainText().toStdString();
    std::string c = playfair_encrypt(p, k);
    std::cout << uppercase(p) << " " << k << " " << c << "\n";
    this->_cipher->setText(QString::fromStdString(c));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}

void PlayfairKeyBoxArea::decrypt() {
    std::string c = this->_cipher->toPlainText().toStdString();
    std::string k = this->keybox->toPlainText().toStdString();
    std::string p = playfair_decrypt(c, k);
    std::cout << p << " " << k << " " << c << "\n";
    this->_plain->setText(QString::fromStdString(p));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}
