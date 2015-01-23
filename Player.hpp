#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"

class Player:Colisionable {
public:
    Player();
    ~Player();
    void update(float deltaTime);
    void draw();
};

#endif // PLAYER_H
