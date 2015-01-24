#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "Door.hpp"
#include "Board.hpp"
#include "Stone.hpp"
#include "Player.hpp"

class GameManager : public Game {
private:
    sf::RenderTexture renderText;
	std::vector<Stone> stones;
    std::vector<Door> doors;
    Player player;
	Board board;
	
    void generaItems();
    
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
