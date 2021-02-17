#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QKeyEvent>
#include <iostream>
#include "secwindow.h"
#include "regwindow.h"
#include <QStackedWidget>
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectToDb(QString db_protocol, QString ip, QString db_name);
    void keyPressEvent(QKeyEvent *event ) override;
private slots:
    void logIn();
    void registerWindow();
public slots:
    void returnToMain();
    void clearFields();
signals:
    void leaveApp();
    void secondWindow();
    void regWindow_signal();
private:
    Ui::MainWindow *ui;
    QPushButton *submit_btn;
    QPushButton *register_btn;
    QLabel *usr_lbl;
    QLabel *pswd_lbl;
    QLabel *warning_lbl;
    QLabel *title_lbl;
    QLineEdit *username;
    QLineEdit *password;
};
#endif // MAINWINDOW_H
