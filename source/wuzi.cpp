// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#include <conio.h>
#include "..\include\wuzi.h"
#include "..\include\ui.h"

void Wuzi::exec(void)
{
    initScreen();
    chessboard = Chessboard();

    switchScene(1);
    while(true) {
        inputPort(getch());
    }

    initScreenWhenQuit();
    return;
}

