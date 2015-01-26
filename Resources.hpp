#ifndef RESOURCES_H
#define RESOURCES_H

#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture buttonTexture;
    static sf::Texture stoneTexture;
    static sf::Texture visibleBoard;
    static sf::Texture doorTexture;
    static sf::Image colorBoard;
    static sf::Texture bodyPartTexture;

    static sf::Texture playerShoes;
    static void loadLegs();
    static sf::Texture playerLegs;
    static void loadBody();
    static sf::Texture playerBody;
    static void loadArms();
    static sf::Texture playerArms;
    static void loadHands();
    static sf::Texture playerHands;
    static void loadHead();
    static sf::Texture playerHead;
    static void loadWings();
    static sf::Texture playerWings;

    static sf::Texture legsText;
    static sf::Texture bodyText;
    static sf::Texture armsText;
    static sf::Texture handText;
    static sf::Texture headText;
    static sf::Texture wingsText;
    static sf::Texture hammerText;
    static sf::Texture muffinText;
    static sf::Font djvu;

};

#endif // RESOURCES_H
