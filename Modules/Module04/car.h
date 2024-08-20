#ifndef CAR_H
#define CAR_H
#include "position.h"
#include <QObject>

class Car: public QObject
{
    Q_OBJECT

    QString name = "";
    Position pos;
    double speed;
    Direction dir;
public:
    Car(QObject *parent = nullptr);
    Car(QString name, Position pos, double speed, Direction dir, QObject *parent = nullptr);
    ~Car();
    Car(const Car& car);
    Car operator=(const Car& car);

    void setName(QString name);
    void setPosition(Position pos);
    void setSpeed(double speed);
    void setDirection(Direction dir);
    QString getName();
    Position getPostion() const;
    double getSpeed() const;
    Direction getDirection() const;
    void move(double sec);

signals:
    void positionChanged();
};

#endif // CAR_H
