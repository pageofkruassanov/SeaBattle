#include <iostream>
#include "Map.h"
#include "Player.h"
#include <vector>
#include "Bot.h"
#include "Menu.h"
#include <conio.h>

enum Keys {
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,
    ESC = 27,
    ENTER = 13
};

#define SIZE_MENU 8

int main()
{
    setlocale(0, "Rus");
    Menu menu(40, 10);
    
    int arrow = 0;
    char symb;
    while (!menu.getExit()) {
        menu.DisplayMenu(arrow);
        symb = _getch();
        switch (symb) {
        case 's':
        case DOWN:
        {
            ++arrow;
            if (arrow > SIZE_MENU - 1)
                arrow = 0;
            break;
        }
        case 'w':
        case UP:
        {
            --arrow;
            if (arrow < 0)
                arrow = SIZE_MENU - 1;
            break;
        }
        case ENTER:
        {
            menu.UpdateMenu(arrow);
            if (menu.getGameStart()) {
                if (menu.getIsHumanGame()) {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    CONSOLE_CURSOR_INFO cursorInfo;
                    GetConsoleCursorInfo(hConsole, &cursorInfo);
                    cursorInfo.bVisible = FALSE; 
                    SetConsoleCursorInfo(hConsole, &cursorInfo);


                    system("cls");
                    std::string playerName;
                    std::cout << "¬ведите им€ игрока: ";
                    std::cin >> playerName;

                    Player player(playerName, 0);
                    Bot bot(0);

                    system("cls");
                    Map firstMap(20, 10);
                    Map secondMap(40, 10);
                    player.setShips(firstMap, 4);
                    bot.setShips(secondMap, 4);
                    firstMap.DisplayMap(true);
                    secondMap.DisplayMap(false);
                    system("pause > nul");

                    cursorInfo.bVisible = TRUE;
                    SetConsoleCursorInfo(hConsole, &cursorInfo);
                }
                else {

                }
                
            }
            break;
        }
        }
    }
    system("cls");


}
