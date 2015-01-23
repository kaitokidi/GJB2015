#include "Resources.hpp"

// Explanation of this class:
// This class allow you to transform this:
//
// sf::Texture texture;
// texture.loadFromFile("PATH");
// sprite.setTexture(texture);
//
// on:
//
// sprite.setTexture(Resources::texture);
//
// Also, you dont need to worry of where have you saved the texture,
// plus that you only load the texture one time and you can use it infinite times.

sf::Texture     Resources::playerTexture;
sf::Texture     Resources::visibleBoard;
sf::Image		Resources::colorBoard;

void Resources::load() {
	playerTexture.loadFromFile("res/playerTexture.png");
    visibleBoard.loadFromFile("res/mapaNormal.png");
	colorBoard.loadFromFile( "res/mapaColors.png");

}
