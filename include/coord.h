// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once
#include <algorithm>

class Coord {
public:
    Coord(void)
    {
        x = 0;
        y = 0;
    }

    Coord(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int x, y;
};

class Rect {
public:
    Rect(void)
    {
        upperLeft = Coord(0, 0);
        lowerRight = Coord(0, 0);
    }

    Rect(Coord _upperLeft, Coord _lowerRight)
    {
        int upperLeft_x = std::min(_upperLeft.x, _lowerRight.x);
        int upperLeft_y = std::min(_upperLeft.y, _lowerRight.y);
        int lowerRight_x = std::max(_upperLeft.x, _lowerRight.x);
        int lowerRight_y = std::max(_upperLeft.y, _lowerRight.y);

        upperLeft = Coord(upperLeft_x, upperLeft_y);
        lowerRight = Coord(lowerRight_x, lowerRight_y);
    }

    Coord upperLeft, lowerRight;
};
