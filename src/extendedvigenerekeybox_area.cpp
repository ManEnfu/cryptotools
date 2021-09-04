#include "extendedvigenerekeybox_area.hpp"
#include "extendedvigenere.hpp"
#include "util.hpp"
#include <iostream>
#include <fstream>
#include <QBoxLayout>
#include <QFileDialog>

ExtendedVigenereKeyBoxArea::ExtendedVigenereKeyBoxArea(QWidget* parent, QTextEdit* plaintextbox, QTextEdit* ciphertextbox) : QWidget(parent) {
    this->keybox = new QLineEdit(this);
    this->open_button = new QPushButton("Open", this);
    this->encrypt_button = new QPushButton("Encrypt and Save", this);
    this->decrypt_button = new QPushButton("Decrypt and Save", this);
    this->filename_label = new QLabel("Select File...");
    this->filename = std::string("");
    
    QLabel* key_label = new QLabel("Key", this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* flayout = new QHBoxLayout(this);
    QHBoxLayout* klayout = new QHBoxLayout(this);
    QHBoxLayout* olayout = new QHBoxLayout(this);

    flayout->addWidget(open_button);
    flayout->addWidget(filename_label);
    klayout->addWidget(key_label);
    klayout->addWidget(keybox);
    olayout->addWidget(encrypt_button);
    olayout->addWidget(decrypt_button);
    layout->addLayout(flayout);
    layout->addLayout(klayout);
    layout->addStretch();
    layout->addLayout(olayout);
    this->setLayout(layout);
    
    this->_plain = plaintextbox;
    this->_cipher = ciphertextbox;
    connect(this->open_button, &QPushButton::released,
            this, &ExtendedVigenereKeyBoxArea::handle_open_button);
    connect(this->encrypt_button, &QPushButton::released,
            this, &ExtendedVigenereKeyBoxArea::handle_encrypt_button);
    connect(this->decrypt_button, &QPushButton::released,
            this, &ExtendedVigenereKeyBoxArea::handle_decrypt_button);

}

ExtendedVigenereKeyBoxArea::~ExtendedVigenereKeyBoxArea() {
    //
}

void ExtendedVigenereKeyBoxArea::encrypt() {
    if (!this->filename.compare("")) return;
    std::ifstream f;
    f.open(this->filename);
    if (!f.is_open()) return;
    std::string p;
    char ch;
    while(f.get(ch))
        p.push_back(ch);
    f.close();
    std::cout << "done reading\n";
    std::string k = this->keybox->text().toStdString();
    std::string c = extended_vigenere_encrypt(p, k);
    std::cout << "done encrypting\n";
    this->save(c);
}

void ExtendedVigenereKeyBoxArea::decrypt() {
    if (!this->filename.compare("")) return;
    std::ifstream f;
    f.open(this->filename);
    if (!f.is_open()) return;
    std::string c;
    char ch;
    while(f.get(ch))
        c.push_back(ch);
    f.close();
    std::string k = this->keybox->text().toStdString();
    std::string p = extended_vigenere_decrypt(c, k);
    this->save(p);
}

void ExtendedVigenereKeyBoxArea::save(std::string str) {
    QString fname = QFileDialog::getSaveFileName(this, tr("Open File"), ".");
    if (fname.compare("")) {
        /* std::cout << "save " << filename.toStdString() << "\n"; */
        std::ofstream f;
        f.open(fname.toStdString());
        if (!f.is_open()) return;
        /* std::string str = this->textbox->toPlainText().toStdString(); */
        for (auto it = str.begin(); it != str.end(); it++)
            f.put(*it);
        f.close();
    }
}

void ExtendedVigenereKeyBoxArea::handle_open_button() {
    QString fname = QFileDialog::getOpenFileName(this, tr("Open File"), ".");
    if (fname.compare("")) {
        this->filename = fname.toStdString();
        this->filename_label->setText(fname);
        /* std::cout << "open " << filename.toStdString() << "\n"; */
        /* std::ifstream f; */
        /* f.open(filename.toStdString()); */
        /* if (!f.is_open()) return; */
        /* QString newstr; */
        /* char c; */
        /* while(f.get(c)) */
        /*     newstr.push_back(c); */
        /* f.close(); */
    }
}

void ExtendedVigenereKeyBoxArea::handle_encrypt_button() {
    std::cout << "encrypt\n";
    this->encrypt();
}

void ExtendedVigenereKeyBoxArea::handle_decrypt_button() {
    std::cout << "decrypt\n";
    this->decrypt();
}
