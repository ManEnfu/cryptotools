#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "inputbox_area.hpp"
#include "singlekeybox_area.hpp"
#include "vigenerekeybox_area.hpp"
#include "fullvigenerekeybox_area.hpp"
#include "autokeyvigenerekeybox_area.hpp"
#include "extendedvigenerekeybox_area.hpp"
#include "playfairkeybox_area.hpp"
#include "affinekeybox_area.hpp"

class MainWindow: public QMainWindow {
private:
    QLabel *label;
    InputBoxArea *plaintextbox_area;
    InputBoxArea *ciphertextbox_area;
    VigenereKeyBoxArea *vigenerekeybox_area;
    FullVigenereKeyBoxArea *fullvigenerekeybox_area;
    AutoKeyVigenereKeyBoxArea *autokeyvigenerekeybox_area;
    ExtendedVigenereKeyBoxArea *extendedvigenerekeybox_area;
    PlayfairKeyBoxArea *playfairkeybox_area;
    AffineKeyBoxArea *affinekeybox_area;
public:
    MainWindow(QWidget *parent, int width, int height);
    ~MainWindow();
};

#endif
