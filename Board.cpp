#include "Board.hpp"

Board::Board(){

}

Board::Board(sf::Texture* vM, sf::Image* cM){
		visibleMap = *vM;
		colorMap = *cM;
		map.setTexture(visibleMap);
}

std::string Board::getPixelColor(float px, float py){
	if(colorMap.getPixel(px,py) == sf::Color::Black) return "Black";
	if(colorMap.getPixel(px,py) == sf::Color::Red)   return "Red";
    if(colorMap.getPixel(px,py) == sf::Color::Blue)  return "Blue";
	if(colorMap.getPixel(px,py) == sf::Color::Green) return "Green";
	if(colorMap.getPixel(px,py) == sf::Color::White) return "White";
    return "Penguins";
}

void Board::draw(sf::RenderTexture* rT){
	rT->draw(map);
}
