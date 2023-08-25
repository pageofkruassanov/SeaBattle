#pragma once
#include <iostream>
#include <Windows.h>
#define SIZE_MAIN_MENU 2
#define SIZE_SECONDARY_MENU 6
#define HORIZONTAL_SHIFT 30
#define VERTICAL_SHIFT 3

class Menu
{
	int coordX;
	int coordY;
	std::string* mainItems;
	std::string* secondaryItems;
	bool isHumanGame;
	bool isRandomSetShips;
	bool isIntellectualGame;
	void RefreshGameMode();
	bool isGameStart;
	bool isExit;
public:
	Menu(int coordX, int coordY);

	void DisplayMenu(int arrow);
	void UpdateMenu(int index);

	bool getGameStart();
	bool getExit();
	bool getIsHumanGame();
	bool getIsRandomSetShips();

	void setGameStart(bool isGameStart);
};

