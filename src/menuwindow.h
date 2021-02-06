#ifndef QUIZGODHELP2_MENUWINDOW_H
#define QUIZGODHELP2_MENUWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>
#include "layoutHelp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menuWindow; }
QT_END_NAMESPACE

template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp);

class menuWindow : public QWidget {
Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);

    ~menuWindow() override;
signals:
    void firstWindow();
private slots:
    void logout();
    static void newGameSlot();
    static void settingsSlot();
private:
    Ui::menuWindow *ui;
    QPushButton *new_game_btn;
    QPushButton *settings_btn;
    QPushButton *logout_btn;
};

#endif //QUIZGODHELP2_MENUWINDOW_H
