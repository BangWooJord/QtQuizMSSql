#include "gamewindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::gameWindow)
{
    ui->setupUi(this);
    int hsize = 260;
        int vsize = 50;
        int xpos = (400-hsize)/2;
        int ypos = (450-(vsize*4))/2;
        QString dd = "SELECT id FROM QUIZQUESTIONS";
        query.exec(dd);
        while(query.next()){
            questions_id.push_back(query.value(0).toInt());
        }
        srand(time(0));
    int rand_id = questions_id[rand() % questions_id.size()];
    std::vector<int>::iterator it = remove(questions_id.begin(), questions_id.end(), rand_id);
    QString question_query = "SELECT * FROM QUIZQUESTIONS WHERE id='%1'";
        question_query = question_query.arg(rand_id);
        query.exec(question_query);
        query.first();
    question_lbl = createTemplate(question_lbl, this, query.value(1).toString(), SIZE_AND_PLACE(hsize+30, vsize*3, xpos, ypos - vsize*2.5));
        question_lbl->setWordWrap(true);
        question_lbl->setAlignment(Qt::AlignCenter);
    std::vector<int> place_arr = {2,3,4};
    for(int i = 0; i < 3; ++i){
        srand(time(0));
        int place = place_arr[rand() % place_arr.size()];
        std::vector<int>::iterator place_it = remove(place_arr.begin(), place_arr.end(), place);
        ans_btn[i] = createTemplate(ans_btn[i], this, query.value(place).toString(), SIZE_AND_PLACE(hsize, vsize, xpos, ypos+vsize*1.33*i));
        ans_btn[i]->setCursor(Qt::PointingHandCursor);
        ans_btn[i]->setStyleSheet("QPushButton{"
                                    "font-size: 22px;"
                                    "font-weight: 600;"
                                    "color: #f99e1b;"
                                    "border-radius: 25px;"
                                    "background-color: #990033;}"
                              "QPushButton:hover{"
                                    "background-color: #990044;}"
                              "QPushButton:focus{outline: none;}");
        connect(ans_btn[i], SIGNAL(clicked()), this, SLOT(changeQuestion()));
    }
    score = 0;
    score_lbl = createTemplate(score_lbl, this, QString("Score: %1").arg(score), SIZE_AND_PLACE(hsize, vsize, xpos, ypos + vsize*4));
}

gameWindow::~gameWindow() {
    delete ui;
}

//////////METHODS////////////////////

void gameWindow::changeQuestion() {
    auto *sender_btn = qobject_cast<QPushButton*>(sender());
    if(query.value(2).toString() == sender_btn->text()){
        std::cout<<"answer is correct!"<<std::endl;
        score++;
        score_lbl->setText(QString("Score: %1").arg(score));
    }
    else{
        std::cout << "ubi machine broke" <<std::endl;
    }

    srand(time(0));
    int rand_id = questions_id[rand() % questions_id.size()];
    std::vector<int>::iterator it = remove(questions_id.begin(), questions_id.end(), rand_id);
    QString question_query = "SELECT * FROM QUIZQUESTIONS WHERE id='%1'";
        question_query = question_query.arg(rand_id);
    query.exec(question_query);
        query.first();
    question_lbl->setText(query.value(1).toString());
    for(int i = 0; i < 3; ++i){
        ans_btn[i]->setText(query.value(i+2).toString());
    }
}