#include "GameManager.hpp"

void GameManager::generaItems(){
    sf::Image aux = Resources::colorBoard;
    int size_x, size_y;
    sf::Font font = Resources::djvu;
    size_x = aux.getSize().x;
    size_y = aux.getSize().y;
    float speedRunerTimer=0;
    
    /***************************/
//     sf::Texture text;
//     text.loadFromFile("res/foregroundMap.png");
//     mapaForeground.setTexture(text);
    
    for(int x = 1; x < size_x; ++x){
        for(int y = 1; y < size_y; ++y){
            sf::Color pixelColor = board.get_pixel_color(x,y);
            
            if (board.get_pixel_color(x-1,y) != pixelColor && board.get_pixel_color(x,y-1) != pixelColor) {

                if(pixelColor == colorsArray[colors::boxColor] ) { //add box STONE
                    
//                     std::cout << "Generate Box on" << x << " , " << y << std::endl;
                    Stone* s = new Stone(this, x, y-10, 200, 200);
                    stones.push_back(s);
                    //createBox(pos = x,y  size = i,j);
                    
                }
                else if(pixelColor == colorsArray[colors::doorColor]) { //add door

//                     std::cout << "Generate door on" << x << " , " << y << std::endl;

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

//             int part = 0;
//             if(pixelColor == colorsArray[colors::footColor]) part = 1 ;//peus (inici player)
//             else if(pixelColor == colorsArray[colors::legsColor]) part = 2 ;//cames
//             else if(pixelColor == colorsArray[colors::bodyColor]) part = 3 ;//cos
//             else if(pixelColor == colorsArray[colors::armsColor]) part = 4 ;//brac,os
//             else if(pixelColor == colorsArray[colors::handColor]) part = 5 ;//ma1
//             else if(pixelColor == colorsArray[colors::headColor]) part = 6 ;//cap
//             else if(pixelColor == colorsArray[colors::wingColor]) part = 7 ;//ales
        }
    }
    Door* d = new Door(this, 5100, 100, 50, 400);
    Door* d2 = new Door(this, 5400, 1700, 50, 400);
    Door* d3 = new Door(this, 6700, 700, 50, 400);
    doors.push_back(d);
    doors.push_back(d2);
    doors.push_back(d3);
                     
    Button* bu = new Button(this, 5250, 300, 150,75, 3);
    Button* bu2 = new Button(this, 5200, 1900, 150,75, 1);
    Button* bu3 = new Button(this, 5600, 1900, 150,75, 2);
    buttons.push_back(bu);
    buttons.push_back(bu2);
    buttons.push_back(bu3);

    BodyPart *p1 = new BodyPart(this, 4360, 1300,100,100,PState::legs);
    parts.push_back(p1);
    BodyPart *p2 = new BodyPart(this, 3400, 1980 ,100,100,PState::body);
    parts.push_back(p2);
    BodyPart *p3 = new BodyPart(this, 6100, 1250, 100, 100,PState::arms);
    parts.push_back(p3);
    BodyPart *p4 = new BodyPart(this, 4100, 450,100,100,PState::hands);
    parts.push_back(p4);
    BodyPart *p5 = new BodyPart(this, 5200, 1940,100,100,PState::head);
    parts.push_back(p5);
    BodyPart *p6 = new BodyPart(this, 7450, 1050,100,100,PState::wings);
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
    speedRunerTimer = speedRunerTimer + deltaTime;
    std::cout << "time" << speedRunerTimer << " , " << std::endl;
    checkMovement();
    player.update(deltaTime);
    for(uint i = 0; i < stones.size(); ++i){
        stones[i]->update(deltaTime);
    }
    for(uint i = 0; i < doors.size(); ++i){
        doors[i]->update(deltaTime);
    }
    for(uint i = 0; i < buttons.size(); ++i){
        buttons[i]->update(deltaTime);
    }
    for(uint i = 0; i < parts.size(); ++i){
        parts[i]->update(deltaTime);
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
        doors[i]->draw(&window);
    }
    for(uint i = 0; i < buttons.size(); ++i){
        buttons[i]->draw(&window);
    }
    for(uint i = 0; i < parts.size(); ++i){
        parts[i]->draw(&window);
    }
    // Declare and load a font
    
    // Create a text
    sf::Text text("hddddddddddddello", font);
    text.setCharacterSize(200);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Red);
    text.setPosition(player.getPosition().x, player.getPosition().y);
    // Draw it
    
    
//     mapaForeground.setScale(window.getSize().y/mapaForeground.getGlobalBounds().height, window.getSize().y/mapaForeground.getGlobalBounds().height);
    window.draw(mapaForeground);

    
     view.reset(sf::FloatRect(0,0, 1350, 800));
     view.setCenter(player.getPosition().x, player.getPosition().y);
     window.draw(text);
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
    std::vector<BodyPart*> GameManager::getBodyParts(){ return parts; }
void GameManager::eliminaElBody(int i){
    parts.erase(parts.begin());
}

    std::vector<Door*> GameManager::getDoors(){ return doors; }
    std::vector<Button*> GameManager::getButtons(){ return buttons; }

