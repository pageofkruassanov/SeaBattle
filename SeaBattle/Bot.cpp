#include "Bot.h"

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
