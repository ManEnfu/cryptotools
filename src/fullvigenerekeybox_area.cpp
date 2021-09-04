#include "fullvigenerekeybox_area.hpp"
#include "fullvigenere.hpp"
#include "util.hpp"
#include <iostream>

FullVigenereKeyBoxArea::FullVigenereKeyBoxArea(QWidget* parent, QTextEdit* plaintextbox, QTextEdit* ciphertextbox) : SingleKeyBoxArea(parent, plaintextbox, ciphertextbox) {}

void FullVigenereKeyBoxArea::encrypt() {
    std::string p = this->_plain->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string c = full_vigenere_encrypt(p, k);
    std::cout << uppercase(p) << " " << k << " " << c << "\n";
    this->_cipher->setText(QString::fromStdString(c));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}

void FullVigenereKeyBoxArea::decrypt() {
    std::string c = this->_cipher->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string p = full_vigenere_decrypt(c, k);
    std::cout << p << " " << k << " " << c << "\n";
    this->_plain->setText(QString::fromStdString(p));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}
