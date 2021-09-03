#include "singlekeybox_area.hpp"
#include <QLabel>
#include <QBoxLayout>

SingleKeyBoxArea::SingleKeyBoxArea(QWidget* parent) : QWidget(parent) {
    this->keybox = new QTextEdit(this);
    this->encrypt_button = new QPushButton("Encrypt", this);
    this->decrypt_button = new QPushButton("Decrypt", this);
    
    QHBoxLayout* layout = new QHBoxLayout(this);
    QVBoxLayout* leftlayout = new QVBoxLayout(this);
    QVBoxLayout* rightlayout = new QVBoxLayout(this);
    QLabel* label = new QLabel("Key", this);

    leftlayout->addWidget(label);
    leftlayout->addWidget(keybox);
    rightlayout->addWidget(encrypt_button);
    rightlayout->addWidget(decrypt_button);
    layout->addLayout(leftlayout);
    layout->addLayout(rightlayout);
    this->setLayout(layout);
}

SingleKeyBoxArea::~SingleKeyBoxArea() {
    //
}
