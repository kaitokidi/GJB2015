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

namespace Dir {
    enum Direction { down, left, right, none , up };
}

namespace PState {
    enum level { shoes, legs, body, arms, hands, head, wings };
    enum state { idle, walkingRight, walkingLeft, jumpingRight, jumpingLeft, pushingRight, pushingLeft, runningRight, runningLeft, qttState};
}

namespace colors {
    enum itemColor { boxColor, doorColor, buttonColor, muffinColor, hammerColor,
        footColor, legsColor, bodyColor, armsColor, handColor, headColor, wingColor};
}
// If you want to declare global variables you can do it here:
extern const int mx[5];
extern const int my[5];
extern const sf::Color colorsArray[12];

extern const float GRAVITY;

extern const int PLAYER_MAX_SPEED[7];
extern const int PLAYER_ACCELERATION[7];
extern const float PLAYER_JUMP_TIME[7];
extern const int PLAYER_JUMP_SPEED;
extern const int PLAYER_SIZE_X[7];
extern const int PLAYER_SIZE_Y[7];
extern const float PLAYER_ANIMATION_TIMER[7];

// shoes
extern const int SHOES_SIZE[PState::qttState];
extern const float SHOES_TIMER[PState::qttState];
// legs
extern const int LEGS_SIZE[PState::qttState];
extern const float LEGS_TIMER[PState::qttState];
// body
extern const int BODY_SIZE[PState::qttState];
extern const float BODY_TIMER[PState::qttState];
// arms
extern const int ARMS_SIZE[PState::qttState];
extern const float ARMS_TIMER[PState::qttState];
// hands
extern const int HANDS_SIZE[PState::qttState];
extern const float HANDS_TIMER[PState::qttState];
// head
extern const int HEAD_SIZE[PState::qttState];
extern const float HEAD_TIMER[PState::qttState];
// wings
extern const int WINGS_SIZE[PState::qttState];
extern const float WINGS_TIMER[PState::qttState];



#endif // UTILS_HPP
