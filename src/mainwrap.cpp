#include "mainwrap.h"
#include "ui_mainwrap.h"

mainWrap::mainWrap(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint),
    ui(new Ui::mainWrap)
{
    ui->setupUi(this);
        this->setFixedSize(400,450);
        this->setAttribute(Qt::WA_TranslucentBackground);
    QWidget *bg_widget = new QWidget(this);
        bg_widget->setGeometry(0,0,400,450);
        bg_widget->setStyleSheet("background-color: #1c172e;"
                                 "border-radius: 15px;");
    main_window = new MainWindow(this);
        connect(main_window, &MainWindow::leaveApp, this, &mainWrap::exitApp);
        connect(main_window, &MainWindow::secondWindow, this, &mainWrap::secondWindow);
        connect(main_window, &MainWindow::regWindow_signal, this, &mainWrap::registerWindow);
    reg_window = new regWindow(this);
        connect(reg_window, &regWindow::firstWindow, this, &mainWrap::returnMain);
        connect(main_window, &MainWindow::regWindow_signal, reg_window, &regWindow::clearFields);
        connect(reg_window, &regWindow::firstWindow, main_window, &MainWindow::returnToMain);
    second_window = new secWindow(this);
        connect(second_window, &secWindow::firstWindow, this, &mainWrap::returnMain);

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
        exit_btn->show();
        exit_btn->activateWindow();
        exit_btn->raise();

    widget_stack = new QStackedWidget(this);
        widget_stack->setGeometry(QRect(0,50, 400, 400));
        widget_stack->addWidget(main_window);
        widget_stack->addWidget(reg_window);
        widget_stack->addWidget(second_window);
        widget_stack->show();
}

mainWrap::~mainWrap()
{
    delete ui;
}

//////////METHODS/////////////////
void mainWrap::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        break;
    }
}

///////SLOTS///////////
void mainWrap::exitApp(){
    this->close();
}

void mainWrap::returnMain(){
    widget_stack->setCurrentWidget(main_window);
}
void mainWrap::secondWindow(){
    widget_stack->setCurrentWidget(second_window);
}
void mainWrap::registerWindow(){
    widget_stack->setCurrentWidget(reg_window);
}
