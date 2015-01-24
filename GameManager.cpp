#include "GameManager.hpp"

void GameManager::generaItems(){
    
    sf::Image aux = Resources::colorBoard;
    int size_x, size_y;
    size_x = aux.getSize().x;
    size_y = aux.getSize().y;
    
    for(int x = 0; x < size_x; ++x){
        for(int y = 0; y < size_y; ++y){
            sf::Color pixelColor = board.get_pixel_color(x,y);
            
            if(pixelColor == colorsArray[colors::boxColor]) { //add box
                int i = x; int j = y;
                while(board.get_pixel_color(i, y) == colorsArray[colors::boxColor]){ 
                    if(i < size_x-1) ++i;
                    board.setPixel(i, y, sf::Color::White);
                }
                while(board.get_pixel_color(x, j) == colorsArray[colors::boxColor]){ 
                    if(j < size_y-1) ++j;
                    board.setPixel(x, j, sf::Color::White);
                }
                //createBox(pos = x,y  size = i,j);
            }
            else if(pixelColor == colorsArray[colors::doorColor]) { //add door
                int i = x; int j = y;
                while(board.get_pixel_color(i, y) == colorsArray[colors::doorColor]){ 
                    if(i < size_x-1) ++i;
                    board.setPixel(i, y, sf::Color::White);
                }
                while(board.get_pixel_color(x, j) == colorsArray[colors::doorColor]){ 
                    if(j < size_y-1) ++j;
                    board.setPixel(x, j, sf::Color::White);
                }
                //createDoor(pos = x,y  size = i,j);
            }
            else if(pixelColor == colorsArray[colors::buttonColor]) { //add button
                int i = x; int j = y;
                while(board.get_pixel_color(i, y) == colorsArray[colors::buttonColor]){ 
                    if(i < size_x-1) ++i;
                    board.setPixel(i, y, sf::Color::White);
                }
                while(board.get_pixel_color(x, j) == colorsArray[colors::buttonColor]){ 
                    if(j < size_y-1) ++j;
                    board.setPixel(x, j, sf::Color::White);
                }
                //createButton(pos = x,y  size = i,j);
            }
            else if(pixelColor == colorsArray[colors::muffinColor]) { //add muffin
                int i = x; int j = y;
                while(board.get_pixel_color(i, y) == colorsArray[colors::muffinColor]){ 
                    if(i < size_x-1) ++i;
                    board.setPixel(i, y, sf::Color::White);
                }
                while(board.get_pixel_color(x, j) == colorsArray[colors::muffinColor]){ 
                    if(j < size_y-1) ++j;
                    board.setPixel(x, j, sf::Color::White);
                }
                //createMuffin(pos = x,y  size = i,j);
            }
            else if(pixelColor == colorsArray[colors::hammerColor]) { //add hammer
                int i = x; int j = y;
                while(board.get_pixel_color(i, y) == colorsArray[colors::hammerColor]){ 
                    if(i < size_x-1) ++i;
                    board.setPixel(i, y, sf::Color::White);
                }
                while(board.get_pixel_color(x, j) == colorsArray[colors::hammerColor]){ 
                    if(j < size_y-1) ++j;
                    board.setPixel(x, j, sf::Color::White);
                }
                //createHammer(pos = x,y  size = i,j);
            }

            int part = 0;
            if(pixelColor == colorsArray[colors::footColor]) part = 1 ;//peus (inici player)
            else if(pixelColor == colorsArray[colors::legsColor]) part = 2 ;//cames
            else if(pixelColor == colorsArray[colors::bodyColor]) part = 3 ;//cos
            else if(pixelColor == colorsArray[colors::armsColor]) part = 4 ;//brac,os
            else if(pixelColor == colorsArray[colors::handColor]) part = 5 ;//ma1
            else if(pixelColor == colorsArray[colors::headColor]) part = 6 ;//cap
            else if(pixelColor == colorsArray[colors::wingColor]) part = 7 ;//ales
        }
    }
    
}

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT 

        player = Player(this);
		board = Board(& Resources::visibleBoard, & Resources::colorBoard);
        
        generaItems();


}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    checkMovement();
    player.update(deltaTime);
}

void GameManager::draw() {
    window.clear();
	board.draw(&window);
    player.draw(&window);
    
     view.reset(sf::FloatRect(0,0, 1350, 800));
     view.setCenter(player.getPosition().x, player.getPosition().y);
//      view.zoom(0.4);
        
    window.setView(view);
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

