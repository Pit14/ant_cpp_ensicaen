//
// Created by edgar on 29/11/2018.
//

#ifndef C_SCOUT_H
#define C_SCOUT_H


#include "Ant.h"
#include "../Map/Grid.h"

class Scout: public Ant {

private:
    bool is_minor;
public:

    void setIs_minor(bool is_minor);

    virtual void die();
    void move(int x, int y);
    void find_move();
    virtual bool eat();
    virtual bool update();
    Scout(Nest *n);
    bool try_to_move(int x, int y,Cell ** m);
    void discoverMap(int x,int y);
    void discoverMapLoop(int x,int y);
    bool checkNeighbourFog(int x, int y);
    bool isInFog( int x, int y);
    std::vector <int> checkAllNeighbour( int x, int y);

};


#endif //C_SCOUT_H
