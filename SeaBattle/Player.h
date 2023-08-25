#pragma once
#include "Map.h"
#include <exception>
#include <iostream>
#include <vector>

class Player
{
protected:
	std::string name;
	int points;
	std::vector<std::pair<int, int>> createRandomShip(const int MAX_SIZE, int minCoord, int maxCoord);
	std::vector<std::pair<int, int>> pastMoves;
public:
	Player(std::string name, int points) : name{ name }, points{ points } {};
	virtual bool makeMove(std::string position, Map& map);
	virtual void setShips(std::vector<std::pair<int, int>> ship, Map& map);
	virtual void setShips(Map& map, const int MAX_SIZE_SHIP);
	std::string getName();
	int getPoints();
};

