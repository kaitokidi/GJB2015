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
<<<<<<< HEAD
    std::vector<Door> doors;
    std::vector<Button> buttons;
    std::vector<BodyPart*> parts;
=======
    std::vector<Door*> doors;
    std::vector<Button*> buttons;
    std::vector<BodyPart> parts;
>>>>>>> b2c0706c53ee84af8e0a3e7ed814b98022f0ec97
    Player player;
	Board board;
	
    void generaItems();
    
public:
    
    std::vector<Stone*> getStones();
<<<<<<< HEAD
    std::vector<Door> getDoors();
    std::vector<Button> getButtons();
    std::vector<BodyPart*> getBodyParts();
=======
    std::vector<Door*> getDoors();
    std::vector<Button*> getButtons();
>>>>>>> b2c0706c53ee84af8e0a3e7ed814b98022f0ec97
    GameManager(int scrwidth, int scrheight, std::string title, int style);
    ~GameManager();
    void update(float deltaTime);
    void draw();
    void processEvents();
	void checkMovement();
    void eliminaElBody(int i);
    sf::RenderTexture *getRenderTexture();
    Board *getBoard();
    sf::View view;
};

#endif // GAMEMANAGER_HPP
