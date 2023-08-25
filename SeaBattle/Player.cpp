#include "Player.h"

// not end:

bool Player::makeMove(std::string position, Map& map)
{
	if (position.length() > 2 || position.length() < 2)
		throw std::exception("Error /Length position input/ makeMove");

	char tempSymbol = position[0];
	int X = -1;
	for (int i = 0; i < Map::getMapSize(); i++) {
		if (position[0] == map.getLetters(i))
			X = i;
		if (X != -1)
			break;
	}
	if (X == -1)
		throw std::exception("Error /coord Y/ makeMove");

	position.erase(0, 1);

	int Y = -1;
	Y = std::atoi(position.c_str());
	if (Y == -1 || Y < 0 || Y > 9)
		throw std::exception("Error /coord X/ makeMove");

	for (int i = 0; i < pastMoves.size(); i++)
		if (pastMoves[i].first == X && pastMoves[i].second == Y)
			throw std::exception("Error/ You've been to this place before! / makeMove");

	if (map.getBoard()[X][Y] == ' ') {
		map.getBoard()[X][Y] = '*';
		pastMoves.push_back(std::make_pair(X, Y));
		return false;
	}
	else if (map.getBoard()[X][Y] == 'B') {
		map.getBoard()[X][Y] = 'X';
		points += 10;
		pastMoves.push_back(std::make_pair(X, Y));
		return true;
	}
}

void Player::setShips(Map& map,const int MAX_SIZE_SHIP)
{
	int amountTypeShips = 0;
	const int minCoord = 0;
	const int maxCoord = 9;
	std::vector<std::pair<int, int>> tempShip;
	
	do {
		tempShip = createRandomShip(MAX_SIZE_SHIP - amountTypeShips, minCoord, maxCoord);
	} while (map.isReservedPlace(tempShip, map.getReservedPlace()));
	for (int i = 0; i < MAX_SIZE_SHIP - amountTypeShips; i++) {
		map.getShips().push_back(tempShip[i]);
	}
	map.reservePlace(map.findSmallerPoint(tempShip), map.findLargestPoint(tempShip), map.getReservedPlace());
	tempShip.clear();
	++amountTypeShips;

	for (int i = 0; i < amountTypeShips + 1; i++) {
		do {
			tempShip = createRandomShip(MAX_SIZE_SHIP - amountTypeShips, minCoord, maxCoord);
		} while (map.isReservedPlace(tempShip, map.getReservedPlace()));
		for (int i = 0; i < MAX_SIZE_SHIP - amountTypeShips; i++) {
			map.getShips().push_back(tempShip[i]);
		}
		map.reservePlace(map.findSmallerPoint(tempShip), map.findLargestPoint(tempShip), map.getReservedPlace());
		tempShip.clear();
	}

	++amountTypeShips;
	for (int i = 0; i < amountTypeShips + 1; i++) {
		do {
			tempShip = createRandomShip(MAX_SIZE_SHIP - amountTypeShips, minCoord, maxCoord);
		} while (map.isReservedPlace(tempShip, map.getReservedPlace()));
		for (int i = 0; i < MAX_SIZE_SHIP - amountTypeShips; i++) {
			map.getShips().push_back(tempShip[i]);
		}
		map.reservePlace(map.findSmallerPoint(tempShip), map.findLargestPoint(tempShip), map.getReservedPlace());
		tempShip.clear();
	}

	++amountTypeShips;
	for (int i = 0; i < amountTypeShips + 1; i++) {
		do {
			tempShip = createRandomShip(MAX_SIZE_SHIP - amountTypeShips, minCoord, maxCoord);
		} while (map.isReservedPlace(tempShip, map.getReservedPlace()));
		for (int i = 0; i < MAX_SIZE_SHIP - amountTypeShips; i++) {
			map.getShips().push_back(tempShip[i]);
		}
		map.reservePlace(map.findSmallerPoint(tempShip), map.findLargestPoint(tempShip), map.getReservedPlace());
		tempShip.clear();
	}
	map.RefreshBoard();

}

std::string Player::getName()
{
	return name;
}

int Player::getPoints()
{
	return points;
}

std::vector<std::pair<int, int>> Player::createRandomShip(const int MAX_SIZE, int minCoord, int maxCoord)
{
	srand(time(0));
	bool isVertical = rand() % 2;

	std::vector<std::pair<int, int>> ship;
	if (isVertical) {
		std::pair<int, int> firstCoord;
		firstCoord.first = minCoord + rand() % (maxCoord - minCoord + 1);
		firstCoord.second = minCoord + rand() % (maxCoord - minCoord + 1);
		ship.push_back(firstCoord);
		if (ship[0].first + MAX_SIZE > maxCoord) {
			for (int i = 1; i < MAX_SIZE; i++) {
				std::pair<int, int> tempShip;
				tempShip.first = ship[0].first - i;
				tempShip.second = ship[0].second;
				ship.push_back(tempShip);
			}
		}
		else {
			for (int i = 1; i < MAX_SIZE; i++) {
				std::pair<int, int> tempShip;
				tempShip.first = ship[0].first + i;
				tempShip.second = ship[0].second;
				ship.push_back(tempShip);
			}
		}
	}
	else {
		std::pair<int, int> firstCoord;
		firstCoord.first = minCoord + rand() % (maxCoord - minCoord + 1);
		firstCoord.second = minCoord + rand() % (maxCoord - minCoord + 1);
		ship.push_back(firstCoord);
		if (ship[0].second + MAX_SIZE > maxCoord) {
			for (int i = 1; i < MAX_SIZE; i++) {
				std::pair<int, int> tempShip;
				tempShip.first = ship[0].first;
				tempShip.second = ship[0].second - i;
				ship.push_back(tempShip);
			}
		}
		else {
			for (int i = 1; i < MAX_SIZE; i++) {
				std::pair<int, int> tempShip;
				tempShip.first = ship[0].first;
				tempShip.second = ship[0].second + i;
				ship.push_back(tempShip);
			}
		}
	}
	return ship;

}

void Player::setShips(std::vector<std::pair<int,int>> ship, Map& map) {
	if (map.isReservedPlace(ship, map.getReservedPlace()))
		throw std::exception("Error / Reserved Place / .. / isReservedPlace");
	else if (!map.checkShip(ship))
		throw std::exception("Error / Ship coords not correct / .. / checkShip");
	int tempSize = ship.size();
	for (int i = 0; i < tempSize; i++) {
		if (ship[i].first < 0 || ship[i].first > 9)
			throw std::exception("Error / Ship coord X not correct / setShips");
		else if (ship[i].second < 0 || ship[i].second > 9)
			throw std::exception("Error / Ship coord Y not correct / setShip");
		else
			map.getShips().push_back(ship[i]);
	}
	map.RefreshBoard();
	map.reservePlace(map.findSmallerPoint(ship), map.findLargestPoint(ship), map.getReservedPlace());
}
