#include "main_window.hpp"
#include <QTabWidget>
#include <QBoxLayout>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent, int width, int height) {
    this->setWindowTitle("CryptTools");
    this->inputbox_area = new InputBoxArea(this, "Plaintext");
    this->inputbox_area2 = new InputBoxArea(this, "Ciphertext");

    QWidget* center = new QWidget(this);
    QVBoxLayout* clayout = new QVBoxLayout(this);
    QHBoxLayout* toplayout = new QHBoxLayout(this);
    

    QTextEdit* keybox = new QTextEdit(NULL);

    QTabWidget* tab_widget = new QTabWidget(this); 
    /* tab_widget->setTabPosition(QTabWidget::West); */
    tab_widget->addTab(keybox, "Vigenere Cipher");
    /* tab_widget->addTab(this->inputbox_area2, "Full Vigenere Cipher"); */
    

    toplayout->addWidget(inputbox_area);
    toplayout->addWidget(inputbox_area2);
    clayout->addLayout(toplayout, 3);
    clayout->addWidget(tab_widget, 1);
    center->setLayout(clayout);

    this->setCentralWidget(center);
}

MainWindow::~MainWindow() {
}
