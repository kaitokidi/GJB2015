#ifndef HAMMER
#define HAMMER

#include "utils.hpp"
#include "Collisionable.hpp"

class Hammer : public Collisionable {

private:
	int id;
public:
    Hammer();
    Hammer(GameManager *gm, float px, float py, float sx, float sy);
    ~Hammer();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    void modPos(float px, float py);

};

#endif // HAMMER
