#include "menuwindow.h"
#include "ui_menuwindow.h"

menuWindow::menuWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400,450);
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
    new_game_btn = createTemplate(new_game_btn, this, "New game", SIZE_AND_PLACE(200, 40, 20, 20));
        connect(new_game_btn, SIGNAL(clicked()), this, SLOT(newGameSlot()));
}

menuWindow::~menuWindow() {
    delete ui;
}


/////////METHODS///////////////////
template <typename T>
T* createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp){
    new_smth = new T(text, p);
    new_smth->setGeometry(QRect(QPoint(sp.xpos, sp.ypos), QSize(sp.hsize, sp.vsize)));
    new_smth->setStyleSheet("font-size: 22px;"
                            "font-weight: 600;"
                            "border-radius: 25px;"
                            "color: #990033;"
                            "padding-right: 20px;");

    return new_smth;
}

//////////////SLOTS///////////////

void menuWindow::newGameSlot(){
    std::cout<<"New game clicked !" << std::endl;
}