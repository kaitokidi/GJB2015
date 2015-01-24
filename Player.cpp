#include "Player.hpp"
#include "Resources.hpp"

Player::Player() {}

Player::Player(GameManager *gm) : Collisionable(gm, &Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 4, 4){
    direction = Dir::none;
    state = PState::shoes;
}

Player::~Player() {
	
}


void Player::draw(sf::RenderWindow* render) {
    render->draw(sprite);
}

void Player::jump(bool b){
    speed.y = -100;
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

//    if (collisionMap(x,y+deltaTime*speed.y)) {
//        speed.y = 0;
//        if (speed.y > 0) onGround = true;
//    }
//    if (collisionMap(x+deltaTime*speed.x,y)) {
//        speed.x = 0;
//    }
    sprite.setPosition(sprite.getPosition().x+speed.x*deltaTime,sprite.getPosition().y+speed.y*deltaTime);
}



