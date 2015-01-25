#ifndef RESOURCES_H
#define RESOURCES_H

#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture playerTexture;
    static sf::Texture buttonTexture;
    static sf::Texture stoneTexture;
    static sf::Texture visibleBoard;
    static sf::Texture doorTexture;
    static sf::Image colorBoard;
    static sf::Texture bodyPartTexture;
    static sf::Texture playerShoes;
    static sf::Texture playerHead;
    
static sf::Texture shoesText;
static sf::Texture legsText;
static sf::Texture bodyText;
static sf::Texture armsText;
static sf::Texture handText;
static sf::Texture headText;
static sf::Texture wingsText;
static sf::Font djvu;

};

#endif // RESOURCES_H
