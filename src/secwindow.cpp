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

    menu_window = new menuWindow(this);
        connect(menu_window, SIGNAL(firstWindow()), this, SLOT(logOutSlot()));
    widget_stack = new QStackedWidget(this);
        widget_stack->setGeometry(QRect(0,50, 400, 400));
        widget_stack->addWidget(menu_window);
        widget_stack->show();
//    logout_btn = createTemplate(logout_btn, this, "Log out", SIZE_AND_PLACE(100, 40, 10,10));
//        logout_btn->setStyleSheet("QPushButton{background-color: #990033;"
//                                  "color: #f99e1b;"
//                                  "font-size: 20px;"
//                                  "font-weight: 700;"
//                                  "border-radius: 15px}"
//                                  "QPushButton:hover{background-color: #bb0033}"
//                                  "QPushButton:focus{outline:none}");
//        logout_btn->setCursor(Qt::PointingHandCursor);
//
//        connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
}

secWindow::~secWindow()
{
    delete ui;
}
////////////METHODS///////////////

///////////SLOTS//////////////////
void secWindow::exitApp(){
    this->close();
}

void secWindow::logOutSlot(){
    emit(firstWindow());
}