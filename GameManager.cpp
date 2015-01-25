#include "GameManager.hpp"

void GameManager::generaItems(){
    
    
    sf::Image aux = Resources::colorBoard;
    int size_x, size_y;

    text.setFont(Resources::djvu);
    text.setString("hddddddddddddello");
    text.setCharacterSize(20);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Red);
    text.setPosition(2600, 800);
    size_x = aux.getSize().x;
    size_y = aux.getSize().y;
    speedRunerTimer=0;
    
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

    Button* bu = new Button(this, 5250, 300, 75,150, 3);
    Button* bu2 = new Button(this, 5200, 1900, 75,150, 1);
    Button* bu3 = new Button(this, 5600, 1900, 75,150, 2);
    buttons.push_back(bu);
    buttons.push_back(bu2);
    buttons.push_back(bu3);

    BodyPart *p1 = new BodyPart(this, 4360, 1350,174,63,PState::legs);
    parts.push_back(p1);
    BodyPart *p2 = new BodyPart(this, 3400, 2080 ,144,44,PState::body);
    parts.push_back(p2);
    BodyPart *p3 = new BodyPart(this, 6100, 1300, 137, 32,PState::arms);
    parts.push_back(p3);
    BodyPart *p4 = new BodyPart(this, 4100, 530,144,27,PState::hands);
    parts.push_back(p4);
    BodyPart *p5 = new BodyPart(this, 5200, 1970,143,67,PState::head);
    parts.push_back(p5);
    BodyPart *p6 = new BodyPart(this, 7450, 1050,100,100,PState::wings);
    parts.push_back(p6);

    Hammer* h = new Hammer(this, 500, 120,520,420);
    Hammers.push_back(h);
    Muffin* m = new Muffin(this, 6650, 2200,100,100);
    Muffins.push_back(m);
    Muffin* m2 = new Muffin(this, 1080, 2400,100,100);
    Muffins.push_back(m2);
    Muffin* m3 = new Muffin(this, 1080, 2400,100,100);
    Muffins.push_back(m3);
    Muffin* m4 = new Muffin(this, 1080, 2400,100,100);
    Muffins.push_back(m4);
    Muffin* m5 = new Muffin(this, 1080, 2400,100,100);
    Muffins.push_back(m5);
    Muffin* m6 = new Muffin(this, 1080, 2400,100,100);
    Muffins.push_back(m6);

    
}

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) { //RECKT

    player = Player(this);
    board = Board(& Resources::visibleBoard, & Resources::colorBoard);

    generaItems();

    Portada p;
    p.display(&window, "res/Portada.png");
    aids = 0;
    //         p.display(&window, "res/inst1.png");
    //         p.display(&window, "res/inst2.png");
    //         p.display(&window, "res/inst3.png");
    //         p.display(&window, "res/inst4.png");
    //         p.display(&window, "res/inst5.png");
    //         p.display(&window, "res/inst6.png");

}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    deltaTime -= aids;
    int level = player.getLvl();
    if(player.getH()==false){
        speedRunerTimer += deltaTime;
    }
    
    else{
        Hammers[0]->modPos(player.getPosition().x-200, player.getPosition().y-100);
    }
    if(player.getM()==true){
        speedRunerTimer -= 20;
    }
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
    if (player.getLvl() > level) {
        sf::Clock c;
        window.setView(window.getDefaultView());
        Portada p1;
    std::stringstream text2;
    text2 << "res/inst" << player.getLvl() << ".png";
    std::string strn = text2.str();

        p1.display(&window, strn);
        aids = c.restart().asSeconds();
    }
    else aids = 0;
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
    for(uint i = 0; i < Hammers.size(); ++i){
        Hammers[i]->draw(&window);
    }
    for(uint i = 0; i < Muffins.size(); ++i){
        Muffins[i]->draw(&window);
    }
    // Declare and load a font
    
    // Create a text
    
    
    // Draw it
    
    
    //     mapaForeground.setScale(window.getSize().y/mapaForeground.getGlobalBounds().height, window.getSize().y/mapaForeground.getGlobalBounds().height);
    window.draw(mapaForeground);


    std::stringstream text2;
    text2 << speedRunerTimer;
    std::string str = text2.str();
    text.setString(str);



    view.reset(sf::FloatRect(0,0, 1350, 800));
    view.setCenter(player.getPosition().x, player.getPosition().y);
    text.setPosition(player.getPosition().x-500, player.getPosition().y-300);
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

void GameManager::eliminaElMuffin(int i){
    Muffins.erase(Muffins.begin());
}

std::vector<Door*> GameManager::getDoors(){ return doors; }
std::vector<Button*> GameManager::getButtons(){ return buttons; }
std::vector<Hammer*> GameManager::getHammers(){ return Hammers; }
std::vector<Muffin*> GameManager::getMuffins(){ return Muffins; }

