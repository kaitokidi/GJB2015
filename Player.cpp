#include "Player.hpp"
#include "Resources.hpp"


Player::Player() : Collisionable(&Resources::playerTexture, PLAYER_0_SIZE_X, PLAYER_0_SIZE_Y, 1, 1){
    //sprite.setTexture(Resources::playerTexture);
    direction = Dir::none;
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
		speed.x=
	}
	if(direction==Dir::left){
		
	}
	if(direction==Dir::right){
		
	}
}




