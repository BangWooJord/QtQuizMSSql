#include "../header/secwindow.h"
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
        connect(menu_window, &menuWindow::newGameSignal, this, &secWindow::startNewGame);
    game_window = new gameWindow(this);
        connect(game_window, &gameWindow::backToMenuSignal, this, &secWindow::openMenu);
    widget_stack = new QStackedWidget(this);
        widget_stack->setGeometry(QRect(0,0, 400, 400));
        widget_stack->addWidget(menu_window);
        widget_stack->addWidget(game_window);
        widget_stack->show();
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

void secWindow::startNewGame(){
    widget_stack->setCurrentWidget(game_window);
}

void secWindow::openMenu(){
    delete[]game_window;
    game_window = new gameWindow(this);
        connect(game_window, &gameWindow::backToMenuSignal, this, &secWindow::openMenu);
        widget_stack->addWidget(game_window);
    widget_stack->setCurrentWidget(menu_window);
}