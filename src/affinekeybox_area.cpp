#include "affinekeybox_area.hpp"
#include "affine.hpp"
#include <QLabel>
#include <QBoxLayout>
#include <iostream>


AffineKeyBoxArea::AffineKeyBoxArea(
    QWidget* parent, 
    QTextEdit *plaintextbox, 
    QTextEdit *ciphertextbox
) : QWidget(parent) {
    this->mbox = new QLineEdit(this);
    this->bbox = new QLineEdit(this);
    this->encrypt_button = new QPushButton("Encrypt", this);
    this->decrypt_button = new QPushButton("Decrypt", this);
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* mlayout = new QHBoxLayout(this);
    QHBoxLayout* blayout = new QHBoxLayout(this);
    QHBoxLayout* rightlayout = new QHBoxLayout(this);
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
    layout->addStretch();
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
    bool ok;
    int m = this->mbox->text().toInt(&ok, 10);
    if (!ok) return;
    int b = this->bbox->text().toInt(&ok, 10);
    if (!ok) return;
    std::string p = this->_plain->toPlainText().toStdString();
    std::string c = affine_encrypt(p, m, b);
    this->_cipher->setText(QString::fromStdString(c));
}

void AffineKeyBoxArea::decrypt() {
    bool ok;
    int m = this->mbox->text().toInt(&ok, 10);
    if (!ok) return;
    int b = this->bbox->text().toInt(&ok, 10);
    if (!ok) return;
    std::string c = this->_cipher->toPlainText().toStdString();
    std::string p = affine_decrypt(c, m, b);
    this->_plain->setText(QString::fromStdString(p));
}

void AffineKeyBoxArea::handle_encrypt_button() {
    std::cout << "encrypt\n";
    this->encrypt();
}

void AffineKeyBoxArea::handle_decrypt_button() {
    std::cout << "decrypt\n";
    this->decrypt();
}
