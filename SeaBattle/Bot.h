#pragma once
#include "Player.h"
#include <iostream>

const int sizeArrName = 15;
const std::string arrayName[sizeArrName] = { "Bob", "Jack", "Harry", "Jacob", "Charlie", "Liam", "Mason", "William", "Thomas", "Oliver", "George", "James", "John", "Joseph" , "Richard" };

class Bot : private Player
{

	bool isIntellectualGame;
public:
	Bot() : Player{arrayName[rand() % sizeArrName], 0} {};
	Bot(int points) : Player{ arrayName[rand() % sizeArrName],points } {};
	Bot(std::string name, int points) : Player{ name, points } {};
	void setShips(Map& map, const int MAX_SIZE_SHIP) override;
	
};

