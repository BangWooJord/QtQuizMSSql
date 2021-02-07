#include "menuwindow.h"
#include "ui_menuwindow.h"

menuWindow::menuWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    int hsize = 300;
    int vsize = 60;
    int xpos = (400-hsize)/2;
    int ypos = (450-(vsize*4))/2;
    this->setFixedSize(400,450);
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
    new_game_btn = createTemplate(new_game_btn, this, "New game", SIZE_AND_PLACE(hsize, vsize, xpos, ypos));
        connect(new_game_btn, SIGNAL(clicked()), this, SLOT(newGameSlot()));
    settings_btn = createTemplate(settings_btn, this, "Settings", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*1.33));
        connect(settings_btn, SIGNAL(clicked()), this, SLOT(settingsSlot()));
    logout_btn = createTemplate(logout_btn, this, "Log Out", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*2.66));
        connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
}

menuWindow::~menuWindow() {
    delete ui;
}


/////////METHODS///////////////////

//////////////SLOTS///////////////



void menuWindow::logout(){
    emit firstWindow();
}


void menuWindow::newGameSlot(){
    std::cout << "New game clicked!" << std::endl;
}

void menuWindow::settingsSlot(){
    std::cout << "Settings clicked!" << std::endl;
}