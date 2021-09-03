#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "inputbox_area.hpp"
#include "singlekeybox_area.hpp"

class MainWindow: public QMainWindow {
private:
    QLabel *label;
    InputBoxArea *plaintextbox_area;
    InputBoxArea *ciphertextbox_area;
    SingleKeyBoxArea * vigenerekeybox_area;
public:
    MainWindow(QWidget *parent, int width, int height);
    ~MainWindow();
};

#endif
