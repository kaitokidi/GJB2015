#ifndef DOOR_H
#define DOOR_H

#include "utils.hpp"
#include "Collisionable.hpp"

class Door : public Collisionable {

private:
    bool acted;
    bool down;
    bool up;
public:
    Door();
    Door(GameManager *gm);
    Door(GameManager *gm, float px, float py);
    Door(GameManager *gm, float px, float py, float sx, float sy);
    ~Door();
    void moveUp(bool b);
    void moveDown(bool b);
    void update(float deltaTime);
    void draw(sf::RenderWindow* render);
    void move(Dir::Direction dir);

};

#endif 