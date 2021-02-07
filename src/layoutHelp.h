#ifndef QTQUIZBABE_LAYOUTHELP_H
#define QTQUIZBABE_LAYOUTHELP_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

struct SIZE_AND_PLACE{
    int hsize;
    int vsize;
    int xpos;
    int ypos;
    SIZE_AND_PLACE();
    SIZE_AND_PLACE(int h, int v, int x, int y);
};


template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp);
template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text);


#endif //QTQUIZBABE_LAYOUTHELP_H
