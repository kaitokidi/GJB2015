#include "GameManager.hpp"

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT 
    board = Board(& Resources::visibleBoard, & Resources::colorBoard);
    player = Player(this);
}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    player.update(deltaTime);
}

void GameManager::draw() {
    board.draw(&renderText);
    player.draw();
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.move(Dir::up);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  player.move(Dir::down);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(Dir::right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.move(Dir::left);
    else player.move(Dir::none);
}

sf::RenderTexture *GameManager::getRenderTexture() {
   return &renderText;
}

