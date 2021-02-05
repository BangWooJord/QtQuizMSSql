#ifndef MAINWRAP_H
#define MAINWRAP_H

#include <QWidget>
#include <QStackedWidget>
#include <QKeyEvent>
#include <QtGui>
#include "mainwindow.h"
#include "regwindow.h"
#include "secwindow.h"

namespace Ui {
class mainWrap;
}

class mainWrap : public QWidget
{
    Q_OBJECT

public:
    explicit mainWrap(QWidget *parent = nullptr);
    ~mainWrap();
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void exitApp();
    void secondWindow();
    void registerWindow();
    void returnMain();
private:
    Ui::mainWrap *ui;
    QStackedWidget *widget_stack;
    MainWindow *main_window;
    regWindow *reg_window;
    secWindow *second_window;
};

#endif // MAINWRAP_H
