#include "gamewindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::gameWindow)
{
    ui->setupUi(this);
    int hsize = 300;
        int vsize = 60;
        int xpos = (400-hsize)/2;
        int ypos = (450-(vsize*4))/2;
    QString question_query = "SELECT * FROM QUIZQUESTIONS WHERE id=1";
    QSqlQuery query;
        query.exec(question_query);
        query.first();
    for(int i = 0; i < 3; ++i){
        ans[i] = createTemplate(ans[i], this, query.value(i+2).toString(), SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*1.33*i));
        ans[i]->setCursor(Qt::PointingHandCursor);
        ans[i]->setStyleSheet("QPushButton{"
                                    "font-size: 22px;"
                                    "font-weight: 600;"
                                    "color: #f99e1b;"
                                    "border-radius: 25px;"
                                    "background-color: #990033;}"
                                    "QPushButton:hover{"
                                    "background-color: #990044;}"
                                    "QPushButton:focus{outline: none;}");
    }
}

gameWindow::~gameWindow() {
    delete ui;
}
