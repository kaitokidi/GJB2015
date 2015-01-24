#include "Board.hpp"

Board::Board(){

}

Board::Board(sf::Texture* vM, sf::Image* cM){
//         std::cout << "vM ---- " << vM->getSize().x << std::endl;    
//          std::cout << "map ---- " << map.getTexture()->getSize().x << std::endl;
		visibleMap = *vM;
//     std::cout << "visibleMap ---- " << visibleMap.getSize().x << std::endl;    
		colorMap = *cM;
//     std::cout << "colorMap ---- " << colorMap.getSize().x << std::endl;    

}

std::string Board::getPixelColor(float px, float py){
	if(colorMap.getPixel(px,py) == sf::Color::Red)   return "Red";
    if(colorMap.getPixel(px,py) == sf::Color::Blue)  return "Blue";
	if(colorMap.getPixel(px,py) == sf::Color::Green) return "Green";
	if(colorMap.getPixel(px,py) == sf::Color::Black) return "Black";
	if(colorMap.getPixel(px,py) == sf::Color::White) return "White";
    return "Penguins";
}

sf::Color Board::get_pixel_color(float px, float py){
    return colorMap.getPixel(px, py);
}

void Board::setPixel(float px, float py, sf::Color c){
    colorMap.setPixel(px, py, c);
    colorMap.loadFromFile("res/mapaColors.png");
}

void Board::draw(sf::RenderWindow* rW){
//     rT->clear(sf::Color::Red);
//     std::cout << "bmo " << visibleMap.getSize().x << std::endl;
//      std::cout << "map ---- " << map.getTexture()->getSize().x << std::endl;
    map.setTexture(visibleMap);
//     map.scale(rW->getSize().x/map.getGlobalBounds().width, rW->getSize().y/map.getGlobalBounds().height);
	rW->draw(map);
    
//     std::cout << "BMO" << std::endl;
}
