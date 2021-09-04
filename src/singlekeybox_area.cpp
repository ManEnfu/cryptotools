#include "singlekeybox_area.hpp"
#include "qpushbutton.h"
#include <QLabel>
#include <QBoxLayout>
#include <iostream>

SingleKeyBoxArea::SingleKeyBoxArea(QWidget* parent, QTextEdit *plaintextbox, QTextEdit *ciphertextbox) : QWidget(parent) {
    this->keybox = new QLineEdit(this);
    this->encrypt_button = new QPushButton("Encrypt", this);
    this->decrypt_button = new QPushButton("Decrypt", this);
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* leftlayout = new QHBoxLayout(this);
    QHBoxLayout* rightlayout = new QHBoxLayout(this);
    QLabel* label = new QLabel("Key", this);

    leftlayout->addWidget(label);
    leftlayout->addWidget(keybox);
    rightlayout->addWidget(encrypt_button);
    rightlayout->addWidget(decrypt_button);
    layout->addLayout(leftlayout);
    layout->addStretch();
    layout->addLayout(rightlayout);
    this->setLayout(layout);

    this->_plain = plaintextbox;
    this->_cipher = ciphertextbox;

    connect(this->encrypt_button, &QPushButton::released,
            this, &SingleKeyBoxArea::handle_encrypt_button);
    connect(this->decrypt_button, &QPushButton::released,
            this, &SingleKeyBoxArea::handle_decrypt_button);
}

SingleKeyBoxArea::~SingleKeyBoxArea() {
    //
}

void SingleKeyBoxArea::handle_encrypt_button() {
    std::cout << "encrypt\n";
    this->encrypt();
}

void SingleKeyBoxArea::handle_decrypt_button() {
    std::cout << "decrypt\n";
    this->decrypt();
}
