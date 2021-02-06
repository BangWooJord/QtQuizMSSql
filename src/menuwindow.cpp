#include "menuwindow.h"
#include "ui_menuwindow.h"

menuWindow::menuWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    int hsize = 300;
    int vsize = 60;
    int xpos = 60;
    int ypos = 60;
    this->setFixedSize(400,450);
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
    new_game_btn = createTemplate(new_game_btn, this, "New game", SIZE_AND_PLACE(hsize, 2*vsize, xpos, ypos));
        connect(new_game_btn, SIGNAL(clicked()), this, SLOT(newGameSlot()));
//        new_game_btn->setStyleSheet("QPushButton{background-color: #990033;"
//                                    "color: #f99e1b;"
//                                    "border-radius: 15px;"
//                                    "font-weight: 500;}"
//                                    "QPushButton:hover{background-color: #bb0033;}"
//                                    "QPushButton:focus{outline: none;}");
        //new_game_btn.ce
    settings_btn = new QPushButton("Settings", this);//createTemplate(settings_btn, this, "Settings", SIZE_AND_PLACE(hsize, vsize, xpos, ypos + vsize + 15));
        connect(new_game_btn, SIGNAL(clicked()), this, SLOT(settingsSlot()));
    logout_btn = createTemplate(logout_btn, this, "Log Out", SIZE_AND_PLACE(hsize, 2*vsize, xpos, ypos));
        connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
    QWidget *button_widget = new QWidget(this);
        button_widget->setGeometry(QRect(50,25, 300, 200));
    QVBoxLayout *vlayout = new QVBoxLayout(button_widget);
        vlayout->addWidget(new_game_btn);
        vlayout->addWidget(settings_btn);
        vlayout->addWidget(logout_btn);
    button_widget->show();
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



void menuWindow::logout(){
    emit firstWindow();
}


void menuWindow::newGameSlot(){
    std::cout << "New game clicked!" << std::endl;
}

void menuWindow::settingsSlot(){
    std::cout << "Settings clicked!" << std::endl;
}