#ifndef SINGLEKEYBOX_AREA_H
#define SINGLEKEYBOX_AREA_H

#include "qobjectdefs.h"
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class SingleKeyBoxArea: public QWidget {
    Q_OBJECT
public:
    QTextEdit* keybox;
    QPushButton* encrypt_button;
    QPushButton* decrypt_button;
    explicit SingleKeyBoxArea(QWidget *parent);
    ~SingleKeyBoxArea();
};

#endif
