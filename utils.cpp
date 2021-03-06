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

const int PLAYER_MAX_SPEED[PState::qttLevel] =         { 100, 260,   260,   260,   300,   320,  4000};
const int PLAYER_ACCELERATION[PState::qttLevel] =      { 800, 800,   800,   800,   800,   800,  1000};
const float PLAYER_JUMP_TIME[PState::qttLevel] =       { 100, 300, 300, 300, 999, 999, 999};
const int PLAYER_JUMP_SPEED = 500;
const float PLAYER_ANIMATION_TIMER[PState::qttLevel] = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
const int PLAYER_SPRINT_SPEED = 200;
//                                           sho leg bod arm han hed wing
const int PLAYER_SIZE_X[PState::qttLevel] = {100,100,150,150,150,150,300};
const int PLAYER_SIZE_Y[PState::qttLevel] = { 50,175,240,240,240,220,220};

//  idleRight, idleLeft, walkingRight, walkingLeft, runningRight, runningLeft, jumpingRight, jumpingLeft, pushingRight, pushingLeft
// shoes
float SHOES_TIMER[4] = {1,1,0.5,0.5};
int SHOES_N[4] = {1,1,6,6};
// legs
float LEGS_TIMER[8] = {0.3,0.3,0.3,0.3,0,0,0.2,0.2};
int LEGS_N[8] = {6,6,6,6,0,0,7,7};
// body
float BODY_TIMER[10] = {0.2, 0.2, 0.1, 0.1, 0, 0, 0.2, 0.2, 0.1, 0.1};
int BODY_N[10] = {6,6,6,6,0,0,7,7,5,5};
// arms
float ARMS_TIMER[10] = {0.2, 0.2, 0.1, 0.1, 0.1, 0.1, 0.2, 0.2, 0.1, 0.1};
int ARMS_N[10] = {6,6,6,6,10,10,7,7,5,5};
// hands
float HANDS_TIMER[10] = {0.2, 0.2, 0.1, 0.1, 0.1, 0.1, 0.2, 0.2, 0.1, 0.1};
int HANDS_N[10] = {6,6,6,6,10,10,7,7,5,5};
// head
float HEAD_TIMER[PState::qttState] = {0.3, 0.3, 0.1, 0.1, 0.1, 0.1, 0.2, 0.2, 0.1, 0.1};
int HEAD_N[PState::qttState] = {2,2,6,6,10,10,7,7,5,5};
// wings
float WINGS_TIMER[2] = {0.05,0.05};
int WINGS_N[2] = {7,7};
