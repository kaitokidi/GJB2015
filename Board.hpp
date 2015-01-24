#ifndef BOARD_H
#define BOARD_H

#include "utils.hpp"
#include "Resources.hpp"

class Board {

	public:
		Board();
		Board(sf::Texture* vM, sf::Image* cM);
		std::string getPixelColor(float x, float y);
		void draw(sf::RenderTexture* rT);
		
	private:
		
		sf::Texture visibleMap;
		sf::Image colorMap;
		sf::Sprite map;
	
};

#endif // BOARD_H
