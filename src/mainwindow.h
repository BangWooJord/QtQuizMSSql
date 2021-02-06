#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QKeyEvent>
#include <QPixmap>
#include <QIcon>
#include <iostream>
#include "secwindow.h"
#include "regwindow.h"
#include <QPainter>
#include <QPen>
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
    template <typename T>
    T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp);
    void connectToDb(QString db_protocol, QString ip, QString db_name);
    void keyPressEvent(QKeyEvent *event ) override;
    void paintEvent(QPaintEvent *event) override;
private slots:
    void logIn();
    void registerWindow();
    void exitApp();
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
    QPushButton *exit_btn;
    QPushButton *register_btn;
    QLabel *usr_lbl;
    QLabel *pswd_lbl;
    QLabel *warning_lbl;
    QLabel *empty_pswd_lbl;
    QLabel *title_lbl;
    QLineEdit *username;
    QLineEdit *password;
};
#endif // MAINWINDOW_H
