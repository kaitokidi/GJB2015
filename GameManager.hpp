#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "Player.hpp"

class GameManager : public Game {
private:
    Player player;
    sf::RenderTexture renderText;
	std::vector<Collisionable> collisionables;
public:
    GameManager(int scrwidth, int scrheight, std::string title, int style);
    ~GameManager();
    void update(float deltaTime);
    void draw();
    void processEvents();
    sf::RenderTexture *getRenderTexture();
};

#endif // GAMEMANAGER_HPP
