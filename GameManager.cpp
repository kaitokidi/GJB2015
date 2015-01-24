#include "GameManager.hpp"

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT 
		board = Board(& Resources::visibleBoard, & Resources::colorBoard);
        if (! renderText.create(8000, 3204)) std::cout << "The motherfuking rendertexture is not being created" << std::endl;
}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    player.update(deltaTime);
}

void GameManager::draw() {
    renderText.clear();
	board.draw(&renderText);
    sf::Texture txt;
    sf::Image img(renderText.getTexture().copyToImage());
    img.flipVertically();
    txt.loadFromImage(img);
    sf::Sprite spr(txt);
    spr.setPosition(0,0);
    window.draw(spr);
    window.display();
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) window.close();
            break;
        case sf::Event::KeyReleased:
            break;
        default:
            break;
        }
    }
}

void GameManager::checkMovement(){
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.move(Dir::up);
//      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  player.move(Dir::down);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(Dir::right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.move(Dir::left);
    else player.move(Dir::none);
    
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  player.jump(true);
//     else player.jump(false);
}

sf::RenderTexture *GameManager::getRenderTexture() {
   return &renderText;
}

