#include "Button.hpp"
#include "Resources.hpp"

Button::Button() {}



Button::Button(GameManager *gm, float px, float py, float sx, float sy, int ide) 
    : Collisionable(gm, &Resources::buttonTexture, sx, sy, 1, 1) {
    id = ide;
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
}

Button::~Button() {
    
}


void Button::draw(sf::RenderWindow* render) {
    render->draw(sprite);
}

void Button::update(float deltaTime) {

}

int Button::getID(){
    return id;
}

