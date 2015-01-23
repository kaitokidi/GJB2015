#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"

class Player:Colisionable {
public:
    Player(int scrwidth, int scrheight, std::string title, int style);
    ~Player();
    void update(float deltaTime) = 0;
    void draw() = 0;
};

#endif // PLAYER_H
