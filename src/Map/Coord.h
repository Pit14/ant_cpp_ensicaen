//
// Created by edgar on 28/11/2018.
//
using namespace std;

#ifndef C_COORD_H
#define C_COORD_H


class Coord {
public:
    Coord(int x, int y);
    //Coord();

    virtual ~Coord();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

private:

    int x;
    int y;

};


#endif //C_COORD_H
