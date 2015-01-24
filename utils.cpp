#include "utils.hpp"

//direction { down, left, right, up , none };
const int mx[5] = {0,  -1,	 1,	   0,   0   };
const int my[5] = {1,	0,	 0,   -1,   0   };


const int PLAYER_MAX_SPEED[7] =    {100,   0,   0,   0,   0,   0,   0};
const int PLAYER_ACCELERATION[7] = {100,   0,   0,   0,   0,   0,   0};
const int PLAYER_SIZE_X[7] =       { 10,  10,  10,  10,  10,  10,  10};
const int PLAYER_SIZE_Y[7] =       { 10,  10,  10,  10,  10,  10,  10};
const int PLAYER_ANIMATION_TIMER[7] =       { 100,  100,  100,  100,  100,  100,  100};

const float GRAVITY = 98;
