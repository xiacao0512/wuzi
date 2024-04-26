// Wuzi chess game 
// program by ET-16G, Apr. 8 2024

#include <algorithm>
#include <random>
#include "../include/common.h"
#include "../include/console.h"
#include "../include/coord.h"
#include "../include/misc.h"

void gotoXY_Complex(Coord sCoord)
{
    gotoXY(Coord(sCoord.x+CHESSBOARD_X+1, sCoord.y+CHESSBOARD_Y+1));
    return;
}

bool isHorizonalArrow(int c)
{
    if(c == ARROW_LEFT || c == ARROW_RIGHT) {
        return true;
    }
    return false;
}

bool isVerticalArrow(int c)
{
    if(c == ARROW_UP || c == ARROW_DOWN) {
        return true;
    }
    return false;
}

bool isCoordInRange(Coord coord)
{
    if(coord.x < 0 || coord.x >= EDGE_LENGTH) {
        return false;
    }

    if(coord.y < 0 || coord.y >= EDGE_LENGTH) {
        return false;
    }

    return true;
}

void paintBlackRect(Rect rect)
{
    for(int j = rect.upperLeft.y; j <= rect.lowerRight.y; j++) {
        for(int i = rect.upperLeft.x; i <= rect.lowerRight.x; i++) {
            putchar_ex(Coord(i, j), BLACK_BACK_BLACK_CHAR, ' ');
        }
    }

    return;
}

void paintHorizontalStick(int start_x, int y, int length)
{
    for(int i = 0; i < length; i++) {
        putchar_ex(Coord(start_x+i, y), BLACK_BACK_WHITE_CHAR, STICK_HORI);
    }

    return;
}

void paintVerticalStick(int x, int start_y, int length)
{
    for(int i = 0; i < length; i++) {
        putchar_ex(Coord(x, start_y+i), BLACK_BACK_WHITE_CHAR, STICK_VERT);
    }

    return;
}

void paintBox(Rect rect)
{
    putchar_ex(Coord(rect.upperLeft.x, rect.upperLeft.y), BLACK_BACK_WHITE_CHAR, UPPER_LEFT);
    putchar_ex(Coord(rect.lowerRight.x, rect.upperLeft.y), BLACK_BACK_WHITE_CHAR, UPPER_RIGHT);
    putchar_ex(Coord(rect.upperLeft.x, rect.lowerRight.y), BLACK_BACK_WHITE_CHAR, LOWER_LEFT);
    putchar_ex(Coord(rect.lowerRight.x, rect.lowerRight.y), BLACK_BACK_WHITE_CHAR, LOWER_RIGHT);

    paintHorizontalStick(rect.upperLeft.x+1, rect.upperLeft.y, (rect.lowerRight.x-rect.upperLeft.x)-1);
    paintHorizontalStick(rect.upperLeft.x+1, rect.lowerRight.y, (rect.lowerRight.x-rect.upperLeft.x)-1);
    paintVerticalStick(rect.upperLeft.x, rect.upperLeft.y+1, (rect.lowerRight.y-rect.upperLeft.y)-1);
    paintVerticalStick(rect.lowerRight.x, rect.upperLeft.y+1, (rect.lowerRight.y-rect.upperLeft.y)-1);

    return;
}

int getRandomNumber(int max, int min)
{
    int _max = std::max(max, min);
    int _min = std::min(max, min);

    std::random_device dev;
    std::ranlux48 e(dev());

    std::uniform_int_distribution<unsigned int> u(_min, _max);
    return u(e);
}
