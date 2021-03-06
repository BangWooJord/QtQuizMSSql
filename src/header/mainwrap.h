#ifndef MAINWRAP_H
#define MAINWRAP_H

#include <QWidget>
#include <QPushButton>
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
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    Ui::mainWrap *ui;
    QStackedWidget *widget_stack;
    QPushButton *exit_btn;
    MainWindow *main_window;
    regWindow *reg_window;
    secWindow *second_window;
};

#endif // MAINWRAP_H
