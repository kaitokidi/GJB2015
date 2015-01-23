#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Game.hpp"

class GameManager : public Game {
public:
    GameManager(int scrwidth, int scrheight, std::string title, int style);
    ~GameManager();
    void update(float deltaTime);
    void draw();
    void processEvents();

    sf::RenderWindow* getWindow();

};

#endif // GAMEMANAGER_HPP
