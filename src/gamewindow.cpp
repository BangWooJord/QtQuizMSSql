#include "gamewindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::gameWindow)
{
    ui->setupUi(this);
}

gameWindow::~gameWindow() {
    delete ui;
}
