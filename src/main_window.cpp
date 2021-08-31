#include "main_window.hpp"

MainWindow::MainWindow(QWidget *parent, int width, int height) {
    this->setWindowTitle("CryptTools");
    this->label = new QLabel("Hello");
    this->setCentralWidget(this->label);
}

MainWindow::~MainWindow() {
    delete this->label;
}
