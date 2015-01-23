#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : Collisionable {
public:
    Player();
    ~Player();
    void update(float deltaTime);
    void draw();
};

#endif // PLAYER_H
