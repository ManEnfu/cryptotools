#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "inputbox_area.hpp"

class MainWindow: public QMainWindow {
private:
    QLabel *label;
    InputBoxArea *inputbox_area;
    InputBoxArea *inputbox_area2;
public:
    MainWindow(QWidget *parent, int width, int height);
    ~MainWindow();
};

#endif
