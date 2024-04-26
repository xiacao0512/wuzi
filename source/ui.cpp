// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#include <algorithm>
#include <stdlib.h>
#include <string>
#include "..\include\common.h"
#include "..\include\console.h"
#include "..\include\menu.h"
#include "..\include\misc.h"
#include "..\include\ui.h"
#include "..\include\version.h"
#include "..\include\wuzi.h"

void printVersionInfo(void);
void paintBasicElements(void);

void initScreen(void)
{
    system("chcp 437");
    system("mode con cols=80 lines=24");
    system("cls");
    
    return;
}

void initScreenWhenQuit(void)
{
    putchar_ex(Coord(0, 0), BLACK_BACK_WHITE_CHAR, ' ');
    system("cls");
    return;
}

void printVersionInfo(void)
{
    paintBlackRect(Rect(Coord(CONSOLE_WIDTH-10, 22), Coord(CONSOLE_WIDTH-2, 22)));
    printf_ex(Coord(WORD_X, 22), BLACK_BACK_WHITE_CHAR, "Wuzi (build %d), by ET-16G", BUILD_NUMBER);
    return;
}

void paintBasicElements(void)
{
    paintBlackRect(Rect(Coord(SPILT_LINE_X, 0), Coord(CONSOLE_WIDTH-1, CONSOLE_HEIGHT-1)));
    paintVerticalStick(SPILT_LINE_X, 0, CONSOLE_HEIGHT);
    printVersionInfo();

    return;
}

void paintMainMenu(void)
{
    paintBasicElements();

    printf_ex(Coord(WORD_X, 3), BLACK_BACK_WHITE_CHAR, "Wuzi is a board game that widely popular in China,");
    printf_ex(Coord(WORD_X, 4), BLACK_BACK_WHITE_CHAR, "Japan and Korea. ");
    printf_ex(Coord(WORD_X, 6), BLACK_BACK_WHITE_CHAR, "During the game, players take turns placing black");
    printf_ex(Coord(WORD_X, 7), BLACK_BACK_WHITE_CHAR, "and white (in this program, is blue and green)");
    printf_ex(Coord(WORD_X, 8), BLACK_BACK_WHITE_CHAR, "pieces on the board with the goal of creating");
    printf_ex(Coord(WORD_X, 9), BLACK_BACK_WHITE_CHAR, "an unbroken line of five pieces in any direction.");

    return;
}

void paintGamePanel(void)
{
    paintBasicElements();

    printf_ex(Coord(WORD_X, 3), BLACK_BACK_WHITE_CHAR, "Press arrow keys to move your cursor.");
    printf_ex(Coord(WORD_X, 4), BLACK_BACK_WHITE_CHAR, "Press enter key to placing piece.");
    printf_ex(Coord(WORD_X, 5), BLACK_BACK_WHITE_CHAR, "Press esc key to quit.");

    return;
}

void paintMoverPanel(Player player)
{
    int p = (int)player;
    
    paintBlackRect(Rect(Coord(WORD_X, 7), Coord(59, 8)));
    printf_ex(Coord(WORD_X, 7), BLACK_BACK_WHITE_CHAR, "Player %d is placing piece...", p);

    return;
}

void paintWinnerPanel(Player winner)
{
    int p = (int)winner;

    paintBasicElements();
    printf_ex(Coord(WORD_X, 7), BLACK_BACK_WHITE_CHAR, "Player %d is the winner! Congratulation!", p);
    printf_ex(Coord(WORD_X, 8), BLACK_BACK_WHITE_CHAR, "Press any key to quit.", p);

    return;
}

void paintQuitMenu(Menu quitMenu)
{
    paintBlackRect(Rect(Coord(WORD_X, 11), Coord(50, 15)));
    paintBox(Rect(Coord(QUIT_BOX_X_UL, QUIT_BOX_Y_UL), Coord(QUIT_BOX_X_LR, QUIT_BOX_Y_LR)));
    printf_ex(Coord(QUIT_BOX_X_UL+1, QUIT_BOX_Y_UL-2), BLACK_BACK_WHITE_CHAR, "Are you confirm to quit?");

    quitMenu.paintMenu();
    return;
}

void paintCoord(Coord coord)
{
    paintBlackRect(Rect(Coord(CONSOLE_WIDTH-10, 22), Coord(CONSOLE_WIDTH-2, 22)));
    printf_ex(Coord(CONSOLE_WIDTH-10, 22), BLACK_BACK_WHITE_CHAR, "(%d, %d)", coord.x, coord.y);
    gotoXY_Complex(coord);

    return;
}

void Wuzi::paintGameElements(void)
{
    ScenePack_2 &sp2 = scenePacks._2;

    chessboard.paintChessboard();
    paintGamePanel();
    paintMoverPanel(sp2.mover);
    gotoXY_Complex(sp2.currentCoord);

    return;
}
