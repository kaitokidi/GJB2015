#include "GameManager.hpp"

void GameManager::generaItems(){
    sf::Image aux = Resources::colorBoard;
    int size_x, size_y;
    size_x = aux.getSize().x;
    size_y = aux.getSize().y;
    
    for(int x = 1; x < size_x; ++x){
        for(int y = 1; y < size_y; ++y){
            sf::Color pixelColor = board.get_pixel_color(x,y);
            
            if (board.get_pixel_color(x-1,y) != pixelColor && board.get_pixel_color(x,y-1) != pixelColor) {

                if(pixelColor == colorsArray[colors::boxColor] ) { //add box STONE
                    
//                     std::cout << "Generate Box on" << x << " , " << y << std::endl;
                    Stone* s = new Stone(this, x, y-100, 200, 200);
                    stones.push_back(s);
                    //createBox(pos = x,y  size = i,j);
                    
                }
                else if(pixelColor == colorsArray[colors::doorColor]) { //add door

//                     std::cout << "Generate door on" << x << " , " << y << std::endl;
                    Door d = Door(this, x, y, 50, 400);
                    doors.push_back(d);
                    //createDoor(pos = x,y  size = i-x,j-y);
                }
                else if(pixelColor == colorsArray[colors::buttonColor]) { //add button

//                     std::cout << "Generate button on" << x << " , " << y << std::endl;
                    //createButton(pos = x,y  size = i-x,j-y);
                }
                else if(pixelColor == colorsArray[colors::muffinColor]) { //add muffin

//                     std::cout << "Generate Muffin on" << x << " , " << y << std::endl;
                    //createMuffin(pos = x,y  size = i-x,j-y);
                }
                else if(pixelColor == colorsArray[colors::hammerColor]) { //add hammer

//                     std::cout << "Generate hammer on" << x << " , " << y << std::endl;
                //createHammer(pos = x,y  size = i-x,j-y);
                }
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
    Button bu = Button(this, 5250, 300, 150,75, 3);
    buttons.push_back(bu);
    Button bu2 = Button(this, 5200, 1900, 150,75, 1);
    buttons.push_back(bu2);
    Button bu3 = Button(this, 5600, 1900, 150,75, 2);
    buttons.push_back(bu3);

    BodyPart p1 = BodyPart(this, 0,0 ,100,100,PState::legs);
    parts.push_back(p1);
    BodyPart p2 = BodyPart(this, 0,0 ,100,100,PState::body);
    parts.push_back(p2);
    BodyPart p3 = BodyPart(this, 0,0 ,100,100,PState::arms);
    parts.push_back(p3);
    BodyPart p4 = BodyPart(this, 0,0 ,100,100,PState::hands);
    parts.push_back(p4);
    BodyPart p5 = BodyPart(this, 0,0 ,100,100,PState::head);
    parts.push_back(p5);
    BodyPart p6 = BodyPart(this, 0,0 ,100,100,PState::wings);
    parts.push_back(p6);

    
}

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT 

        player = Player(this);
		board = Board(& Resources::visibleBoard, & Resources::colorBoard);
        
        generaItems();
        
        Portada p;
        p.display(&window);

}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    checkMovement();
    player.update(deltaTime);
    for(uint i = 0; i < stones.size(); ++i){
        stones[i]->update(deltaTime);
    }
    for(uint i = 0; i < doors.size(); ++i){
        doors[i].update(deltaTime);
    }
    for(uint i = 0; i < parts.size(); ++i){
        parts[i].update(deltaTime);
    }
}

void GameManager::draw() {
    window.clear();
	board.draw(&window);
    player.draw(&window);

    for(uint i = 0; i < stones.size(); ++i){
        stones[i]->draw(&window);
    }
    for(uint i = 0; i < doors.size(); ++i){
        doors[i].draw(&window);
    }
    for(uint i = 0; i < parts.size(); ++i){
        parts[i].draw(&window);
    }
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
    else player.jump(false);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(Dir::right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.move(Dir::left);
    else player.move(Dir::none);
}

sf::RenderTexture *GameManager::getRenderTexture() {
    return &renderText;
}

Board *GameManager::getBoard() {
    return &board;
}

    std::vector<Stone*> GameManager::getStones() { return stones; }
    std::vector<Door> GameManager::getDoors(){ return doors; }
    std::vector<Button> GameManager::getButtons(){ return buttons; }
