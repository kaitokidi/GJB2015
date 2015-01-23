#include "Player.hpp"
#include "Resources.hpp"

int SPRITE_FOOT_X = 10;
int SPRITE_FOOT_Y = 10;
Player::Player() :Collisionable(Resources::playerTexture, SPRITE_FOOT_X, SPRITE_FOOT_Y, 1, 1){
    //sprite.setTexture(Resources::playerTexture);
}

Player::~Player() {
	
}


void Player::draw() {

}
void Player::update(float deltaTime) {

}


