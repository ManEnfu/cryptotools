#include "autokeyvigenerekeybox_area.hpp"
#include "autokeyvigenere.hpp"
#include "util.hpp"
#include <iostream>

AutoKeyVigenereKeyBoxArea::AutoKeyVigenereKeyBoxArea(
    QWidget* parent, 
    QTextEdit* plaintextbox, 
    QTextEdit* ciphertextbox
) : SingleKeyBoxArea(parent, plaintextbox, ciphertextbox) {}

void AutoKeyVigenereKeyBoxArea::encrypt() {
    std::string p = this->_plain->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string c = autokey_vigenere_encrypt(p, k);
    std::cout << uppercase(p) << " " << k << " " << c << "\n";
    this->_cipher->setText(QString::fromStdString(c));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}

void AutoKeyVigenereKeyBoxArea::decrypt() {
    std::string c = this->_cipher->toPlainText().toStdString();
    std::string k = this->keybox->text().toStdString();
    std::string p = autokey_vigenere_decrypt(c, k);
    std::cout << p << " " << k << " " << c << "\n";
    this->_plain->setText(QString::fromStdString(p));
    this->keybox->setText(QString::fromStdString(filter_alphabet(uppercase(k))));
}
