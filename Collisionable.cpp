#include "Collisionable.hpp"
#include "GameManager.hpp"
#include "utils.hpp"

Collisionable::Collisionable() {

}

Collisionable::Collisionable(GameManager* gm, sf::Texture* text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY) {
    this->gm = gm;
    sprite.setTexture(*text);
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->nSpriteX = nSpriteX;
    this->nSpriteY = nSpriteY;
    speed = sf::Vector2f(0,0);
}

int Collisionable::getWidth() {
    return spriteWidth;
}

int Collisionable::getHeight() {
    return spriteHeight;
}

int Collisionable::getNSpriteX() {
    return nSpriteX;
}

int Collisionable::getNSpriteY() {
    return nSpriteY;
}

sf::Vector2f Collisionable::getSpeed() {
    return speed;
}

sf::Vector2f Collisionable::getPosition() {
    return sprite.getPosition();
}

void Collisionable::setPosition(float x,float y) {
    sprite.setPosition(sf::Vector2f(x,y));
}

bool Collisionable::areCollisioning(Collisionable *a, Collisionable *b) {
    if(a->getPosition().x > b->getPosition().x + b->getWidth()) return false;
    if(a->getPosition().x + a->getWidth() < b->getPosition().x) return false;
    if(a->getPosition().y > b->getPosition().y + b->getHeight()) return false;
    if(a->getPosition().y + a->getHeight() < b->getPosition().y) return false;
    return true;
}

int Collisionable::collisionVertical(float x, float y) {
    int n = 20;
    int maxX = sprite.getTexture()->getSize().x/nSpriteX;
    std::string color;
    for (int i = 0; i < maxX; i +=  maxX/n) {
        color = gm->getBoard()->getPixelColor(x+i,y);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = (gm->getBoard()->getPixelColor(x+i,y+spriteHeight));
        if (color == "Red") return 2;
        if (color == "Black") return 1;
    }
    return 0;
}

int Collisionable::collisionHorizontal(float x, float y) {
    int n = 20;
    int maxY = sprite.getTexture()->getSize().y/nSpriteY;
    std::string color;
    for (int j = 0; j < maxY; j +=  maxY/n) {
        color = gm->getBoard()->getPixelColor(x,y+j);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = gm->getBoard()->getPixelColor(x+spriteWidth,y+j);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
    }
    return 0;
}

void Collisionable::move(Dir::Direction dir) {
    direction = dir;
}

