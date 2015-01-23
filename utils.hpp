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


enum direction { down, left, right, up , none };

#endif // UTILS_HPP
