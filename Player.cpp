#include "Player.hpp"
#include "Stone.hpp"
#include "Resources.hpp"
#include "GameManager.hpp"

Player::Player() {}


Player::Player(GameManager *gm) /*: Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1)*/:
    Collisionable(gm, &Resources::playerTexture, Resources::playerTexture.getSize().x/4, Resources::playerTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    state = PState::legs;
    spriteSource = sf::Vector2u(0,Dir::none);
    scont = 0;
    time_to_next_sprite = 0.1;
    sprite.setPosition(2800,1000);
    jumping = false;
    jumpTimer = 0;
}


Player::Player(GameManager *gm, float px, float py) /*: Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1)*/:
    Collisionable(gm, &Resources::playerTexture, Resources::playerTexture.getSize().x/4, Resources::playerTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    state = PState::legs;
    spriteSource = sf::Vector2u(0,Dir::none);
    scont = 0;
    time_to_next_sprite = 0.1;
    sprite.setPosition(px,py);
}

Player::~Player() {

}


void Player::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

void Player::jump(bool jump){
    if (onGround && jump) {
        jumping = true;
        speed.y = 0;
        jumpTimer = PLAYER_JUMP_TIME[state]/1000;
    }
    else if (!(jumping && jump)) jumping = false;
}

Dir::Direction Player::getDirection() {
    return direction;
}

void Player::update(float deltaTime) {
    if (jumping && jumpTimer > 0) {
        speed.y = -PLAYER_JUMP_SPEED;
        jumpTimer -= deltaTime;
    }
    else speed.y += GRAVITY*deltaTime;
    if(direction == Dir::none){
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[state]*deltaTime;
            if(speed.x < 0) speed.x = 0;
        }
        else if( speed.x < 0) {
            speed.x += 1.5*PLAYER_ACCELERATION[state]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    else if(direction == Dir::left){
        if (speed.x > 0){
            speed.x -= 1.5*PLAYER_ACCELERATION[state]*deltaTime;
        }
        else {
            speed.x -= PLAYER_ACCELERATION[state]*deltaTime;
            if (speed.x < -PLAYER_MAX_SPEED[state]) speed.x = -PLAYER_MAX_SPEED[state];
        }
    }
    else if(direction == Dir::right){
        if (speed.x >= 0){
            speed.x += PLAYER_ACCELERATION[state]*deltaTime;
            if(speed.x > PLAYER_MAX_SPEED[state]) speed.x = PLAYER_MAX_SPEED[state];
        }
        else {
            speed.x += 1.5*PLAYER_ACCELERATION[state]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }


    //Colisions amb el mon & moviment
    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;
    
    int collision1 = collisionVertical(x,y+deltaTime*speed.y);
    int collision2 = collisionHorizontal(x+deltaTime*speed.x,y);
    if (collision1 == 2 || collision2 == 2) {
        speed = sf::Vector2f(0,0);
        sprite.setPosition(lastGround);
    }
    else {
        if (collision1) {
            if (speed.y > 0) onGround = true;
            speed.y = 0;
        }
        else onGround = false;
        if (collision2) speed.x = 0;

        //colisions amb caixes
        for(uint i = 0; i < this->gm->getStones().size();++i){
            Collisionable* c = gm->getStones()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c)) {
                if (y+spriteHeight < c->getPosition().y) {
                    speed.y = 0;
                    onGround = true;
                }
                else {
                    speed.x = 0;
                    c->move(direction);
                }
            }
        }
        
        //colisions Doors
        for(uint i = 0; i < this->gm->getDoors().size();++i){
            Collisionable* c = gm->getDoors()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c)) {
                if (y+spriteHeight < c->getPosition().y) {
                    speed.y = 0;
                }
                else {
                    speed.x = 0;
                }
            }
        }
        
        //colisions Buttons
        for(uint i = 0; i < this->gm->getButtons().size();++i){
            Collisionable* c = gm->getButtons()[i];
            Collisionable p = *this;
            p.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
            if (Collisionable::areCollisioning(&p, c)) {
                if (gm->getButtons()[i]->getID() == 1) { //aball
                    gm->getDoors()[1]->moveDown(true);
                }
                else {
                    gm->getDoors()[gm->getButtons()[i]->getID()]->moveUp(true);
                }
            }
        }
        
        
        sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
    }
    if (onGround) lastGround = sprite.getPosition();
    
    if (!onGround) spriteSource.y = Dir::down;
    else {
        scont += deltaTime;
        if (speed.x > 0) spriteSource.y = Dir::right;
        else if (speed.x == 0) spriteSource.y = Dir::none;
        else spriteSource.y = Dir::left;

        if (scont >= time_to_next_sprite){
            scont = 0;
            spriteSource.x = (spriteSource.x+1)%nSpriteX;
        }
    }
    std::cout << "bounds player " << x << " " << y << " " << sprite.getGlobalBounds().width << " " << sprite.getGlobalBounds().height << std::endl;
    sprite.setTextureRect(sf::IntRect(spriteSource.x*spriteWidth,
                                      spriteSource.y*spriteHeight, spriteWidth, spriteHeight));

}



