#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
//#include <utility> 

//enum boardData {
//	_F,    // free place
//	_R,    // reserved place
//};

namespace MyMap {
	class Map
	{
		int coordX, coordY; // map point coordinates
		int* nums;
		static int mapSize;
		char* letters;
		char** board;
		std::vector<std::pair<int, int>> ships; // ships coordinates
		std::vector<std::pair<int, int>> reservedPlace;
	public:
		Map(int coordX, int coordY) : coordX{ coordX - 1 }, coordY{ coordY - 1 } {
			nums = new int[mapSize];
			for (int i = 0; i < mapSize; i++)
				nums[i] = i;
			letters = new char[mapSize];
			letters[0] = 'A';
			for (int i = 1; i < mapSize; i++)
				letters[i] = letters[i - 1] + 1;
			board = new char* [mapSize];
			for (int i = 0; i < mapSize; i++)
				board[i] = new char[mapSize];
			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					board[i][j] = ' ';
				}
			}
		};
		char getLetters(int index);
		static int getMapSize();
		void DisplayMap(bool hideShips) const;
		char** getBoard();
		std::vector<std::pair<int, int>>& getShips();
		void RefreshBoard();
		std::pair<int, int> findLargestPoint(std::vector<std::pair<int, int>>& ship) const;
		std::pair<int, int> findSmallerPoint(std::vector<std::pair<int, int>>& ship) const;
		void reservePlace(std::pair<int, int> pointFrom, std::pair<int, int> pointTo, std::vector<std::pair<int, int>>& reservedPlace);
		std::vector<std::pair<int, int>>& getReservedPlace();
		bool isReservedPlace(std::vector<std::pair<int, int>> ships, std::vector<std::pair<int, int>> reservedPlace);
		bool checkShip(std::vector<std::pair<int, int>> ship);
		~Map();
	};
}

