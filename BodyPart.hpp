#ifndef BODY_PART
#define BODY_PART

#include "utils.hpp"
#include "Collisionable.hpp"

class BodyPart : public Collisionable {

private:
	int id;
public:
    BodyPart();
    BodyPart(GameManager *gm, float px, float py, float sx, float sy, id);
    ~BodyPart();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    int getId();


};

#endif // BODY_PART
