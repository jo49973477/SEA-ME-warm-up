#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>
#include <QPainter>
#include "car.h"
#include "track.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RacingGame;
}
QT_END_NAMESPACE

class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    RacingGame(QList<Car> cars= {Car()}, Track track= Track({Position(50, 300)}, Position(750, 300)), QWidget *parent = nullptr);
    ~RacingGame();

    void drawing_car();
    void car_initialize();
    virtual void paintEvent(QPaintEvent * e);
    void make_new_track();

    void startRace();

private slots:
    void on_runButton_clicked(); //RUN FOREST RUN!
    void change_rect();
    void on_startButton_clicked();
    void on_startButton_2_clicked();
    void set_stateLabel(int carIndex, int state);

private:
    Ui::RacingGame *ui;
    QList<Car> cars;
    Track track;
    QList<QRectF> rects;
    QList<Track> track_for_you;
};
#endif // RACINGGAME_H
