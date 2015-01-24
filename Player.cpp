#include "Player.hpp"
#include "Resources.hpp"


Player::Player() : Collisionable(&Resources::playerTexture, PLAYER_SIZE_X[PState::shoes], PLAYER_SIZE_Y[PState::shoes], 1, 1){
    //sprite.setTexture(Resources::playerTexture);
    direction = Dir::none;
    stat = PState::shoes;

}

Player::~Player() {
	
}


void Player::draw() {

}

void Player::move(Dir::Direction dir) {
    direction = dir;
}

Dir::Direction Player::getDirection() {
    return direction;
}

void Player::update(float deltaTime) {
	if(direction==Dir::none){
		if(speed.x>0){
			speed.x=-1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x<0)speed.x=0;
		}
		else if(speed.x<0){
			speed.x=1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x>0)speed.x=0;
		}
		speed.y=-GRAVITY*deltaTime + speed.y;
	}
	if(direction==Dir::left){
		if(speed.x>0){
			speed.x=-1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x<0)speed.x=0;
		}
		else if(speed.x<0){
			speed.x=1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x>0)speed.x=0;
		}
		speed.y=-GRAVITY*deltaTime + speed.y;
	}
	if(direction==Dir::right){
		speed.x= PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
		speed.y=-GRAVITY*deltaTime + speed.y;
	}
}




