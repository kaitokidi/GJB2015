#include "Board.hpp"

Board::Board(){

}

Board(sf::Texture vM, sf::Image cM){
		visibleMap = vM;
		colorMap = cM;
		map.setTexture(visibleMap);
}

std::string Board::getPixelColor(float destix, float destiy){
	if(image.getPixel(px,py) == sf::Color::Black) {
		return "Black";
	}
	else {
		if(image.getPixel(px,py) == sf::Color::Red) {
			return "Red";
		}
		else {
			if(image.getPixel(px,py) == sf::Color::Blue) {
				return "Blue";
			}
			else {
				if(image.getPixel(px,py) == sf::Color::Green) {
					return "Green";
				}
				else {
					if(image.getPixel(px,py) == sf::Color::White) {
						return "White";
					}
				}
			}
		}
	}
}

std::string Board::draw(sf::RenderWindow& rw){
	rw.draw(Map);
}
