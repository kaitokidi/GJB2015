#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : Collisionable {
private:
    Dir::Direction direction;
    int stat;
public:
    Player();
    ~Player();
    void update(float deltaTime);
    void draw();
    void move(Dir::Direction dir);
    Dir::Direction getDirection();

};

#endif // PLAYER_H
