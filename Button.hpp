#ifndef BUTTON_H
#define BUTTON_H

#include "utils.hpp"
#include "Collisionable.hpp"

class Button : public Collisionable {

private:
    bool pressed;
    int id;
public:
    Button();
    Button(GameManager *gm, float px, float py, float sx, float sy, int id);
    ~Button();
    int getID();
    void draw(sf::RenderWindow* render); 
    void update(float deltaTime);

};

#endif // BUTTON_H