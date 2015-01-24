#ifndef STONE_H
#define STONE_H

#include "utils.hpp"
#include "Collisionable.hpp"

class Stone : public Collisionable {
public:
    Stone();
    Stone(GameManager *gm, float px, float py, float sx, float sy);
    ~Stone();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    Dir::Direction getDirection();

};

#endif // STONE_H
