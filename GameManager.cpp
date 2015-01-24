#include "GameManager.hpp"

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT 

        player = Player(this);
		board = Board(& Resources::visibleBoard, & Resources::colorBoard);
        if (! renderText.create(8000, 3204)) std::cout << "The motherfuking rendertexture is not being created" << std::endl;

}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    checkMovement();
    player.update(deltaTime);
}

void GameManager::draw() {
    renderText.clear();
	board.draw(&renderText);
    player.draw(&renderText);
    sf::Texture txt(renderText.getTexture());
//     sf::Image img(txt.copyToImage());
//     img.flipVertically();
//     txt.loadFromImage(img);
    sf::Sprite spr(txt);
    spr.setPosition(0,0);
//     spr.setOrigin(spr.getGlobalBounds().width/2, spr.getGlobalBounds().height/2);
//     spr.setRotation(180);
    spr.setScale(window.getSize().x/spr.getGlobalBounds().width,window.getSize().x/spr.getGlobalBounds().width);
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  player.jump(true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(Dir::right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.move(Dir::left);
    else player.move(Dir::none);
    
//     else player.jump(false);
}

sf::RenderTexture *GameManager::getRenderTexture() {
    return &renderText;
}

Board *GameManager::getBoard() {
    return &board;
}

