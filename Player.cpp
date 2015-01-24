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

void Player::jump(bool b){

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
		//si et movies en direccio contraria
		if(speed.x>0){
			speed.x=-1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x<0)speed.x=0;
		}
		else if(speed.x<=0 && speed.x>-PLAYER_MAX_SPEED[stat]){
			speed.x=-PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x>0)speed.x=0;
			if(speed.x<-PLAYER_MAX_SPEED[stat])speed.x=-PLAYER_MAX_SPEED[stat];
		}
		speed.y=-GRAVITY*deltaTime + speed.y;
	}
	if(direction==Dir::right){
		
		if(speed.x>=0 && speed.x<PLAYER_MAX_SPEED[stat]){
			speed.x=PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x>PLAYER_MAX_SPEED[stat])speed.x=PLAYER_MAX_SPEED[stat];
		}
		//si et movies en direccio contraria
		else if(speed.x<0){
			speed.x=1.5*PLAYER_ACCELERATION[stat]*deltaTime + speed.x;
			if(speed.x>0)speed.x=0;
		}
		speed.y=-GRAVITY*deltaTime + speed.y;
	}
}




