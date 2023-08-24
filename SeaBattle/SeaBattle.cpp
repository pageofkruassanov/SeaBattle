#include <iostream>
#include "Map.h"
#include "Player.h"
#include <vector>
#include "Bot.h"
using namespace MyMap;

int main()
{
    Bot bot1("Ok", 0);
    Player pl1("Pavlo", 0);
    Map map1(5, 5);
    Map map2(20, 5);
    std::vector<std::pair<int, int>> vector;
    /*vector.push_back(std::pair(5, 7));
    vector.push_back(std::pair(5, 8));
    vector.push_back(std::pair(5, 9));
    vector.push_back(std::pair(5, 10));*/
    try {
        pl1.setShips(map1, 4);
        bot1.setShips(map2, 4);
    }
    catch (std::exception ex) {
        std::cerr << ex.what();
    }
    map1.DisplayMap(0);
    map2.DisplayMap(0);

}
