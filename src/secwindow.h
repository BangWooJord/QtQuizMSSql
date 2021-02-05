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
    template <typename T>
    T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp);
signals:
    void firstWindow();
public slots:
    void exitApp();
    void logout();
private:
    Ui::secWindow *ui;
    QPushButton *logout_btn;
    QStackedWidget *widget_stack;
    menuWindow *menu_window;
};

#endif // secWindow_H
