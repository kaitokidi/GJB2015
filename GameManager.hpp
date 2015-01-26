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
#include "Hammer.hpp"
#include "Muffin.hpp"
class GameManager : public Game {
private:
    sf::RenderTexture renderText;
    std::vector<Stone*> stones;
    std::vector<BodyPart*> parts;
    std::vector<Door*> doors;
    std::vector<Button*> buttons;
    std::vector<Hammer*> Hammers;
    std::vector<Muffin*> Muffins;
    Player player;
	Board board;
	sf::Sprite mapaForeground;
    void generaItems();
    sf::Font font;
    float speedRunerTimer;
    sf::Text text;
    float aids;
    bool firstHammer;
    
public:
    
    std::vector<Stone*> getStones();
    std::vector<BodyPart*> getBodyParts();
    std::vector<Door*> getDoors();
    std::vector<Button*> getButtons();
    std::vector<Hammer*> getHammers();
    std::vector<Muffin*> getMuffins();
    GameManager(int scrwidth, int scrheight, std::string title, int style);
    ~GameManager();
    void update(float deltaTime);
    void draw();
    void processEvents();
	void checkMovement();
    void eliminaElBody();
    void eliminaElMuffin();
    sf::RenderTexture *getRenderTexture();
    Board *getBoard();
    sf::View view;
};

#endif // GAMEMANAGER_HPP
