#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"
#include "Door.hpp"
#include "Board.hpp"
#include "Stone.hpp"
#include "Player.hpp"
#include "Button.hpp"
#include "BodyPart.hpp"
#include "Portada.hpp"
class GameManager : public Game {
private:
    sf::RenderTexture renderText;
    std::vector<Stone*> stones;
    std::vector<Door*> doors;
    std::vector<Button*> buttons;
    std::vector<BodyPart> parts;
    Player player;
	Board board;
	
    void generaItems();
    
public:
    
    std::vector<Stone*> getStones();
    std::vector<Door*> getDoors();
    std::vector<Button*> getButtons();
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
