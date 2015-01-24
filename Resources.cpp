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

sf::Texture     Resources::buttonTexture;
sf::Texture     Resources::playerTexture;
sf::Texture     Resources::stoneTexture;
sf::Texture     Resources::visibleBoard;
sf::Texture     Resources::doorTexture;
sf::Image		Resources::colorBoard;
sf::Texture     Resources::bodyPartTexture;
sf::Texture     Resources::playerHead;

void Resources::load() {
    if(!buttonTexture.loadFromFile("res/buttonTexture.png")) std::cout << "unable to load buttonTexture" << std::endl;
    if(!playerTexture.loadFromFile("res/playerTexture.png")) std::cout << "unable to load playerTexture" << std::endl;
    if(!stoneTexture.loadFromFile("res/stoneTexture.png")) std::cout << "unable to load stoneTexture" << std::endl;
    if(!doorTexture.loadFromFile("res/doorTexture.png")) std::cout << "unable to load doorTexture" << std::endl;
    if(!visibleBoard.loadFromFile("res/mapaNormal.png")) std::cout << "unable to load mapNormal" << std::endl;
	if(!colorBoard.loadFromFile( "res/mapaColors.png")) std::cout << "unable to load mapaColors" << std::endl;
    if(!bodyPartTexture.loadFromFile( "res/BodyPartTexture.png")) std::cout << "unable to load BodyPartTexture" << std::endl;

    if(!playerHead.loadFromFile( "res/head.png")) std::cout << "unable to load playerHead" << std::endl;
}
