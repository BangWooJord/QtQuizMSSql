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
    questions_id.erase(std::remove(questions_id.begin(), questions_id.end(), rand_id), questions_id.end());
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
        place_arr.erase(std::remove(place_arr.begin(), place_arr.end(), place), place_arr.end());
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
    question_num = 0;
    score_lbl = createTemplate(score_lbl, this, QString("Score: %1").arg(score), SIZE_AND_PLACE(hsize, vsize, xpos, ypos + vsize*4));
}

gameWindow::~gameWindow() {
    delete ui;
}

///////////SLOTS////////////////////

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

    question_num++;

    if(question_num == 5) {
        gameEnd();
    }
    else {
        srand(time(0));
        int rand_id = questions_id[rand() % questions_id.size()];
        questions_id.erase(std::remove(questions_id.begin(), questions_id.end(), rand_id), questions_id.end());
        QString question_query = "SELECT * FROM QUIZQUESTIONS WHERE id='%1'";
        question_query = question_query.arg(rand_id);
        query.exec(question_query);
        query.first();
        question_lbl->setText(query.value(1).toString());
        std::vector<int> place_arr = {2, 3, 4};
        for (int i = 0; i < 3; ++i) {
            srand(time(0));
            int place = place_arr[rand() % place_arr.size()];
            place_arr.erase(std::remove(place_arr.begin(), place_arr.end(), place), place_arr.end());
            ans_btn[i]->setText(query.value(place).toString());
        }
    }
}

void gameWindow::backToMenu() {
    emit backToMenuSignal();
}

//////////METHODS////////////////////

void gameWindow::gameEnd(){
    score_lbl->hide();
    question_lbl->hide();
    for(int i = 0; i < 3; ++i) ans_btn[i]->hide();
    final_lbl = createTemplate(final_lbl, this, QString("Game over! \n Your score: %1").arg(score), SIZE_AND_PLACE(260, 50, 70, 100));
        final_lbl->show();
    go_back_btn = createTemplate(go_back_btn, this, "Back to menu", SIZE_AND_PLACE(260, 60, 70, 170));
        connect(go_back_btn, SIGNAL(clicked()), this, SLOT(backToMenu()));
        go_back_btn->show();
}