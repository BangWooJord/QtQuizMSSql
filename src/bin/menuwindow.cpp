#include "../header/menuwindow.h"
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
        new_game_btn->setCursor(Qt::PointingHandCursor);
        new_game_btn->setStyleSheet("QPushButton{"
                                  "font-size: 22px;"
                                  "font-weight: 600;"
                                  "color: #f99e1b;"
                                  "border-radius: 25px;"
                                  "background-color: #990033;}"
                                  "QPushButton:hover{"
                                  "background-color: #990044;}"
                                  "QPushButton:focus{outline: none;}");
    settings_btn = createTemplate(settings_btn, this, "Settings", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*1.33));
        connect(settings_btn, SIGNAL(clicked()), this, SLOT(settingsSlot()));
        settings_btn->setCursor(Qt::PointingHandCursor);
        settings_btn->setStyleSheet("QPushButton{"
                                    "font-size: 22px;"
                                    "font-weight: 600;"
                                    "color: #f99e1b;"
                                    "border-radius: 25px;"
                                    "background-color: #990033;}"
                                    "QPushButton:hover{"
                                    "background-color: #990044;}"
                                    "QPushButton:focus{outline: none;}");
    logout_btn = createTemplate(logout_btn, this, "Log Out", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*2.66));
        connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
        logout_btn->setCursor(Qt::PointingHandCursor);
        logout_btn->setStyleSheet("QPushButton{"
                                  "font-size: 22px;"
                                  "font-weight: 600;"
                                  "color: #f99e1b;"
                                  "border-radius: 25px;"
                                  "background-color: #990033;}"
                                  "QPushButton:hover{"
                                  "background-color: #990044;}"
                                  "QPushButton:focus{outline: none;}");
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
    emit newGameSignal();
}

void menuWindow::settingsSlot(){
    std::cout << "Settings clicked!" << std::endl;
}