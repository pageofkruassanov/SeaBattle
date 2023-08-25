#include "Bot.h"

bool Bot::checkReservedMoves(std::pair<int, int> move)
{
	for (int i = 0; i < reservedMoves.size(); i++) {
		if (reservedMoves[i] == move)
			return false;
	}
	return true;
}

void Bot::setShips(Map& map, const int MAX_SIZE_SHIP)
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

bool Bot::makeMove(Map& map)
{
	std::pair<int, int> move;
	do {
		move.first = 0 + rand() % (Map::getMapSize() - 1 - 0 + 1);
		move.second = 0 + rand() % (Map::getMapSize() - 1 - 0 + 1);
	} while (checkReservedMoves(move));
	if (map.getBoard()[move.first][move.second] == ' ') {
		map.getBoard()[move.first][move.second] = '*';
		pastMoves.push_back(move);
		return false;
	}
	else if (map.getBoard()[move.first][move.second] == 'B') {
		map.getBoard()[move.first][move.second] = 'X';
		pastMoves.push_back(move);
		hitShots.push_back(move);
		points += 10;
		return true;
	}
}
