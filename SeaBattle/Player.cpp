#include "Player.h"

// not end:

void Player::makeMove(std::string position, Map& map)
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

	if (map.getBoard()[X][Y] == ' ')
		map.getBoard()[X][Y] = '*';
	else if (map.getBoard()[X][Y] == 'B')
		map.getBoard()[X][Y] = 'X';
}

void Player::setShips(std::vector<std::pair<int,int>> ship, Map& map) {
	if (map.isReservedPlace(ship, map.getReservedPlace()))
		throw std::exception("Error / Reserved Place / .. / isReservedPlace");
	if (!map.checkShip(ship))
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
