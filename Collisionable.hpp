#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "utils.hpp"

class Collisionable {
protected:
    sf::Sprite sprite;
    sf::Vector2f speed;
    int spriteWidth;
    int spriteHeight;
    int nSpriteX;
    int nSpriteY;

public:
    Collisionable();
    Collisionable(sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY);
    virtual void update(float deltaTime) = 0;
    int getWidth();
    int getHeight();
    int getNSpriteX();
    int getNSpriteY();
    sf::Vector2f getSpeed();
    sf::Vector2f getPosition();
    static bool areCollisioning(Collisionable *a, Collisionable *b);
};

#endif // COLLISIONABLE_H
