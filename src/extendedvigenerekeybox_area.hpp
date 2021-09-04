#ifndef EXTVIGENEREKEYBOX_AREA_H
#define EXTVIGENEREKEYBOX_AREA_H

#include "singlekeybox_area.hpp"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class ExtendedVigenereKeyBoxArea: public QWidget {
    Q_OBJECT
public:
    QLineEdit* keybox;
    QLabel* filename_label;
    QPushButton* open_button;
    QPushButton* encrypt_button;
    QPushButton* decrypt_button;
    std::string filename;
    ExtendedVigenereKeyBoxArea(QWidget *parent, QTextEdit *plaintextbox, QTextEdit* ciphertextbox);
    ~ExtendedVigenereKeyBoxArea();
    void encrypt();
    void decrypt();
    void save(std::string str);
protected:
    QTextEdit *_plain, *_cipher;
private slots:
    void handle_open_button();
    void handle_encrypt_button();
    void handle_decrypt_button();
};

#endif
