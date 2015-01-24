#ifndef RESOURCES_H
#define RESOURCES_H

#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture playerTexture;
    static sf::Texture stoneTexture;
    static sf::Texture visibleBoard;
    static sf::Image colorBoard;
};

#endif // RESOURCES_H
