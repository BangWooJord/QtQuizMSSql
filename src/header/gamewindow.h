#ifndef QUIZGODHELP2_GAMEWINDOW_H
#define QUIZGODHELP2_GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QtSql/QSqlQuery>
#include <vector>
#include <ctime>
#include "layoutHelp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gameWindow; }
QT_END_NAMESPACE

class gameWindow : public QWidget {
Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow() override;
    void gameEnd();

signals:
    void backToMenuSignal();
private slots:
    void changeQuestion();
    void backToMenu();
private:
    Ui::gameWindow *ui;
    QLabel *question_lbl;
    QLabel *score_lbl;
    QLabel *final_lbl;
    int score;
    int question_num;
    QPushButton *ans_btn[3];
    QPushButton *go_back_btn;
    std::vector<int> questions_id;
    QSqlQuery query;
};

#endif //QUIZGODHELP2_GAMEWINDOW_H
