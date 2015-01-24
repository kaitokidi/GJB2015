#include "Collisionable.hpp"
#include "GameManager.hpp"

Collisionable::Collisionable() {

}

Collisionable::Collisionable(GameManager *gm, sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY) {
    this->gm = gm;
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

bool Collisionable::areCollisioning(Collisionable *a, Collisionable *b) {
    if(a->getPosition().x > b->getPosition().x + b->getWidth()) return false;
    if(a->getPosition().x + a->getWidth() < b->getPosition().x) return false;
    if(a->getPosition().y > b->getPosition().y + b->getHeight()) return false;
    if(a->getPosition().y + a->getHeight() < b->getPosition().y) return false;
    return true;
}

bool Collisionable::collisionBackground() {
    int x = sprite.getPosition().x;
    int y = sprite.getPosition().y;
    if (gm->getBoard()->getPixelColor(x,y) == "Black") speed.x = 0;
    else if (gm->getBoard()->getPixelColor(x+spriteWidth,y) == "Black") speed.x = 0;
    if (gm->getBoard()->getPixelColor(x,y+spriteHeight) == "Black") {
        onGround = true;
        speed.y = 0;
    }
    else if (gm->getBoard()->getPixelColor(x+spriteWidth,y+spriteHeight) == "Black") {
        onGround = true;
        speed.y = 0;
    }
    return true;
}
