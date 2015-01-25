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
void Collisionable::modTexture(sf::Texture *text, int spriteWidth, int spriteHeight, int nSpriteX, int nSpriteY){
    sprite.setTexture(*text);
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
    this->nSpriteX = nSpriteX;
    this->nSpriteY = nSpriteY;
}

bool Collisionable::areCollisioning(Collisionable *a, Collisionable *b) {
    int n = 30;
    if(a->getPosition().x +n > b->getPosition().x + b->getWidth()) return false;
    if(a->getPosition().x + a->getWidth() - n < b->getPosition().x) return false;
    if(a->getPosition().y > b->getPosition().y + b->getHeight()) return false;
    if(a->getPosition().y + a->getHeight() < b->getPosition().y) return false;
    return true;
}

int Collisionable::collisionVertical(float x, float y) {
    int m = 30;
    int n = 20;
    int maxX = spriteWidth-2*m;
    std::string color;
    for (int i = 0; i < maxX; i +=  maxX/n) {
        color = gm->getBoard()->getPixelColor(x+m+i,y);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = (gm->getBoard()->getPixelColor(x+m+i,y+spriteHeight));
        if (color == "Red") return 2;
        if (color == "Black") return 1;
    }
    return 0;
}


int Collisionable::collisionHorizontal(float x, float y) {
    int n = 20;
    int maxY = spriteHeight;
    std::string color;
    for (int j = 0; j < maxY; j +=  maxY/n) {
        color = gm->getBoard()->getPixelColor(x + 30,y+j);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = gm->getBoard()->getPixelColor(x+spriteWidth - 30,y+j);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
    }
    return 0;
}
int Collisionable::collisionVertical(float x, float y, int lvl) {
    int m = 30;
    int n = 20;
    int maxX = spriteWidth-2*m;
    int maxY = spriteHeight;
    int elValor=0;
    if(lvl==1) elValor=80;
    else if(lvl==2) elValor=80;
    else if(lvl==3 || lvl==4 ) elValor=100;
    std::string color;
    for (int i = 0; i < maxX; i +=  maxX/n) {
        color = gm->getBoard()->getPixelColor(x+m+i,y+elValor);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = (gm->getBoard()->getPixelColor(x+m+i,y+maxY));
        if (color == "Red") return 2;
        if (color == "Black") return 1;
    }
    return 0;
}
int Collisionable::collisionHorizontal(float x, float y, int lvl) {
    int n = 20;
    int maxY = spriteHeight;
    int elValor=0;
    if(lvl==1) elValor=80;
    else if(lvl==2) elValor=80;
    else if(lvl==3 || lvl==4) elValor=100;
    std::string color;
    for (int j = 0; j < maxY-elValor; j +=  (maxY-elValor)/n) {
        std::cout << "soy yo " << j  << " " << y+maxY << " " << y+j+elValor << std::endl; 
        color = gm->getBoard()->getPixelColor(x + 30, y + j + elValor);
        if (color == "Red") return 2;
        if (color == "Black") return 1;
        color = gm->getBoard()->getPixelColor(x+spriteWidth - 30,y+elValor+j);
        if (color == "Red") return 2;
        if (color == "Black") return 1;

    }
    return 0;
}

void Collisionable::move(Dir::Direction dir) {
    direction = dir;
}

