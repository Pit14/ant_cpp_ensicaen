//
// Created by edgar on 29/11/2018.
//

#ifndef C_SCOUT_H
#define C_SCOUT_H


#include "Ant.h"

class Scout: public Ant {

private:
    bool is_minor;
public:
    bool isIs_minor() const;

    void setIs_minor(bool is_minor);

    virtual void die();
    void move(Coord c);
    void find_move();
    virtual void eat();
    virtual void update();
    Scout(Nest *n);
    void setC(Coord *c,int x, int y);
    void discoverMap(int x,int y);

};


#endif //C_SCOUT_H
