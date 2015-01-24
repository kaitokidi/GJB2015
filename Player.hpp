#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : public Collisionable {
private:
    Dir::Direction direction;
    int state;
public:
    Player();
    Player(GameManager *gm);
    ~Player();
    void update(float deltaTime);
    void draw(sf::RenderTexture* render);
    void move(Dir::Direction dir);
    void jump(bool b);
    Dir::Direction getDirection();

};

#endif // PLAYER_H
