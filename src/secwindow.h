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
public slots:
    void exitApp();
    void logOutSlot();
private:
    Ui::secWindow *ui;
    QStackedWidget *widget_stack;
    menuWindow *menu_window;
};

#endif // secWindow_H
