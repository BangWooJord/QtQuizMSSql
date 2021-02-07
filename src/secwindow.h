#ifndef secWindow_H
#define secWindow_H

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QStackedWidget>
#include <iostream>
#include "layoutHelp.h"
#include "menuwindow.h"
#include "gamewindow.h"

namespace Ui {
class secWindow;
}

class secWindow : public QWidget
{
    Q_OBJECT

public:
    explicit secWindow(QWidget *parent = nullptr);
    ~secWindow();

signals:
    void firstWindow();
private slots:
    void exitApp();
    void logOutSlot();
    void startNewGame();
private:
    Ui::secWindow *ui;
    QStackedWidget *widget_stack;
    menuWindow *menu_window;
    gameWindow *game_window;
};

#endif // secWindow_H
