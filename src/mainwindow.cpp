#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400,450);
        this->setWindowTitle("Login");
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->statusBar()->close();
    int hsize = 300;
        int vsize = 50;
        int xpos = 50;
        int ypos = 150;
    exit_btn = createTemplate(exit_btn, this, "x", SIZE_AND_PLACE(30, 30, 360, 10));
        connect(exit_btn, SIGNAL(clicked()), this, SLOT(exitApp()));
        exit_btn->setStyleSheet("QPushButton{"
                                "background-color: #880033;"
                                "color: white;"
                                "font-weight: 800;"
                                "font-size: 22px;"
                                "padding-bottom: 5px;"
                                "border-radius: 10px;}"
                                "QPushButton:hover{"
                                "background-color: #990044;}"
                                "QPushButton:focus{outline:none;}");
        exit_btn->setCursor(Qt::PointingHandCursor);
    submit_btn = createTemplate(submit_btn, this, "Sign in", SIZE_AND_PLACE(80, vsize, xpos+hsize-80, ypos+3*vsize+30));
        connect(submit_btn, SIGNAL(clicked()), this, SLOT(logIn()));
        submit_btn->setStyleSheet("QPushButton{background-color: #990033;"
                                  "color: #f99e1b;"
                                  "border-radius: 15px;"
                                  "font-weight: 500;}"
                                  "QPushButton:hover{background-color: #bb0033;}"
                                  "QPushButton:focus{outline: none;}");
        submit_btn->setCursor(Qt::PointingHandCursor);
    register_btn = createTemplate(register_btn, this, "Create an account", SIZE_AND_PLACE(210, vsize, xpos, ypos+3*vsize+30));
        connect(register_btn, SIGNAL(clicked()), this, SLOT(registerWindow()));
        register_btn->setStyleSheet("QPushButton{background-color: #330099;"
                                    "color: #f99e1b;"
                                    "border-radius: 15px;"
                                    "font-weight: 500;}"
                                    "QPushButton:hover{background-color: #3300bb;}"
                                    "QPushButton:focus{outline: none;}");
        register_btn->setCursor(Qt::PointingHandCursor);
    username = createTemplate(username, this, "", SIZE_AND_PLACE(hsize, vsize, xpos, ypos));
        username->setAlignment(Qt::AlignRight);
        username->setStyleSheet("border-radius: 25px;"
                                "background-color: #382860;"
                                "color: #f79e1b;"
                                "font-size: 20px;"
                                "font-weight: 500;"
                                "padding-right: 20px;");
    password = createTemplate(password, this, "", SIZE_AND_PLACE(hsize, vsize, xpos, ypos+2*vsize));
        password->setEchoMode(QLineEdit::Password);
        password->setAlignment(Qt::AlignRight);
        password->setStyleSheet("border-radius: 25px;"
                                "background-color: #382860;"
                                "color: #f79e1b;"
                                "font-size: 20px;"
                                "font-weight: 500;"
                                "padding-right: 20px;");
    title_lbl = createTemplate(title_lbl, this, "Quiz", SIZE_AND_PLACE(hsize+10, vsize, xpos, 40));
        title_lbl->setAlignment(Qt::AlignCenter);
        title_lbl->setStyleSheet("font-size: 40px;"
                                 "font-weight: 900;"
                                 "color: #f99e1b;"
                                 "");
    usr_lbl = createTemplate(usr_lbl, this, "Username", SIZE_AND_PLACE(hsize, vsize/2, xpos, ypos-30));
        usr_lbl->setAlignment(Qt::AlignRight);
    pswd_lbl = createTemplate(pswd_lbl, this, "Password", SIZE_AND_PLACE(hsize, vsize/2, xpos, ypos+2*vsize-30));
        pswd_lbl->setAlignment(Qt::AlignRight);
    warning_lbl = createTemplate(warning_lbl, this, "Username or password is incorrect", SIZE_AND_PLACE(hsize*2, vsize/2, 15, ypos + 3*vsize));
        warning_lbl->hide();
        warning_lbl->setStyleSheet("font-size: 20px;"
                                   "font-weight: 600;"
                                   "border-radius: 25px;"
                                   "color: #990033;"
                                   "padding-right: 20px;"
                                   "text-decoration: underline");
    empty_pswd_lbl = createTemplate(empty_pswd_lbl, this, "*", SIZE_AND_PLACE(40,40, 360, 250));
        empty_pswd_lbl->setStyleSheet("font-weight: 600;"
                                      "font-size: 26px;"
                                      "color: #11dd33;");
        empty_pswd_lbl->hide();
    connectToDb("QODBC3", "tcp:127.0.0.1,54120", "QUIZDB");
}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////SLOTS///////////////

void MainWindow::logIn(){
    QString app_pswd = password->text();
    if(app_pswd == "") empty_pswd_lbl->show();
    else{
        QString login_query = "SELECT * FROM QUIZUSERS2 WHERE username='%1'";
            login_query = login_query.arg(username->text());
        QSqlQuery query;
            query.exec(login_query);
            query.first();
            QString db_pswd = query.value(2).toString();
            std::cout<< db_pswd.toStdString() << std::endl;
        if(app_pswd == db_pswd){
            emit secondWindow();
        }
        else{
            warning_lbl->show();
        }
    }
}

void MainWindow::registerWindow(){
    emit regWindow_signal();
}



void MainWindow::returnToMain(){
    username->clear();
    password->clear();
    username->clearFocus();
    password->clearFocus();
    warning_lbl->hide();
    empty_pswd_lbl->hide();
    this->show();
}

void MainWindow::exitApp(){
    emit leaveApp();
}

void MainWindow::clearFields(){}

////////METHODS///////////////

void MainWindow::connectToDb(QString db_protocol, QString ip, QString db_name){
    QSqlDatabase qdb = QSqlDatabase::addDatabase(db_protocol);
        qdb.setConnectOptions();
        //MSSQLSERVER01//
        QString connectionString =  QString("DRIVER={ODBC Driver 17 for SQL Server};Server=%1;Database=%2;Trusted_Connection=Yes;").arg(ip,db_name);
        qdb.setDatabaseName(connectionString);
        qdb.setUserName("clion_admin");
        qdb.setPassword("admin");
        bool connectionSuccessful = qdb.open();
        std::cout << "Connection to database: " << connectionSuccessful << std::endl;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Return:
        emit(submit_btn->clicked());
        break;
    }
}

template <typename T>
T* MainWindow::createTemplate(T *new_smth, QWidget *p, QString text, SIZE_AND_PLACE sp){
    new_smth = new T(text, p);
    new_smth->setGeometry(QRect(QPoint(sp.xpos, sp.ypos), QSize(sp.hsize, sp.vsize)));
    new_smth->setStyleSheet("font-size: 22px;"
                            "font-weight: 600;"
                            "border-radius: 25px;"
                            "color: #990033;"
                            "padding-right: 20px;");
    return new_smth;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(Qt::SolidPattern);
    //painter.drawRect(QRect(100, 0, 400,50));
}
