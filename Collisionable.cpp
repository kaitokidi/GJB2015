#include "Collisionable.hpp"

Collisionable::Collisionable(sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY) {
    sprite.setTexture(*text);
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->nSpriteX = nSpriteX;
    this->nSpriteY = nSpriteY;
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

bool Collisionable::areCollisioning(Collisionable a, Collisionable b) {
    if(a.getPosition().x > b.getPosition().x + b.getWidth()) return false;
    if(a.getPosition().x + a.getWidth() < b.getPosition().x) return false;
    if(a.getPosition().y > b.getPosition().y + b.getHeight()) return false;
    if(a.getPosition().y + a.getHeight() < b.getPosition().y) return false;
    return true;
}
