#include "Board.hpp"

Board::Board(){

}

Board::Board(sf::Texture* vM, sf::Image* cM){
		visibleMap = *vM;
		colorMap = *cM;
		map.setTexture(visibleMap);
}

std::string Board::getPixelColor(float px, float py){
	if(colorMap.getPixel(px,py) == sf::Color::Black) {
		return "Black";
	}
	else {
		if(colorMap.getPixel(px,py) == sf::Color::Red) {
			return "Red";
		}
		else {
			if(colorMap.getPixel(px,py) == sf::Color::Blue) {
				return "Blue";
			}
			else {
				if(colorMap.getPixel(px,py) == sf::Color::Green) {
					return "Green";
				}
				else {
					if(colorMap.getPixel(px,py) == sf::Color::White) {
						return "White";
					}
					else {
						return "Penguins";
					}
				}
			}
		}
	}
}

void Board::draw(sf::RenderTexture* rT){
	rT->draw(map);
}
