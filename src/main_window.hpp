#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>

class MainWindow: public QMainWindow {
private:
    QLabel *label;
public:
    MainWindow(QWidget *parent, int width, int height);
    ~MainWindow();
};

#endif
