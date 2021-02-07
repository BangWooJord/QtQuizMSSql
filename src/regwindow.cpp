#include "regwindow.h"
#include "ui_regwindow.h"

regWindow::regWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #1c172e;"
                        "border-radius: 15px;");
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setFixedSize(400,450);
    int hsize = 300;
        int vsize = 50;
        int xpos = 50;
        int ypos = 150;
    user_lbl = createTemplate(user_lbl, this, "Username", SIZE_AND_PLACE(hsize, vsize, xpos, ypos - vsize - 35));
        user_lbl->setAlignment(Qt::AlignRight);
    pswd_lbl = createTemplate(pswd_lbl, this, "Password", SIZE_AND_PLACE(hsize, vsize, xpos, ypos + vsize - 35));
        pswd_lbl->setAlignment(Qt::AlignRight);
    email_lbl = createTemplate(email_lbl, this, "e-Mail", SIZE_AND_PLACE(hsize, vsize, xpos, ypos + 3*vsize - 35));
        email_lbl->setAlignment(Qt::AlignRight);
    error_lbl = createTemplate(error_lbl, this, "Username taken", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+3*vsize+50));
        error_lbl->setAlignment(Qt::AlignRight);
        error_lbl->hide();
    username = createTemplate(username, this, "", SIZE_AND_PLACE(hsize, vsize, xpos, ypos - vsize));
        username->setStyleSheet("border-radius: 25px;"
                                "background-color: #382860;"
                                "color: #f79e1b;"
                                "font-size: 20px;"
                                "font-weight: 500;"
                                "padding-right: 20px;");
        username->setAlignment(Qt::AlignRight);
    password = createTemplate(password, this, "", SIZE_AND_PLACE(hsize, vsize, xpos, ypos + vsize));
        password->setStyleSheet("border-radius: 25px;"
                                "background-color: #382860;"
                                "color: #f79e1b;"
                                "font-size: 20px;"
                                "font-weight: 500;"
                                "padding-right: 20px;");
        password->setAlignment(Qt::AlignRight);
    email = createTemplate(email, this, "", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+3*vsize));
        email->setStyleSheet("border-radius: 25px;"
                             "background-color: #382860;"
                             "color: #f79e1b;"
                             "font-size: 20px;"
                             "font-weight: 500;"
                             "padding-right: 20px;");
        email->setAlignment(Qt::AlignRight);
    back_btn = createTemplate(back_btn, this, "Go back", SIZE_AND_PLACE(120, vsize, xpos , ypos + 4.5*vsize));
        back_btn->setStyleSheet("QPushButton{background-color: #222233;"
                                "color: black;"
                                "font-size: 22px;"
                                "font-weight: 600}"
                                "QPushButton:hover{background-color: #333344;}"
                                "QPushButton:focus{outline: none;}");
        back_btn->setCursor(Qt::PointingHandCursor);
    reg_btn = createTemplate(reg_btn, this, "Sign up", SIZE_AND_PLACE(hsize-120, vsize, xpos + 130, ypos + 4.5*vsize));
        connect(reg_btn, SIGNAL(clicked()), this, SLOT(signUpQuery()));
        reg_btn->setStyleSheet("QPushButton{background-color: #880033;"
                                "color: black;"
                                "font-size: 22px;"
                                "font-weight: 600}"
                                "QPushButton:hover{background-color: #990044;}"
                                "QPushButton:focus{outline: none;}");
        reg_btn->setCursor(Qt::PointingHandCursor);
        connect(back_btn, SIGNAL(clicked()), this, SLOT(backToMain()));
}

regWindow::~regWindow()
{
    delete ui;
}

//////METHODS//////////

/////////SLOTS/////////////
void regWindow::backToMain(){
    emit firstWindow();
    std::cout << "back to main" << std::endl;
}

void regWindow::signUpQuery(){
    QString sign_up_query = "SELECT * FROM QUIZUSERS2 WHERE username='%1'";
        sign_up_query = sign_up_query.arg(username->text());
    QSqlQuery query;
    query.exec(sign_up_query);
        if(query.next()){
            error_lbl->show();
        }
        else{
            if(password->text() == ""){
                error_lbl->setText("Input password");
                error_lbl->show();
            }
            else{
                sign_up_query = "INSERT INTO QUIZUSERS2 (username, pword, email)"
                                "VALUES ('%1','%2','%3')";
                    sign_up_query = sign_up_query.arg(username->text(), password->text(), email->text());
                    query.exec(sign_up_query);
                std::cout << "SQL INSERT COMPLETE" << std::endl;
            }
        }
}

void regWindow::clearFields(){
    username->clear();
    password->clear();
    email->clear();
    error_lbl->hide();
}
