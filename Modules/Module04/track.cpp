#include "track.h"
#include <QDebug>

#define WAY_SIZE 30

Track::Track(QList<Position> route_pos, Position end): _end(end){
    this->route_pos = route_pos;

    for (int i = 0; i < route_pos.count(); i++){
        Position from_pos = route_pos[i];
        Position to_pos = i == route_pos.count()-1 ? _end : route_pos[i+1];

        if (from_pos.y == to_pos.y){
            if (from_pos.x < to_pos.x){
                route_dir.append(RIGHT);
            }
            else{
                route_dir.append(LEFT);
            }
        }
        else if (from_pos.x == to_pos.x){
            if (from_pos.y < to_pos.y){
                route_dir.append(BOTTOM);
            }
            else{
                route_dir.append(TOP);
            }
        }
        else{
            route_pos.insert(i, Position(to_pos.x, from_pos.y));
            if (to_pos.x > from_pos.x){
                route_dir.append(RIGHT);
            }
            else{
                route_dir.append(LEFT);
            }
            if (to_pos.y > from_pos.y){
                route_dir.append(BOTTOM);
            }
            else{
                route_dir.append(TOP);
            }
        }
    }
}

Track::~Track(){}

Track::Track(const Track& track):
    route_pos(track.route_pos), route_dir(track.route_dir), _end(track._end){}

Track Track::operator=(const Track& track){
    this->_end = track._end;
    this->route_dir = track.route_dir;
    this->route_pos = track.route_pos;

    return *this;
}

void Track::setEnd(Position pos){
    _end = pos;
}

Position Track::end(){
    return _end;
}

Position Track::start(){
    if (route_pos.size() == 0){
        return Position(0,0);
    }
    return route_pos[0];
}

Position Track::operator[](int index){
    return pos(index);
}

Position Track::pos(int index){
    if (index < 0 or index > route_pos.size()){
        return Position(0,0);
    }
    else if (index == route_pos.size()){
        return _end;
    }
    else{
        return route_pos[index];
    }
}

Direction Track::dir(int index){
    if (index < 0 or index >= route_dir.size()){
        return PAUSE;
    }
    else{
        return route_dir[index];
    }
}

int Track::dots(){
    return route_dir.count() + 1;
}

int Track::ways(){
    return route_dir.count();
}

void Track::debug(){
    for (int i = 0; i < dots(); i++){
        qDebug() << pos(i).x << pos(i).y << dir(i) << '\n';
    }
}

Position Track::track_pos(int index){
    if (index < 0 or index >= route_dir.size()){
        return Position(-1, -1);
    }
    else{
        Position from_pos = pos(index);
        Position to_pos = pos(index+1);

        switch (dir(index)){
        case BOTTOM:
        case RIGHT:
            from_pos.x -= WAY_SIZE / 2;
            from_pos.y -= WAY_SIZE/ 2;
            return from_pos;
        case TOP:
        case LEFT:
            to_pos.x -= WAY_SIZE/ 2;
            to_pos.y -= WAY_SIZE / 2;
            return to_pos;
        default:
            return Position(-1, -1);
        }
    }
}

Position Track::track_size(int index){
    if (index < 0 or index >= route_dir.size()){
        return Position(-1, -1);
    }
    else{
        Position from_pos = pos(index);
        Position to_pos = pos(index + 1);
        int track_len;

        switch(dir(index)){
        case TOP:
        case BOTTOM:
            track_len = abs(to_pos.y - from_pos.y);
            return Position(WAY_SIZE, track_len + WAY_SIZE);
        case RIGHT:
        case LEFT:
            track_len = abs(to_pos.x - from_pos.x);
            return Position(track_len + WAY_SIZE, WAY_SIZE);
        default:
            return Position(-1, -1);
        }
    }
}


//아마 뒤에 position하고 size 넣는 것이나 move 하는 것 정도 넣어두면 좋을듯
