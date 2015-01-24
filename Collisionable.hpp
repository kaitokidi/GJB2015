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
    Dir::Direction direction;
public:
    Collisionable();
    Collisionable(GameManager *gm, sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY);
    int getWidth();
    int getHeight();
    int getNSpriteX();
    int getNSpriteY();
    sf::Vector2f getSpeed();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    static bool areCollisioning(Collisionable *a, Collisionable *b);
    int collisionVertical(float x, float y);
    int collisionHorizontal(float x, float y);
    void move(Dir::Direction dir);
};

#endif // COLLISIONABLE_H
