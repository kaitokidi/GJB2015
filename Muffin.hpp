#ifndef MUFFIN
#define MUFFIN

#include "utils.hpp"
#include "Collisionable.hpp"

class Muffin : public Collisionable {

private:
	int id;
public:
    Muffin();
    Muffin(GameManager *gm, float px, float py, float sx, float sy);
    ~Muffin();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    void modPos(float px, float py);

};

#endif // MUFFIN
