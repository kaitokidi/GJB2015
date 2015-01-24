#include "Board.hpp"

Board::Board(){

}

Board::Board(sf::Texture* vM, sf::Image* cM){
//         std::cout << "vM ---- " << vM->getSize().x << std::endl;    
//     std::cout << "visibleMap ---- " << visibleMap.getSize().x << std::endl;    
//          std::cout << "map ---- " << map.getTexture()->getSize().x << std::endl;
		visibleMap = *vM;
		colorMap = *cM;

}

std::string Board::getPixelColor(float px, float py){
	if(colorMap.getPixel(px,py) == sf::Color::Red)   return "Red";
    if(colorMap.getPixel(px,py) == sf::Color::Blue)  return "Blue";
	if(colorMap.getPixel(px,py) == sf::Color::Green) return "Green";
	if(colorMap.getPixel(px,py) == sf::Color::Black) return "Black";
	if(colorMap.getPixel(px,py) == sf::Color::White) return "White";
    return "Penguins";
}

void Board::draw(sf::RenderWindow* rW){
//     rT->clear(sf::Color::Red);
//     std::cout << "bmo " << visibleMap.getSize().x << std::endl;
//      std::cout << "map ---- " << map.getTexture()->getSize().x << std::endl;
    map.setTexture(visibleMap);
    map.scale(rW->getSize().x/map.getGlobalBounds().width, rW->getSize().y/map.getGlobalBounds().height);
	rW->draw(map);
    
//     std::cout << "BMO" << std::endl;
}
