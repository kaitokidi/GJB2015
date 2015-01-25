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
    enum level { shoes, legs, body, arms, hands, head, wings, qttLevel};
    enum state { idleRight, idleLeft, walkingRight, walkingLeft, runningRight, runningLeft, jumpingRight, jumpingLeft, pushingRight, pushingLeft,  qttState};
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
extern const int PLAYER_SIZE_X[PState::qttLevel];
extern const int PLAYER_SIZE_Y[PState::qttLevel];
extern const float PLAYER_ANIMATION_TIMER[7];
extern const int PLAYER_SPRINT_SPEED;

// shoes
extern float SHOES_TIMER[4];
extern int SHOES_N[4];
// legs
extern float LEGS_TIMER[8];
extern int LEGS_N[8];
// body
extern float BODY_TIMER[PState::qttState];
// arms
extern float ARMS_TIMER[10];
extern int ARMS_N[10];
// hands
extern float HANDS_TIMER[10];
extern int HANDS_N[10];
// head
extern float HEAD_TIMER[PState::qttState];
extern int HEAD_N[PState::qttState];
// wings
extern const float WINGS_TIMER[PState::qttState];



#endif // UTILS_HPP
