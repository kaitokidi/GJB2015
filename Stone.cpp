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
    if(direction == Dir::none){
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[0]*deltaTime;
            if(speed.x < 0) speed.x = 0;
        }
        else if( speed.x < 0) {
            speed.x += 1.5*PLAYER_ACCELERATION[0]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    else if(direction == Dir::left){
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[0]*deltaTime;
        }
        else {
            speed.x -= PLAYER_ACCELERATION[0]*deltaTime;
            if (speed.x < -PLAYER_MAX_SPEED[0]) speed.x = -PLAYER_MAX_SPEED[0];
        }
    }
    else if(direction == Dir::right){
        if (speed.x >= 0) {
            speed.x += PLAYER_ACCELERATION[0]*deltaTime;
            if(speed.x > PLAYER_MAX_SPEED[0]) speed.x = PLAYER_MAX_SPEED[0];
        }
        else {
            speed.x += 1.5*PLAYER_ACCELERATION[0]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    speed.y += GRAVITY*deltaTime;

    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    
    if (collisionVertical(x,y+deltaTime*speed.y)) speed.y = 0;
    if (collisionHorizontal(x+deltaTime*speed.x,y)) speed.x = 0;
   
    sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);

}



