#include "main_window.hpp"
#include <QApplication>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow window(NULL, 800, 600);
    window.show();
    return app.exec();
}
