#include "../header/layoutHelp.h"

SIZE_AND_PLACE::SIZE_AND_PLACE() {
    hsize =10;
    vsize = 5;
    xpos = 10;
    ypos = 5;
}

SIZE_AND_PLACE::SIZE_AND_PLACE(int h, int v, int x, int y):hsize(h), vsize(v), xpos(x), ypos(y) {

}


template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp){
    new_smth = new T(text, p);
    new_smth->setGeometry(QRect(QPoint(sp.xpos, sp.ypos), QSize(sp.hsize, sp.vsize)));
    new_smth->setStyleSheet("font-size: 22px;"
                            "font-weight: 600;"
                            "color: #f99e1b;");

    return new_smth;
}

template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text){
    new_smth = new T(text, p);
    new_smth->setStyleSheet("font-size: 22px;"
                            "font-weight: 600;"
                            "color: #f99e1b;");

    return new_smth;
}
