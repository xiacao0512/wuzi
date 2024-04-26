// Wuzi chess game 
// program by ET-16G, Apr. 16 2024

#include "../include/common.h"
#include "../include/console.h"
#include "../include/coord.h"
#include "../include/menu.h"
#include "../include/misc.h"

void Menu::paintMenu(void)
{
    unsigned int itemAmount = items.size();
    int color;

    paintBlackRect(Rect(coord, Coord(coord.x+width-1, coord.y+itemAmount-1)));
    for(int i = 0; i < (int)itemAmount; i++) {
        if(i == highLight) {
            color = WHITE_BACK_BLACK_CHAR;
        } else {
            color = BLACK_BACK_WHITE_CHAR;
        }

        printf_ex(Coord(coord.x, coord.y+i), color, items[i].c_str());
    } 
    putchar_ex(Coord(coord.x+width-1, coord.y+highLight), WHITE_BACK_BLACK_CHAR, '<');
    gotoXY(Coord(coord.x+width-1, coord.y+highLight));

    return;
}

void Menu::inputPort(int c)
{
    unsigned int itemAmount = items.size();
    if(highLight == 0) {
        highLight = itemAmount;
    }

    if(c == ARROW_UP) {
        highLight--;
    } else if(c == ARROW_DOWN) {
        highLight++;
    }

    highLight = highLight % itemAmount;
    return;
}
