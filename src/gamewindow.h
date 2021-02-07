#ifndef QUIZGODHELP2_GAMEWINDOW_H
#define QUIZGODHELP2_GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QtSql/QSqlQuery>
#include "layoutHelp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gameWindow; }
QT_END_NAMESPACE

class gameWindow : public QWidget {
Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);

    ~gameWindow() override;
private:
    Ui::gameWindow *ui;
    QPushButton *ans[3];
};

#endif //QUIZGODHELP2_GAMEWINDOW_H
