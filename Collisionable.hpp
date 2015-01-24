#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "utils.hpp"

class GameManager;
class Collisionable {
protected:
    GameManager *gm;
    sf::Sprite sprite;
    sf::Vector2f speed;
    int spriteWidth;
    int spriteHeight;
    int nSpriteX;
    int nSpriteY;
    bool onGround;

public:
    Collisionable();
    Collisionable(GameManager *gm, sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY);
    virtual void update(float deltaTime) = 0;
    int getWidth();
    int getHeight();
    int getNSpriteX();
    int getNSpriteY();
    sf::Vector2f getSpeed();
    sf::Vector2f getPosition();
    static bool areCollisioning(Collisionable *a, Collisionable *b);
    int collisionMap(float x, float y);

};

#endif // COLLISIONABLE_H
