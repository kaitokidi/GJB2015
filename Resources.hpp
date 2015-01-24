#ifndef RESOURCES_H
#define RESOURCES_H

#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture playerTexture;
    static sf::Texture visibleBoard;
    static sf::Image colorBoard;
    static sf::Image auxPlayerTexture;
    static sf::Image auxVisibleBoard;
};

#endif // RESOURCES_H
