#include "Portada.hpp"
#include "Resources.hpp"


Portada::Portada() {
    open = true;
}

Portada::~Portada(){}

void Portada::display(sf::RenderWindow* window){
    open = true;
    while(open){

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    open = false;
                }
            default:
                break;
            }
        }

        t.loadFromFile("res/Portada.png");
        s.setTexture(t);
        s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
        s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
        window->draw(s);

        window->display();

    }

}

void Portada::display(sf::RenderWindow* window, std::string pathImage){
    open = true;
    t.loadFromFile(pathImage);
    s = sf::Sprite();
    s.setTexture(t);
    s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
    s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
    while(open){

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    open = false;
                }
            default:
                break;
            }
        }

        window->clear();
        window->draw(s);

        window->display();

    }

}

void Portada::display(sf::RenderWindow* window, std::string pathImage, int lvl){
    open = true;
    t.loadFromFile(pathImage);
    s = sf::Sprite();
    s.setTexture(t);
    s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
    s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
    window->clear();
    window->draw(s);
    window->display();
    switch (lvl) {
    case 1:
        Resources::loadLegs();
        break;
    case 2:
        Resources::loadBody();
        break;
    case 3:
        Resources::loadArms();
        break;
    case 4:
        Resources::loadHands();
        break;
    case 5:
        Resources::loadHead();
        break;
    case 6:
        Resources::loadWings();
        break;
    default:
        break;
    }

    while(open){

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) open = false;
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    open = false;
                }
            default:
                break;
            }
        }
    }
}
