#ifndef UTILS_HPP
#define UTILS_HPP

//SFML (Simple Fast Media Library)
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STL (Standard Toolkit Library)
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

// If you want to declare global variables you can do it here:
extern const int mx[5];
extern const int my[5];
extern const sf::Color colorsArray[12];

extern const int PLAYER_MAX_SPEED[7];
extern const int PLAYER_ACCELERATION[7];
extern const int PLAYER_JUMP_SPEED[7];
extern const int PLAYER_SIZE_X[7];
extern const int PLAYER_SIZE_Y[7];
extern const float PLAYER_ANIMATION_TIMER[7];
extern const float GRAVITY;


namespace Dir {
    enum Direction { down, left, right, none , up };
}

namespace PState {
    enum level { shoes, legs, body, arms, hands, head, wings };
    enum state { idle, walkingRight, walkingLeft, jumping, pushing, running};
}

namespace colors {
    enum itemColor { boxColor, doorColor, buttonColor, muffinColor, hammerColor, 
        footColor, legsColor, bodyColor, armsColor, handColor, headColor, wingColor};
}

#endif // UTILS_HPP
