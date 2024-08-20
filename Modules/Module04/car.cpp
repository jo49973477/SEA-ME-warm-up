#include "car.h"

Car::Car(QObject *parent):QObject(parent) ,pos(Position(0,0)), speed(1), dir(PAUSE){}

Car::Car(QString name, Position pos, double speed, Direction dir, QObject *parent):
    QObject(parent), name(name), pos(pos), speed(speed), dir(dir){}

Car::~Car(){}

Car::Car(const Car& car):
    name(car.name), pos(car.pos), speed(car.speed), dir(car.dir){}


Car Car::operator=(const Car& car){
    this->name = car.name;
    this->pos = car.pos;
    this->speed = car.speed;
    this->dir = car.dir;

    return *this;
}

void Car::setName(QString name){
    this->name = name;
}

void Car::setPosition(Position pos){
    this->pos = pos;
    emit positionChanged();
}

void Car::setSpeed(double speed){
    this->speed = speed;
}

void Car::setDirection(Direction dir){
    this->dir = dir;
}

QString Car::getName(){
    return name;
}

Position Car::getPostion() const{
    return pos;
}

double Car::getSpeed() const{
    return speed;
}

Direction Car::getDirection() const{
    return dir;
}

void Car::move(double sec){
    double dist = speed*sec;
    double dys[5] = {0, -dist, 0   , dist, 0};
    double dxs[5] = {0, 0    , dist, 0   , -dist};

    pos = pos + Position(dxs[dir], dys[dir]);
    emit positionChanged();

}
