#include "Resources.hpp"

// Explanation of this class:
// This class allow you to transform this:
//
// sf::Texture texture;
// texture.loadFromFile("PATH");
// sprite.setTexture(texture);
//
// on:
//
// sprite.setTexture(Resources::texture);
//
// Also, you dont need to worry of where have you saved the texture,
// plus that you only load the texture one time and you can use it infinite times.

sf::Texture     Resources::buttonTexture;
sf::Texture     Resources::stoneTexture;
sf::Texture     Resources::visibleBoard;
sf::Texture     Resources::doorTexture;
sf::Image		Resources::colorBoard;
sf::Texture     Resources::bodyPartTexture;

sf::Texture     Resources::playerShoes;
sf::Texture     Resources::playerLegs;
sf::Texture     Resources::playerBody;
sf::Texture     Resources::playerArms;
sf::Texture     Resources::playerHands;
sf::Texture     Resources::playerHead;
sf::Texture     Resources::playerWings;

sf::Texture     Resources::legsText;
sf::Texture     Resources::bodyText;
sf::Texture     Resources::armsText;
sf::Texture     Resources::handText;
sf::Texture     Resources::headText;
sf::Texture     Resources::wingsText;
sf::Texture     Resources::hammerText;
sf::Texture     Resources::muffinText;
sf::Font        Resources::djvu;


void Resources::load() {
    if(!buttonTexture.loadFromFile("res/buttonTexture.png")) std::cout << "unable to load buttonTexture" << std::endl;
    if(!stoneTexture.loadFromFile("res/stoneTexture.png")) std::cout << "unable to load stoneTexture" << std::endl;
    if(!doorTexture.loadFromFile("res/doorTexture.png")) std::cout << "unable to load doorTexture" << std::endl;
    if(!visibleBoard.loadFromFile("res/mapaNormal.png")) std::cout << "unable to load mapNormal" << std::endl;
	if(!colorBoard.loadFromFile( "res/mapaColors.png")) std::cout << "unable to load mapaColors" << std::endl;
    if(!bodyPartTexture.loadFromFile( "res/BodyPartTexture.png")) std::cout << "unable to load BodyPartTexture" << std::endl;

    if(!playerShoes.loadFromFile( "res/shoes.png")) std::cout << "unable to load playerShoes" << std::endl;

    if(  !legsText.loadFromFile( "res/thelegs.png"  )) std::cout << "unable to load legs" << std::endl;
    if(  !bodyText.loadFromFile( "res/thebody.png"  )) std::cout << "unable to load body" << std::endl;
    if(  !armsText.loadFromFile( "res/thearms.png"  )) std::cout << "unable to load arms" << std::endl;
    if(  !handText.loadFromFile( "res/thehand.png"  )) std::cout << "unable to load hand" << std::endl;
    if(  !headText.loadFromFile( "res/thehead.png"  )) std::cout << "unable to load head" << std::endl;
    if( !wingsText.loadFromFile( "res/thewings.png" )) std::cout << "unable to load wings" << std::endl;
    if(!hammerText.loadFromFile( "res/thehammer.png")) std::cout << "unable to load hammer" << std::endl;
    if(!muffinText.loadFromFile( "res/themuffin.png")) std::cout << "unable to load muffin" << std::endl;
    if(!djvu.loadFromFile( "res/djvu.ttf")) std::cout << "unable to load font" << std::endl;
}

void Resources::loadLegs() {
    if(!playerLegs.loadFromFile( "res/legs.png")) std::cout << "unable to load playerLegs" << std::endl;
}

void Resources::loadBody() {
    if(!playerBody.loadFromFile( "res/body.png")) std::cout << "unable to load playerBody" << std::endl;
}

void Resources::loadArms() {
    if(!playerArms.loadFromFile( "res/arms.png")) std::cout << "unable to load playerArms" << std::endl;
}

void Resources::loadHands() {
    if(!playerHands.loadFromFile("res/hands.png")) std::cout << "unable to load playerHands" << std::endl;
}

void Resources::loadHead() {
    if(!playerHead.loadFromFile( "res/head.png")) std::cout << "unable to load playerHead" << std::endl;
}

void Resources::loadWings() {
    if(!playerWings.loadFromFile( "res/wings.png")) std::cout << "unable to load playerWings" << std::endl;
}
