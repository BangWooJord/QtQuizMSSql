#include "secwindow.h"
#include "ui_secwindow.h"

secWindow::secWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #1c172e;"
                        "border-radius: 15px;");
        this->setWindowFlag(Qt::FramelessWindowHint);
    logout_btn = createTemplate(logout_btn, this, "Log out", SIZE_AND_PLACE(100, 40, 10,10));
        logout_btn->setStyleSheet("QPushButton{background-color: #990033;"
                                  "color: #f99e1b;"
                                  "font-size: 20px;"
                                  "font-weight: 700;"
                                  "border-radius: 15px}"
                                  "QPushButton:hover{background-color: #bb0033}"
                                  "QPushButton:focus{outline:none}");
        logout_btn->setCursor(Qt::PointingHandCursor);

        connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
}

secWindow::~secWindow()
{
    delete ui;
}
////////////METHODS///////////////

template <typename T>
T* secWindow::createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp){
    new_smth = new T(text, p);
    new_smth->setGeometry(QRect(QPoint(sp.xpos, sp.ypos), QSize(sp.hsize, sp.vsize)));
    new_smth->setStyleSheet("font-size: 22px;"
                            "font-weight: 600;"
                            "border-radius: 25px;"
                            "color: #990033;"
                            "padding-right: 20px;");
    return new_smth;
}

///////////SLOTS//////////////////
void secWindow::exitApp(){
    this->close();
}

void secWindow::logout(){
    this->close();
    emit firstWindow();
}
