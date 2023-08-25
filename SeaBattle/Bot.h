#pragma once
#include "Player.h"
#include <iostream>

const int sizeArrName = 15;
const std::string arrayName[sizeArrName] = { "Bob", "Jack", "Harry", "Jacob", "Charlie", "Liam", "Mason", "William", "Thomas", "Oliver", "George", "James", "John", "Joseph" , "Richard" };

class Bot : public Player
{

	bool isIntellectualGame;

	std::vector<std::pair<int, int>> hitShots;
	std::vector<std::pair<int, int>> reservedMoves;
	bool checkReservedMoves(std::pair<int, int> move);

public:
	Bot() : Player{arrayName[rand() % sizeArrName], 0} {};
	Bot(int points) : Player{ arrayName[rand() % sizeArrName],points } {};
	void setShips(Map& map, const int MAX_SIZE_SHIP);
	bool makeMove(Map& map);
	
};

