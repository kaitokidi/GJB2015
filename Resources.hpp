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
};

#endif // RESOURCES_H
