#ifndef POSITION_H
#define POSITION_H

struct Position{
    double x, y;

    Position(double x, double y): x(x), y(y) {}
    Position(const Position & pos): x(pos.x), y(pos.y) {}

    Position operator=(const Position& pos){
        this->x = pos.x;
        this->y = pos.y;
        return * this;
    }

    Position operator+(const Position& pos){
        this->x += pos.x;
        this->y += pos.y;
        return * this;
    }

    Position operator-(const Position& pos){
        this->x -= pos.x;
        this->y -= pos.y;
        return * this;
    }

    Position operator*(int a){
        this->x *= a;
        this->y *= a;
        return * this;
    }
};

enum Direction{
    PAUSE,
    TOP,
    RIGHT,
    BOTTOM,
    LEFT
};

#endif // POSITION_H
