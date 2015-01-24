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
sf::Image Resources::auxPlayerTexture;
sf::Image Resources::auxVisibleBoard;

void Resources::load() {
    //el 0.85 es (8000 / la_mida_de_la_imatge_del_mapa) 
	if(!auxPlayerTexture.loadFromFile("res/playerTexture.png")) std::cout << "unable to load playerTexture" << std::endl;
    if(!auxVisibleBoard.loadFromFile("res/mapaNormal.png")) std::cout << "unable to load mapNormal" << std::endl;
	if(!colorBoard.loadFromFile( "res/mapaColors.png")) std::cout << "unable to load mapaColors" << std::endl;
//     auxVisibleBoard.setScale(0.85,0.85);
    visibleBoard.loadFromImage(auxVisibleBoard);
//     colorBoard.setScale(0.85,0.85);
//     auxPlayerTexture.setScale(0.85,0.85);
    playerTexture.loadFromImage(auxPlayerTexture);
}
