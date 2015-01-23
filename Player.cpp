#include "Player.hpp"
#include "Resources.hpp"


Player::Player() :Collisionable(Resources::playerTexture, PLAYER_0_SIZE_X, PLAYER_0_SIZE_Y, 1, 1){
    //sprite.setTexture(Resources::playerTexture);
    direction = none;
}

Player::~Player() {
	
}


void Player::draw() {

}

Direction Player::getDirection() {
    return direction;
}

void Player::update(float deltaTime) {
	if(direction==0){
		
	}
}




