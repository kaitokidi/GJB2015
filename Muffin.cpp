#include "Muffin.hpp"
#include "Resources.hpp"

Muffin::Muffin() {}

Muffin::Muffin(GameManager *gm, float px, float py, float sx, float sy) 
    : Collisionable(gm, &Resources::muffinText, sx, sy, 1, 1) {

    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
}

Muffin::~Muffin() {
    
}

void Muffin::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}
void Muffin::modPos(float px, float py){
    sprite.setPosition(px,py);
}


void Muffin::update(float deltaTime) {
    (void) deltaTime;
}



