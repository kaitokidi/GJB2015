#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : Collisionable {
private:
    Dir::Direction direction;
    int state;
public:
    Player();
    Player(GameManager *gm);
    ~Player();
    void update(float deltaTime);
    void draw();
    void move(Dir::Direction dir);
    Dir::Direction getDirection();

};
//sida

#endif // PLAYER_H
