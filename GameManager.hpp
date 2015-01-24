#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"

class GameManager : public Game {
private:
    Player player;
    sf::RenderTexture renderText;
	std::vector<Collisionable> collisionables;
	Board board;
	
public:
    GameManager(int scrwidth, int scrheight, std::string title, int style);
    ~GameManager();
    void update(float deltaTime);
    void draw();
    void processEvents();
	void checkMovement();
    sf::RenderTexture *getRenderTexture();
    Board *getBoard();
    sf::View view;
};

#endif // GAMEMANAGER_HPP
