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
    sf::FloatRect bBox;
    
public:
    Collisionable();
    Collisionable(GameManager *gm, sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY);
    void setBBox(float offsetX, float offsetY, float width, float height);
    int getWidth();
    int getHeight();
    int getNSpriteX();
    int getNSpriteY();
    void modTexture(sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY);
    sf::Vector2f getSpeed();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    static bool areCollisioning(Collisionable *a, Collisionable *b);
    int collisionVertical(float x, float y);
    int collisionHorizontal(float x, float y);
    void move(Dir::Direction dir);
};

#endif // COLLISIONABLE_H
