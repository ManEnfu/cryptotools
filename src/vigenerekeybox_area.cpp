#include "vigenerekeybox_area.hpp"
#include "vigenere.hpp"
#include "util.hpp"
#include <iostream>

VigenereKeyBoxArea::VigenereKeyBoxArea(QWidget* parent, QTextEdit* plaintextbox, QTextEdit* ciphertextbox) : SingleKeyBoxArea(parent, plaintextbox, ciphertextbox) {}

void VigenereKeyBoxArea::encrypt() {
    std::string p = this->_plain->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string c = vigenere_encrypt(p, k);
    std::cout << uppercase(p) << " " << k << " " << c << "\n";
    this->_cipher->setText(QString::fromStdString(c));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}

void VigenereKeyBoxArea::decrypt() {
    std::string c = this->_cipher->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string p = vigenere_decrypt(c, k);
    std::cout << p << " " << k << " " << c << "\n";
    this->_plain->setText(QString::fromStdString(p));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}
