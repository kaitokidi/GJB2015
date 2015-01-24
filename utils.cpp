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

const int PLAYER_MAX_SPEED[7] =         { 100, 260,   0,   0,   0,   0,   0};
const int PLAYER_ACCELERATION[7] =      { 800, 800,   0,   0,   0,   0,   0};
const float PLAYER_JUMP_TIME[7] =       { 100, 300, 999, 999, 999, 999, 999};
const int PLAYER_JUMP_SPEED = 500;
const float PLAYER_ANIMATION_TIMER[7] = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

// idle, walkingRight, walkingLeft, jumpingRight, jumpingLeft, pushingRight, pushingLeft, runningRight, runningLeft

const int SHOES_SIZE[PState::qttState] = {};
const float SHOES_TIMER[PState::qttState] = {};

extern const int LEGS_SIZE[PState::qttState] = {};
extern const float LEGS_TIMER[PState::qttState] = {};

extern const int BODY_SIZE[PState::qttState] = {};
extern const float BODY_TIMER[PState::qttState] = {};

extern const int ARMS_SIZE[PState::qttState] = {};
extern const float ARMS_TIMER[PState::qttState] = {};

extern const int HANDS_SIZE[PState::qttState] = {};
extern const float HANDS_TIMER[PState::qttState] = {};

extern const int HEAD_SIZE[PState::qttState] = {};
extern const float HEAD_TIMER[PState::qttState] = {};

extern const int WINGS_SIZE[PState::qttState] = {};
extern const float WINGS_TIMER[PState::qttState] = {};
