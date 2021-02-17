#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QtSql/QSqlQuery>
#include <iostream>
#include "layoutHelp.h"

namespace Ui {
class regWindow;
}

class regWindow : public QWidget
{
    Q_OBJECT

public:
    explicit regWindow(QWidget *parent = nullptr);
    ~regWindow();
signals:
    void firstWindow();
private slots:
    void backToMain();
    void signUpQuery();
public slots:
    void clearFields();
private:
    Ui::regWindow *ui;
    QLabel *user_lbl;
    QLabel *pswd_lbl;
    QLabel *email_lbl;
    QLabel *alert_lbl;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *email;
    QPushButton *back_btn;
    QPushButton *reg_btn;
};

#endif // REGWINDOW_H
