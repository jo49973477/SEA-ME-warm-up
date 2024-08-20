#ifndef TRACK_H
#define TRACK_H

#include "position.h"
#include "qlist.h"

class Track
{
    QList<Position> route_pos;
    QList<Direction> route_dir;
    Position _end;
public:
    Track(QList<Position> route_pos, Position _end);
    ~Track();
    Track(const Track& track);
    Track operator=(const Track& track);

    void setEnd(Position pos);
    Position end();
    Position start();
    Position operator[](int index);
    Position pos(int index);
    Direction dir(int index);
    int dots();
    int ways();
    Position track_pos(int index);
    Position track_size(int index);

    void debug();
};

#endif // TRACK_H
