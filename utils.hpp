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
extern float deltaSpeed; // You must to declare this avariable again on utils.cpp
extern const int mx[5];
extern const int my[5];

extern const int PLAYER_0_MAX_SPEED;
extern const int PLAYER_1_MAX_SPEED;
extern const int PLAYER_2_MAX_SPEED;
extern const int PLAYER_3_MAX_SPEED;
extern const int PLAYER_4_MAX_SPEED;
extern const int PLAYER_5_MAX_SPEED;
extern const int PLAYER_6_MAX_SPEED;
extern const int PLAYER_0_ACCELERATION;
extern const int PLAYER_1_ACCELERATION;
extern const int PLAYER_2_ACCELERATION;
extern const int PLAYER_3_ACCELERATION;
extern const int PLAYER_4_ACCELERATION;
extern const int PLAYER_5_ACCELERATION;
extern const int PLAYER_6_ACCELERATION;
extern const int PLAYER_0_SIZE_X;
extern const int PLAYER_1_SIZE_X;
extern const int PLAYER_2_SIZE_X;
extern const int PLAYER_3_SIZE_X;
extern const int PLAYER_4_SIZE_X;
extern const int PLAYER_5_SIZE_X;
extern const int PLAYER_6_SIZE_X;
extern const int PLAYER_0_SIZE_Y;
extern const int PLAYER_1_SIZE_Y;
extern const int PLAYER_2_SIZE_Y;
extern const int PLAYER_3_SIZE_Y;
extern const int PLAYER_4_SIZE_Y;
extern const int PLAYER_5_SIZE_Y;
extern const int PLAYER_6_SIZE_Y;



enum Direction { down, left, right, up , none };

#endif // UTILS_HPP
