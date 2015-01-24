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

const int PLAYER_MAX_SPEED[7] =         {800,   0,   0,   0,   0,   0,   0};
const int PLAYER_ACCELERATION[7] =      {800,   0,   0,   0,   0,   0,   0};
const int PLAYER_SIZE_X[7] =            { 10,  10,  10,  10,  10,  10,  10};
const int PLAYER_SIZE_Y[7] =            { 10,  10,  10,  10,  10,  10,  10};
const float PLAYER_ANIMATION_TIMER[7] =   {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

const float GRAVITY = 980;
