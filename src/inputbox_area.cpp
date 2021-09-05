#include "inputbox_area.hpp"
#include "util.hpp"
#include <iostream>
#include <fstream>
#include <QFileDialog>

InputBoxArea::InputBoxArea(QWidget* parent, const QString& labelstr) : 
    QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel(labelstr, this);

    this->textbox = new QTextEdit(this);
    this->open_button = new QPushButton("Open", this);
    this->save_button = new QPushButton("Save", this);
    this->removespace_button = new QPushButton("Remove Spaces", this);
    this->blockof5_button = new QPushButton("Block of 5", this);

    layout->addWidget(label);
    layout->addWidget(textbox);
    layout->addWidget(open_button);
    layout->addWidget(save_button);
    layout->addWidget(removespace_button);
    layout->addWidget(blockof5_button);

    this->setLayout(layout);

    connect(this->open_button, &QPushButton::released, 
            this, &InputBoxArea::handle_open_button);
    connect(this->save_button, &QPushButton::released, 
            this, &InputBoxArea::handle_save_button);
    connect(this->removespace_button, &QPushButton::released, 
            this, &InputBoxArea::handle_removespace_button);
    connect(this->blockof5_button, &QPushButton::released, 
            this, &InputBoxArea::handle_blockof5_button);
}

InputBoxArea::~InputBoxArea() {
    //
}

void InputBoxArea::handle_open_button() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), ".");
    if (filename.compare("")) {
        std::cout << "open " << filename.toStdString() << "\n";
        std::ifstream f;
        f.open(filename.toStdString());
        if (!f.is_open()) return;
        QString newstr;
        char c;
        while(f.get(c))
            newstr.push_back(c);
        this->textbox->setText(newstr);
        f.close();
    }
}

void InputBoxArea::handle_save_button() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Open File"), ".");
    if (filename.compare("")) {
        std::cout << "save " << filename.toStdString() << "\n";
        std::ofstream f;
        f.open(filename.toStdString());
        if (!f.is_open()) return;
        std::string str = this->textbox->toPlainText().toStdString();
        for (auto it = str.begin(); it != str.end(); it++)
            f.put(*it);
        f.close();
    }
}

void InputBoxArea::handle_removespace_button() {
    this->textbox->setText(QString::fromStdString
        (filter_alphabet(this->textbox->toPlainText().toStdString())));
}

void InputBoxArea::handle_blockof5_button() {
    this->textbox->setText(QString::fromStdString
        (blockof5(this->textbox->toPlainText().toStdString())));
}
