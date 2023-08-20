#include <iostream>
#include "Map.h"
#include "Player.h"
#include <vector>
using namespace MyMap;

int main()
{
    Player pl1("Pavlo", 0);
    Map map1(5, 5);
    std::vector<std::pair<int, int>> vector;
    vector.push_back(std::pair(5, 7));
    vector.push_back(std::pair(5, 8));
    vector.push_back(std::pair(5, 9));
    vector.push_back(std::pair(5, 10));
    try {
        pl1.setShips(vector, map1);
    }
    catch (std::exception ex) {
        std::cerr << ex.what();
    }
    map1.DisplayMap(0);

}
