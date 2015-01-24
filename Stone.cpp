#include "Stone.hpp"
#include "Resources.hpp"

Stone::Stone() {}


Stone::Stone(GameManager *gm) :
    Collisionable(gm, &Resources::stoneTexture, Resources::stoneTexture.getSize().x/4, Resources::stoneTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    sprite.setPosition(0,0);
}

Stone::Stone(GameManager *gm, float px, float py) 
    : Collisionable(gm, &Resources::stoneTexture, Resources::stoneTexture.getSize().x/4, Resources::stoneTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    sprite.setPosition(px,py);
}

Stone::Stone(GameManager *gm, float px, float py, float sx, float sy) 
    : Collisionable(gm, &Resources::stoneTexture, Resources::stoneTexture.getSize().x, Resources::stoneTexture.getSize().y, px, py) {
    direction = Dir::none;
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
}

Stone::~Stone() {
    
}


void Stone::draw(sf::RenderWindow* render) {
    render->draw(sprite);
}


void Stone::move(Dir::Direction dir) {
    direction = dir;
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
        if (speed.x >= 0){
            speed.x += PLAYER_ACCELERATION[0]*deltaTime;
            if(speed.x > PLAYER_MAX_SPEED[0]) speed.x = PLAYER_MAX_SPEED[0];
        }
        else if(speed.x < 0){
            speed.x += 1.5*PLAYER_ACCELERATION[0]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    speed.y += GRAVITY*deltaTime;

    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    
    if (collisionMap(x,y+deltaTime*speed.y)) {
        if (speed.y > 0) onGround = true;
        speed.y = 0;
    }
    else {
        onGround = false;
    }
    if (collisionMap(x+deltaTime*speed.x,y)) {
        speed.x = 0;
    }
   
    sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);

}



