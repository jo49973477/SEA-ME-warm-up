#include "carthread.h"
#include "qDebug"
#define MOVE_INTERVAL 0.01

CarThread::CarThread(Car* car, Track* track, QThread * parent): QThread(parent), car(car), track(track){}

CarThread::~CarThread(){}

CarThread::CarThread(const CarThread& thread):
    QThread(thread.parent()), car(thread.car), track(thread.track), now_road(thread.now_road){}

CarThread CarThread::operator=(const CarThread& thread){
    this->car = thread.car;
    this->track = thread.track;
    this->now_road = thread.now_road;

    return *this;
}

void CarThread::run(){

    for (int i = 0; i < track->ways(); i++){

        Direction current_dir = track->dir(i);
        car->setDirection(current_dir);

        while(!arrived(car->getDirection(), car->getPostion(), track->pos(i+1))){
            car->move(MOVE_INTERVAL);
            msleep(1000 * MOVE_INTERVAL);
        }
    }
}

bool CarThread::arrived(Direction dir, Position now_pos, Position goal){
    switch(dir){
    case TOP:
        return (now_pos.y <= goal.y);
    case RIGHT:
        return (now_pos.x >= goal.x);
    case BOTTOM:
        return (now_pos.y >= goal.y);
    case LEFT:
        return (now_pos.x <= goal.x);
    default:
        return true;
    }
}
