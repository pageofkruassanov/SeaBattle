#pragma once
#include "Map.h"
#include <exception>
#include <iostream>
#include <vector>
using namespace MyMap;
class Player
{
	std::string name;
	int points;
public:
	Player(std::string name, int points) : name{ name }, points{ points } {};
	void makeMove(std::string position, MyMap::Map& map);
	void setShips(std::vector<std::pair<int, int>> ship, Map& map);

};

