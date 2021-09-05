#ifndef INPUTBOXAREA_H
#define INPUTBOXAREA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class InputBoxArea: public QWidget {
    Q_OBJECT
public:
    QTextEdit* textbox;
    QPushButton* open_button;
    QPushButton* save_button;
    QPushButton* removespace_button;
    QPushButton* blockof5_button;
    explicit InputBoxArea(QWidget *parent, const QString& labelstr);
    ~InputBoxArea();
private slots:
    void handle_open_button();
    void handle_save_button();
    void handle_removespace_button();
    void handle_blockof5_button();
};

#endif
