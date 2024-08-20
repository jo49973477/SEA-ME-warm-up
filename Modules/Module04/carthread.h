#ifndef CARTHREAD_H
#define CARTHREAD_H
#include <QThread>
#include <QMutex>
#include "car.h"
#include "track.h"



class CarThread : public QThread
{
    Q_OBJECT

    Car * car;
    Track * track;

    int now_road = 0;
public:
    CarThread(Car* car, Track* track, QThread * parent = nullptr);
    ~CarThread();
    CarThread(const CarThread& thread);
    CarThread operator=(const CarThread& thread);

    void run();
    bool arrived(Direction dir, Position now_pos, Position goal);
};

#endif // CARTHREAD_H
