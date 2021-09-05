#include "main_window.hpp"
#include <QTabWidget>
#include <QBoxLayout>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent, int width, int height)
    : QMainWindow(parent) {
    this->setWindowTitle("CryptoTools");
    this->plaintextbox_area = new InputBoxArea(this, "Plaintext");
    this->ciphertextbox_area = new InputBoxArea(this, "Ciphertext");
    this->vigenerekeybox_area = new VigenereKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);
    this->fullvigenerekeybox_area = new FullVigenereKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);
    this->autokeyvigenerekeybox_area = new AutoKeyVigenereKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);
    this->extendedvigenerekeybox_area = new ExtendedVigenereKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);
    this->playfairkeybox_area = new PlayfairKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);
    this->affinekeybox_area = new AffineKeyBoxArea(NULL, plaintextbox_area->textbox, ciphertextbox_area->textbox);

    QWidget* center = new QWidget(this);
    QVBoxLayout* clayout = new QVBoxLayout(this);
    QHBoxLayout* toplayout = new QHBoxLayout(this);
    

    QTabWidget* tab_widget = new QTabWidget(this); 
    tab_widget->addTab(vigenerekeybox_area, "Vigenere Cipher");
    tab_widget->addTab(fullvigenerekeybox_area, "Full Vigenere Cipher");
    tab_widget->addTab(autokeyvigenerekeybox_area, "Auto-key Vigenere Cipher");
    tab_widget->addTab(extendedvigenerekeybox_area, "Extended Vigenere Cipher");
    tab_widget->addTab(playfairkeybox_area, "Playfair Cipher");
    tab_widget->addTab(affinekeybox_area, "Affine Cipher");
    

    toplayout->addWidget(plaintextbox_area);
    toplayout->addWidget(ciphertextbox_area);
    clayout->addLayout(toplayout, 2);
    clayout->addWidget(tab_widget, 1);
    center->setLayout(clayout);

    this->setCentralWidget(center);
}

MainWindow::~MainWindow() {
}
