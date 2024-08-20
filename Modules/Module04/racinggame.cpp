#include "racinggame.h"
#include "ui_racinggame.h"
#include "carthread.h"
#include "setdialog.h"

#define CAR_SIZE 20

#define READY 0
#define MOVING 1
#define ARRIVED 2


RacingGame::RacingGame(QList<Car> cars, Track track, QWidget *parent):
    QMainWindow(parent), ui(new Ui::RacingGame), cars(cars), track(track){
    ui->setupUi(this);

    car_initialize(); //initialize for the position of the car

    QString color[3] = {"red", "green", "blue"};

    for(int i = 0; i < 3; i++){ //car information print
        QWidget * basePtr1 = ui->carInfo->itemAtPosition(0, i)->widget();
        QLabel * carName = dynamic_cast<QLabel*>(basePtr1);

        QWidget * basePtr2 = ui->carInfo->itemAtPosition(1, i)->widget();
        QLabel * carState = dynamic_cast<QLabel*>(basePtr2);

        if(i < cars.size()){
            carName->setText(cars[i].getName() + " (speed: " + QString::number(cars[i].getSpeed()) +")");
            carName->setStyleSheet("QLabel { color : "+ color[i] +"; }");
            carName->show();

            carState->setText("State: ready");
            carState->show();
        }
        else{
            carName->hide();
            carState->hide();
        }
    }

    make_new_track(); //curtomize track for a car, objective is setting endline different
}

void RacingGame::paintEvent(QPaintEvent * e){
    QPainter painter(this);

    for (int i = 0; i < track.ways(); i++){ //drawing the track ♥
        Position pos = track.track_pos(i);
        Position size = track.track_size(i);
        painter.setBrush(Qt::black); //road
        painter.drawRect(pos.x, pos.y, size.x, size.y);
    }

    for (int i = 0; i < track.ways(); i++){ //drawing the center line
        Position pos_from = track.pos(i);
        Position pos_to = track.pos(i+1);

        painter.setPen(Qt::yellow); //center line in the road
        painter.drawLine(pos_from.x, pos_from.y, pos_to.x, pos_to.y);
    }

    int end_x[5] = {0, -CAR_SIZE, -CAR_SIZE, -CAR_SIZE, -3*CAR_SIZE}; //drawing the endline!
    int end_y[5] = {0, -3*CAR_SIZE, -CAR_SIZE, -CAR_SIZE, -CAR_SIZE};
    int end_w[5] = {0, CAR_SIZE*2 , CAR_SIZE*4, CAR_SIZE*2 , CAR_SIZE*4};
    int end_h[5] = {0, CAR_SIZE*4, CAR_SIZE*2, CAR_SIZE*4, CAR_SIZE*2};


    painter.setPen(Qt::red);
    painter.setBrush(QBrush(Qt::blue, Qt::Dense2Pattern));
    int dir = track.dir(track.ways()-1);

    painter.drawRect(track.end().x + end_x[dir], track.end().y + end_y[dir], end_w[dir], end_h[dir]);

    drawing_car();
}

RacingGame::~RacingGame()
{
    delete ui;
}

void RacingGame::drawing_car(){
    QColor colors[3] = {Qt::red, Qt::green, Qt::blue};
    for (int i = 0; i < cars.count(); i++){
        QPainter painter(this);
        painter.setPen(Qt::white);
        painter.setBrush(colors[i]);
        painter.drawEllipse(rects[i]); //drawing circle on the car

    }
}


void RacingGame::car_initialize(){
    int dys[5] = {0, -CAR_SIZE, 0, CAR_SIZE, 0}; //dy, dx technique
    int dxs[5] = {0, 0, CAR_SIZE, 0, -CAR_SIZE};

    bool firstTime = rects.empty();

    for (int i = 0; i < cars.count(); i++){ //setting the position of car
        int dir = track.dir(0);
        Position pos = track[0] + Position(dxs[dir], dys[dir]) * i;
        cars[i].setPosition(pos);

        if (firstTime){
            QRectF rectangle(pos.x - CAR_SIZE/2, pos.y - CAR_SIZE/2, CAR_SIZE, CAR_SIZE);
            rects.append(rectangle); //the rectangle is where the car is.
        }
    }
}

void RacingGame::make_new_track(){
    int dys[5] = {0, -CAR_SIZE, 0, CAR_SIZE, 0}; //dy, dx technique
    int dxs[5] = {0, 0, CAR_SIZE, 0, -CAR_SIZE};

    for (int i = 0; i < cars.count(); i++){
        Track new_track(track);
        int dir = new_track.dir(track.ways()-1);
        new_track.setEnd(track.end() + Position(dxs[dir], dys[dir]) * i);

        track_for_you.append(new_track);
    }
}

void RacingGame::startRace(){

    for (int i = 0; i < cars.count(); i++){
        Car * car = &cars[i];

        CarThread *carThread = new CarThread(car, &track_for_you[i]);

        connect(carThread, &CarThread::started, this, [this, i]() {set_stateLabel(i, MOVING);});
        connect(carThread, &CarThread::finished, this, [this, i]() {set_stateLabel(i, ARRIVED);});

        connect(car, &Car::positionChanged, this, &RacingGame::change_rect);
        connect(carThread, &CarThread::finished, carThread, &CarThread::deleteLater);
        carThread->start();
    }
}

void RacingGame::on_runButton_clicked()
{
    startRace();
}

void RacingGame::change_rect(){
    for (int i = 0; i < rects.count(); i++){
        Position pos = cars[i].getPostion();
        rects[i].moveTo(pos.x - CAR_SIZE/2, pos.y - CAR_SIZE/2);
    }
    update();
}


void RacingGame::on_startButton_clicked()
{
    car_initialize();
    for (int i = 0; i < cars.count(); i++){
        set_stateLabel(i, READY);
    }
}


void RacingGame::on_startButton_2_clicked()
{
    hide();
    SetDialog * setDialog = new SetDialog(); //좀 더 불러오기
    setDialog -> show();
}

void RacingGame::set_stateLabel(int carIndex, int state){
    QWidget * basePtr = ui->carInfo->itemAtPosition(1, carIndex)->widget();
    QLabel * carState = dynamic_cast<QLabel*>(basePtr);

    QString state_text[3] = {"ready", "moving...", "ARRIVED!"};
    QString color[3] = {"red", "green", "blue"};

    carState->setText("state: " + state_text[state]);
    if (state == ARRIVED){
        carState->setStyleSheet("QLabel { color : " + color[carIndex]
                                 + "; font-weight: bold; font-style: italic; }");
    }
    else{
        carState->setStyleSheet("");
    }
}
