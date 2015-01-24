#ifndef STONE_H
#define STONE_H

#include "utils.hpp"
#include "Collisionable.hpp"

class Stone : public Collisionable {

private:
    Dir::Direction direction;

public:
    Stone();
    Stone(GameManager *gm);
    Stone(GameManager *gm, float px, float py);
    Stone(GameManager *gm, float px, float py, float sx, float sy);
    ~Stone();
    void update(float deltaTime);
    void draw(sf::RenderWindow* render);
    void move(Dir::Direction dir);
    Dir::Direction getDirection();

};

#endif // STONE_H