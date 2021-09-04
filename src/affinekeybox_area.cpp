#include "affinekeybox_area.hpp"
#include <QLabel>
#include <QBoxLayout>
#include <iostream>

AffineKeyBoxArea::AffineKeyBoxArea(QWidget* parent, QTextEdit *plaintextbox, QTextEdit *ciphertextbox) : QWidget(parent) {
    this->mbox = new QTextEdit(this);
    this->bbox = new QTextEdit(this);
    this->encrypt_button = new QPushButton("Encrypt", this);
    this->decrypt_button = new QPushButton("Decrypt", this);
    
    QHBoxLayout* layout = new QHBoxLayout(this);
    QVBoxLayout* mlayout = new QVBoxLayout(this);
    QVBoxLayout* blayout = new QVBoxLayout(this);
    QVBoxLayout* rightlayout = new QVBoxLayout(this);
    QLabel* mlabel = new QLabel("m", this);
    QLabel* blabel = new QLabel("b", this);

    mlayout->addWidget(mlabel);
    mlayout->addWidget(mbox);
    blayout->addWidget(blabel);
    blayout->addWidget(bbox);
    rightlayout->addWidget(encrypt_button);
    rightlayout->addWidget(decrypt_button);
    layout->addLayout(mlayout);
    layout->addLayout(blayout);
    layout->addLayout(rightlayout);
    this->setLayout(layout);

    this->_plain = plaintextbox;
    this->_cipher = ciphertextbox;

    connect(this->encrypt_button, &QPushButton::released,
            this, &AffineKeyBoxArea::handle_encrypt_button);
    connect(this->decrypt_button, &QPushButton::released,
            this, &AffineKeyBoxArea::handle_decrypt_button);
}

AffineKeyBoxArea::~AffineKeyBoxArea() {
    //
}

void AffineKeyBoxArea::encrypt() {

}

void AffineKeyBoxArea::decrypt() {

}

void AffineKeyBoxArea::handle_encrypt_button() {
    std::cout << "encrypt\n";
    this->encrypt();
}

void AffineKeyBoxArea::handle_decrypt_button() {
    std::cout << "decrypt\n";
    this->decrypt();
}
