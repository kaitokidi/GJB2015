#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : Collisionable {
private:
    Direction direction;
public:
    Player();
    ~Player();
    void update(float deltaTime);
    void draw();
    Direction getDirection();
};

#endif // PLAYER_H
