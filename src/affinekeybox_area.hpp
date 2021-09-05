#ifndef AFFINEKEYBOX_AREA_H
#define AFFINEKEYBOX_AREA_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

class AffineKeyBoxArea: public QWidget {
    Q_OBJECT
public:
    QLineEdit* mbox;
    QLineEdit* bbox;
    QPushButton* encrypt_button;
    QPushButton* decrypt_button;
    explicit AffineKeyBoxArea(
        QWidget *parent, 
        QTextEdit *plaintextbox, 
        QTextEdit *ciphertextbox
    );
    ~AffineKeyBoxArea();
    void encrypt();
    void decrypt();
protected:
    QTextEdit *_plain, *_cipher;
private slots:
    void handle_encrypt_button();
    void handle_decrypt_button();
};

#endif
