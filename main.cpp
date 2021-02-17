#include <QApplication>
#include "src/header/mainwrap.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWrap w;
    w.show();
    w.setStyleSheet("background-color: #1c172e;"
                    "border-radius: 15px;");
    return a.exec();
}
