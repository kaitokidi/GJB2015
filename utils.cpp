#include "utils.hpp"

//direction { down, left, right, up , none };
const int mx[5] = {0,  -1,	 1,	   0,   0   };
const int my[5] = {1,	0,	 0,   -1,   0   };

const sf::Color colorsArray[12] = {
    // boxColor,            doorColor,         buttonColor,     muffinColor,        hammerColor, 
       sf::Color(255,153,0),sf::Color(0,153,0),sf::Color(250,250,2),sf::Color(102,51,0),sf::Color(0,51,153),
    // footColor,     legsColor,       bodyColor,        armsColor,       handColor,      headColor,        wingColor
     sf::Color(0,0,0),sf::Color(0,0,0),sf::Color(0,0,0),sf::Color(0,0,0),sf::Color(0,0,0),sf::Color(0,0,0),sf::Color(0,0,0)
    
};

const float GRAVITY = 980;

const int PLAYER_MAX_SPEED[PState::qttLevel] =         { 100, 260,   0,   0,   0,   0,   0};
const int PLAYER_ACCELERATION[PState::qttLevel] =      { 800, 800,   0,   0,   0,   0,   0};
const float PLAYER_JUMP_TIME[PState::qttLevel] =       { 100, 300, 999, 999, 999, 999, 999};
const int PLAYER_JUMP_SPEED = 500;
const float PLAYER_ANIMATION_TIMER[PState::qttLevel] = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

//                                           sho leg bod arm han hed wing
const int PLAYER_SIZE_X[PState::qttLevel] = {  0,  0,  0,  0,  0,150,  0};
const int PLAYER_SIZE_Y[PState::qttLevel] = {  0,  0,  0,  0,  0,220,  0};

// idle, walkingRight, walkingLeft, jumpingRight, jumpingLeft, pushingRight, pushingLeft, runningRight, runningLeft

// shoes
const float SHOES_TIMER[PState::qttState] = {};
// legs
const float LEGS_TIMER[PState::qttState] = {};
// body
const float BODY_TIMER[PState::qttState] = {};
// arms
const float ARMS_TIMER[PState::qttState] = {};
// hands
const float HANDS_TIMER[PState::qttState] = {};
// head
const float HEAD_TIMER[PState::qttState] = {};
// wings
const float WINGS_TIMER[PState::qttState] = {};
