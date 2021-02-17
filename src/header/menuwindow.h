#ifndef QUIZGODHELP2_MENUWINDOW_H
#define QUIZGODHELP2_MENUWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <iostream>
#include "layoutHelp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menuWindow; }
QT_END_NAMESPACE

class menuWindow : public QWidget {
Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);

    ~menuWindow() override;
signals:
    void firstWindow();
    void newGameSignal();
private slots:
    void logout();
    void newGameSlot();
    static void settingsSlot();
private:
    Ui::menuWindow *ui;
    QPushButton *new_game_btn;
    QPushButton *settings_btn;
    QPushButton *logout_btn;
};

#endif //QUIZGODHELP2_MENUWINDOW_H
