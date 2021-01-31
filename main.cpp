#include <QApplication>
#include <QPushButton>
#include "mainwrap.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    mainWrap w;
    w.show();
    w.setStyleSheet("background-color: #1c172e;"
                    "border-radius: 15px;");
    return a.exec();
}
