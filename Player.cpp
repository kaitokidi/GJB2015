#include "Player.hpp"
#include "Resources.hpp"

Player::Player() {}


Player::Player(GameManager *gm) /*: Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1)*/:
    Collisionable(gm, &Resources::playerTexture, Resources::playerTexture.getSize().x/4, Resources::playerTexture.getSize().y/4, 4, 4) {
    direction = Dir::none;
    state = PState::shoes;
    spriteSource = sf::Vector2u(0,Dir::none);
    scont = 0;
    time_to_next_sprite = 0.1;
}

Player::~Player() {
	
}


void Player::draw(sf::RenderWindow* render) {
    render->draw(sprite);
}

void Player::jump(bool b){
//    if (onGround)
    speed.y = -300;
}
void Player::move(Dir::Direction dir) {
    direction = dir;
}

Dir::Direction Player::getDirection() {
    return direction;
}

void Player::update(float deltaTime) {

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
		//si et movies en direccio contraria
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
		//si et movies en direccio contraria
        else if(speed.x < 0){
            speed.x += 1.5*PLAYER_ACCELERATION[state]*deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
	}
    speed.y += GRAVITY * deltaTime;

    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;

    if (collisionMap(x,y+deltaTime*speed.y)) {
        if (speed.y > 0) onGround = true;
        speed.y = 0;
    }
    else onGround = false;
    if (collisionMap(x+deltaTime*speed.x,y)) {
        speed.x = 0;
    }
    if (collisionMap(x+deltaTime*speed.x,y+deltaTime*speed.y)) {
        if (speed.y > 0) onGround = true;
        speed.x = 0;
        speed.y = 0;
    }
    sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);


    scont += deltaTime;
    if (!onGround) spriteSource.y = Dir::down;
    else if (speed.x > 0) spriteSource.y = Dir::right;
    else if (speed.x == 0) spriteSource.y = Dir::none;
    else spriteSource.y = Dir::left;

    if (scont >= time_to_next_sprite){
        scont = 0;
        spriteSource.x = (spriteSource.x+1)%nSpriteX;
    }
    sprite.setTextureRect(sf::IntRect(spriteSource.x*spriteWidth,
                                      spriteSource.y*spriteHeight, spriteWidth, spriteHeight));

}



