#ifndef BOARD_H
#define BOARD_H

#include "Utils.hpp"
#include "Resources.hpp"

class Board {

	public:
		Board();
		Board(sf::Texture vM, sf::Image cM);
		std::string getPixelColor(float x, float y);
		void draw(sf::RenderWindow& rw);
		
	private:
		
		sf::Texture visibleMap;
		sf::Image colorMap;
		sf::Sprite map;
	
};

#endif // BOARD_H
