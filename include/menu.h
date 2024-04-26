// Wuzi chess game 
// program by ET-16G, Apr. 16 2024

#pragma once
#include <vector>
#include <string>
#include "coord.h"

using StringVector = std::vector<std::string>;

class Menu {
public:
    Menu() = default;

    Menu(int _width, Coord _coord) 
    {
        width = _width;
        coord = _coord;
        highLight = 0;

        return;
    }

    void add(std::string item)
    {
        items.push_back(item);
        return;
    }

    int getHighLight(void)
    {
        return highLight;
    }

    void paintMenu(void);
    void inputPort(int c);

private:
    int width, highLight;
    StringVector items;
    Coord coord;
};
