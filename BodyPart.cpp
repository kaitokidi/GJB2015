#include "BodyPart.hpp"
#include "Resources.hpp"

BodyPart::BodyPart() {}

BodyPart::BodyPart(GameManager *gm, float px, float py, float sx, float sy, int idBody) 
    : Collisionable(gm, &Resources::bodyPartTexture, sx, sy, 1, 1) {
    
        switch (idBody){
            case 0:
                sprite.setTexture(Resources::shoesText);
                break;
            case 1:
                sprite.setTexture(Resources::legsText);
                break;
            case 2:
                sprite.setTexture(Resources::bodyText);
                break;
            case 3:
                sprite.setTexture(Resources::armsText);
                break;
            case 4:
                sprite.setTexture(Resources::handText);
                break;
            case 5:
                sprite.setTexture(Resources::headText);
                break;
            case 6:
                sprite.setTexture(Resources::wingsText);
                break;
            default:
                break;
                
        }
    
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
    id= idBody;
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



