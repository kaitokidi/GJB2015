#include "Hammer.hpp"
#include "Resources.hpp"

Hammer::Hammer() {}

Hammer::Hammer(GameManager *gm, float px, float py, float sx, float sy) 
    : Collisionable(gm, &Resources::hammerText, sx, sy, 1, 1) {

    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
}

Hammer::~Hammer() {
    
}

void Hammer::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}
void Hammer::modPos(float px, float py){
    sprite.setPosition(px,py);
}


void Hammer::update(float deltaTime) {

}



