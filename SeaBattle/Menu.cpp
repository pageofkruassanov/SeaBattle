#include "Menu.h"

void Menu::RefreshGameMode()
{
	if (isHumanGame) {
		secondaryItems[0][0] = '+';
		secondaryItems[1][0] = ' ';
	}
	else {
		secondaryItems[0][0] = ' ';
		secondaryItems[1][0] = '+';
	}

	if (!isRandomSetShips) {
		secondaryItems[2][0] = '+';
		secondaryItems[3][0] = ' ';
	}
	else {
		secondaryItems[2][0] = ' ';
		secondaryItems[3][0] = '+';
	}

	if (!isIntellectualGame) {
		secondaryItems[4][0] = '+';
		secondaryItems[5][0] = ' ';
	}
	else {
		secondaryItems[4][0] = ' ';
		secondaryItems[5][0] = '+';
	}
}

Menu::Menu(int coordX, int coordY)
{
	this->coordX = coordX;
	this->coordY = coordY;
	mainItems = new std::string[SIZE_MAIN_MENU]{ "НАЧАТЬ ИГРУ", "ВЫХОД" };
	secondaryItems = new std::string[SIZE_SECONDARY_MENU]{ " Человек - Компьютер", " Компьютер - Компьютер", " Расстановка кораблей вручную", " Рандомная расстановка кораблей", " Легкий режим игры", " Сложный режим игры" };
	isHumanGame = 1;
	isRandomSetShips = 0;
	isIntellectualGame = 0;
	isGameStart = 0;
	isExit = 0;
}

void Menu::DisplayMenu(int arrow)
{
	RefreshGameMode();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordCursor;
	coordCursor.X = coordX;

	for (int i = 0; i < SIZE_MAIN_MENU; i++) {
		coordCursor.Y = coordY + i;
		SetConsoleCursorPosition(hConsole, coordCursor);
		if (arrow == i)
			std::cout << "*" << mainItems[i];
		else
			std::cout << " " << mainItems[i];
	}

	coordCursor.X = coordX + HORIZONTAL_SHIFT;
	int tempVerShift = 0;
	for (int i = 0; i < SIZE_SECONDARY_MENU; i++) {
		if (i > 0 && i % 2 == 0) {
			tempVerShift++;
			coordCursor.Y = coordY - VERTICAL_SHIFT + i + tempVerShift;
			SetConsoleCursorPosition(hConsole, coordCursor);
		}
		else {
			coordCursor.Y = coordY - VERTICAL_SHIFT + i + tempVerShift;
			SetConsoleCursorPosition(hConsole, coordCursor);
		}
		if (arrow - SIZE_MAIN_MENU == i)
			std::cout << "*" << secondaryItems[i];
		else
			std::cout << " " << secondaryItems[i];
	}
}

void Menu::UpdateMenu(int index)
{
	if (index >= 0 && index <= 1) {
		(index == 0) ? isGameStart = 1 : isGameStart = 0;
		(index == 1) ? isExit = 1 : isExit = 0;
	}
	else if (index >= 2 && index <= 7) {
		if (index == 2)
			isHumanGame = 1;
		else if (index == 3)
			isHumanGame = 0;
		else if (index == 4)
			isRandomSetShips = 0;
		else if (index == 5)
			isRandomSetShips = 1;
		else if (index == 6)
			isIntellectualGame = 0;
		else if (index == 7)
			isIntellectualGame = 1;
	}
	else
		throw std::exception("Error / Not correct index / UpdateMenu");
	RefreshGameMode();
}

bool Menu::getGameStart()
{
	return isGameStart;
}

bool Menu::getExit()
{
	return isExit;
}

bool Menu::getIsHumanGame()
{
	return isHumanGame;
}

bool Menu::getIsRandomSetShips()
{
	return isRandomSetShips;
}

void Menu::setGameStart(bool isGameStart)
{
	this->isGameStart = isGameStart;
}
