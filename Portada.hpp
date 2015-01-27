#ifndef PORTADA_H
#define PORTADA_H

#include "utils.hpp"
#include "Button.hpp"

class Portada {

private:
    sf::Sprite s;
    sf::Texture t;
//    sf::Button b;
    bool open;
    
public:
    Portada();
    ~Portada();
    void display(sf::RenderWindow* window);
    void display(sf::RenderWindow* window, std::string pathImage);
    void display(sf::RenderWindow* window, std::string pathImage, int lvl);
    
};

#endif // PORTADA_H
