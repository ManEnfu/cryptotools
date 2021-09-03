#include "main_window.hpp"
#include <QTabWidget>
#include <QBoxLayout>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent, int width, int height) {
    this->setWindowTitle("CryptTools");
    this->plaintextbox_area = new InputBoxArea(this, "Plaintext");
    this->ciphertextbox_area = new InputBoxArea(this, "Ciphertext");
    this->vigenerekeybox_area = new SingleKeyBoxArea(NULL);

    QWidget* center = new QWidget(this);
    QVBoxLayout* clayout = new QVBoxLayout(this);
    QHBoxLayout* toplayout = new QHBoxLayout(this);
    

    QTabWidget* tab_widget = new QTabWidget(this); 
    /* tab_widget->setTabPosition(QTabWidget::West); */
    tab_widget->addTab(vigenerekeybox_area, "Vigenere Cipher");
    /* tab_widget->addTab(this->inputbox_area2, "Full Vigenere Cipher"); */
    

    toplayout->addWidget(plaintextbox_area);
    toplayout->addWidget(ciphertextbox_area);
    clayout->addLayout(toplayout, 3);
    clayout->addWidget(tab_widget, 1);
    center->setLayout(clayout);

    this->setCentralWidget(center);
}

MainWindow::~MainWindow() {
}
