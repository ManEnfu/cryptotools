#ifndef SINGLEKEYBOX_AREA_H
#define SINGLEKEYBOX_AREA_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class SingleKeyBoxArea: public QWidget {
    Q_OBJECT
public:
    QTextEdit* keybox;
    QPushButton* encrypt_button;
    QPushButton* decrypt_button;
    explicit SingleKeyBoxArea(QWidget *parent, QTextEdit *plaintextbox, QTextEdit *ciphertextbox);
    ~SingleKeyBoxArea();
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;
protected:
    QTextEdit *_plain, *_cipher;
private slots:
    void handle_encrypt_button();
    void handle_decrypt_button();
};

#endif
