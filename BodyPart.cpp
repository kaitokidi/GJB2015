#include "BodyPart.hpp"
#include "Resources.hpp"

BodyPart::BodyPart() {}

BodyPart::BodyPart(GameManager *gm, float px, float py, float sx, float sy, int idBody) 
    : Collisionable(gm, &Resources::bodyPartTexture, sx, sy, 1, 1) {
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
    id= idBody;
    sprite.setPosition(3000, 1000);
}

BodyPart::~BodyPart() {
    
}
int BodyPart::getId(){
    return id;
}

void BodyPart::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}


void BodyPart::update(float deltaTime) {

}



