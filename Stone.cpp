#include "Stone.hpp"
#include "Resources.hpp"

Stone::Stone() {}

Stone::Stone(GameManager *gm, float px, float py, float sx, float sy) 
    : Collisionable(gm, &Resources::stoneTexture, sx, sy, 1, 1) {
    direction = Dir::none;
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
}

Stone::~Stone() {
    
}


void Stone::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

Dir::Direction Stone::getDirection() {
    return direction;
}

void Stone::update(float deltaTime) {
    float stoneAceleration = 200;
    float maxSpeed = 150;
    if(direction == Dir::none){
        if (speed.x > 0){
            speed.x -= 1.5*stoneAceleration*deltaTime;
            if(speed.x < 0) speed.x = 0;
        }
        else if( speed.x < 0) {
            speed.x += 1.5*stoneAceleration*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    else if(direction == Dir::left)  speed.x = -maxSpeed;
    else if(direction == Dir::right) speed.x = maxSpeed;
    speed.y += GRAVITY*deltaTime;

    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    
    if (collisionVertical(x,y+deltaTime*speed.y)) speed.y = 0;
    if (collisionHorizontal(x+deltaTime*speed.x,y)) speed.x = 0;

    sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
    direction = Dir::none;
}



