#include "Map.h"

using namespace MyMap;
int Map::mapSize = 10;
char MyMap::Map::getLetters(int index)
{
	return letters[index];
}
int MyMap::Map::getMapSize()
{
	return mapSize;
}
void MyMap::Map::DisplayMap(bool hideShips) const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordCursor;
	coordCursor.X = coordX;
	coordCursor.Y = coordY;

	coordCursor.Y--;
	SetConsoleCursorPosition(hConsole, coordCursor);
	for (int i = 0; i < mapSize; i++)
		std::cout << nums[i];

	coordCursor.X--;
	for (int i = 0; i < mapSize; i++) {
		coordCursor.Y = coordY + i;
		SetConsoleCursorPosition(hConsole, coordCursor);
		std::cout << letters[i];
	}
	if (!hideShips) {
		coordCursor.X = coordX;
		coordCursor.Y = coordY;
		for (int i = 0; i < mapSize; i++) {
			coordCursor.Y = coordY + i;
			SetConsoleCursorPosition(hConsole, coordCursor);
			for (int j = 0; j < mapSize; j++) {
				std::cout << board[i][j];
			}
		}
	}
	else {
		char emptyPlace = ' ';
		coordCursor.X = coordX;
		coordCursor.Y = coordY;
		for (int i = 0; i < mapSize; i++) {
			coordCursor.Y = coordY + i;
			SetConsoleCursorPosition(hConsole, coordCursor);
			for (int j = 0; j < mapSize; j++) {
				if (board[i][j] == 'B')
					std::cout << emptyPlace;
				else {
					std::cout << board[i][j];
				}
			}
		}
	}
}

char** MyMap::Map::getBoard()
{
	return board;
}

std::vector<std::pair<int, int>>& MyMap::Map::getShips()
{
	return ships;
}

void MyMap::Map::RefreshBoard()
{
	for (int i = 0; i < ships.size(); i++) {
		board[ships[i].first][ships[i].second] = 'B';
	}
}

std::pair<int, int> MyMap::Map::findLargestPoint(std::vector<std::pair<int, int>>& ship) const
{
	if (ship.size() == 0)
		throw std::exception("Error / Ship empty / findLargestPoint");
	else if (ship.size() == 1)
		return ship[0];
	else {
		std::pair<int, int> tempPair = ship[0];
		for (int i = 1; i < ship.size(); i++) {
			if (tempPair < ship[i])
				tempPair = ship[i];
		}
		return tempPair;
	}
}

std::pair<int, int> MyMap::Map::findSmallerPoint(std::vector<std::pair<int, int>>& ship) const
{
	if (ship.size() == 0)
		throw std::exception("Error / Ship empty / findLargestPoint");
	else if (ship.size() == 1)
		return ship[0];
	else {
		std::pair<int, int> tempPair = ship[0];
		for (int i = 1; i < ship.size(); i++) {
			if (tempPair > ship[i])
				tempPair = ship[i];
		}
		return tempPair;
	}
}

void MyMap::Map::reservePlace(std::pair<int, int> pointFrom, std::pair<int, int> pointTo, std::vector<std::pair<int, int>>& reservedPlace)
{
	if (pointFrom.first > 0)
		pointFrom.first--;
	if (pointFrom.second > 0)
		pointFrom.second--;
	if (pointTo.first < 9)
		pointTo.first++;
	if (pointTo.second < 9)
		pointTo.second++;

	int tempX = pointFrom.first;
	do {
		if (pointFrom.first == pointTo.first) {
			reservedPlace.push_back(pointFrom);
			pointFrom.second++;
			pointFrom.first = tempX;
		}
		else {
			reservedPlace.push_back(pointFrom);
			pointFrom.first++;
		}
		if (pointFrom == pointTo) {
			reservedPlace.push_back(pointFrom);
		}
		
	} while (pointFrom < pointTo);
}

std::vector<std::pair<int, int>>& MyMap::Map::getReservedPlace()
{
	return reservedPlace;
}

bool MyMap::Map::isReservedPlace(std::vector<std::pair<int, int>> ships, std::vector<std::pair<int, int>> reservedPlace)
{
	for (int i = 0; i < ships.size(); i++) {
		for (int j = 0; j < reservedPlace.size(); j++) {
			if (ships[i] == reservedPlace[j])
				return true;
		}
	}
	return false;
}

bool MyMap::Map::checkShip(std::vector<std::pair<int, int>> ship)
{
	if (ship.size() > 4 || ship.size() < 1)
		return false;
	bool isX = 0, isY = 0;
	int X = ship[0].first;
	int Y = ship[0].second;
	for (int i = 1; i < ship.size(); i++) {
		if (X != ship[i].first)
			isY = true;
	}
	for (int i = 1; i < ship.size(); i++) {
		if (Y != ship[i].second)
			isX = true;
	}
	if (isX == true && isY == true)
		return false;
	
	if (isX) {
		bool up;
		if (ship[0].second > ship[1].second)
			up = true;
		else
			up = false;
		if (up) {
			for (int i = 0; i < ship.size() - 1; i++) {
				if (ship[i].second != ship[i + 1].second + 1)
					return false;
			}
		}
		else {
			for (int i = 0; i < ship.size() - 1; i++) {
				if (ship[i].second != ship[i + 1].second - 1)
					return false;
			}
		}
	}
	else {
		bool right;
		if (ship[0].first < ship[1].first)
			right = true;
		else
			right = false;
		if (right) {
			for (int i = 0; i < ship.size() - 1; i++) {
				if (ship[i].first != ship[i + 1].first - 1)
					return false;
			}
		}
		else {
			for (int i = 0; i < ship.size() - 1; i++) {
				if (ship[i].first != ship[i + 1].first + 1)
					return false;
			}
		}
	}
	return true;
}

MyMap::Map::~Map()
{
	delete nums;
	delete letters;
	for (int i = 0; i < mapSize; i++)
		delete board[i];
	delete board;
}
