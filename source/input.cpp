// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "..\include\combat.h"
#include "..\include\common.h"
#include "..\include\console.h"
#include "..\include\misc.h"
#include "..\include\scene.h"
#include "..\include\ui.h"
#include "..\include\wuzi.h"

void gotoXY_Complex(Coord sCoord);
Coord moveCoordInChessboard(Coord coord, int c);
Player moverReverse(Player mover);

void Wuzi::inputPort(int c)
{
    switch(scene) {
        case 1:
            inputPort_1(c);
            break;
        case 2:
            inputPort_2(c);
            break;
        case 3:
            inputPort_3(c);
            break;
        case 4:
            inputPort_4(c);
            break;
    }

    return;
}

void Wuzi::inputPort_1(int c)
{
    ScenePack_1 &sp1 = scenePacks._1;

    if(isVerticalArrow(c) == true) {
        sp1.modeChooseMenu.inputPort(c);
        sp1.modeChooseMenu.paintMenu();
    }

    if(c == ENTER) {
        int highLight = sp1.modeChooseMenu.getHighLight();
        if(highLight == MODE_QUIT) {
            initScreenWhenQuit();
            exit(0);
        } else {
            switchScene(2);
        }
    }

    return;
}

void Wuzi::inputPort_2(int c)
{
    ScenePack_2 &sp2 = scenePacks._2;
    Coord coord = sp2.currentCoord;

    if(c == ENTER) {
        if(chessboard.getPieceFromCoord(coord).player == Player::Invalid) {
            chessboard.setPieceToCoord(coord, Piece(sp2.mover));

replace:
            int direction = chessboard.checkGameover(coord);
            if(direction != NO_WIN) {
                chessboard.flagWinChesses(coord, direction);
                switchScene(3);
                return;
            }

            sp2.mover = moverReverse(sp2.mover);
            paintGameElements();
            paintCoord(sp2.currentCoord);

            if(sp2.mode == MODE_1PLAYER && sp2.mover == Player::P2) {
                Sleep(500);
                
                Solution sol = Solution(chessboard);
                Coord coordComputer = sol.placing();
                chessboard.setPieceToCoord(coordComputer, Piece(sp2.mover));
                gotoXY_Complex(sp2.currentCoord);

                goto replace;
            }
        }
    }

    if(isVerticalArrow(c) == true || isHorizonalArrow(c) == true) {
        coord = moveCoordInChessboard(coord, c);
        sp2.currentCoord = coord;
        gotoXY_Complex(coord);
        paintCoord(coord);
    }

    if(c == ESC) {
        switchScene(4);
    }

    return;
}

Coord moveCoordInChessboard(Coord coord, int c)
{
    Coord movedCoord = coord;
    switch(c) {
        case ARROW_UP:
            movedCoord.y--;
            break;

        case ARROW_DOWN:
            movedCoord.y++;
            break;

        case ARROW_LEFT:
            movedCoord.x--;
            break;

        case ARROW_RIGHT:
            movedCoord.x++;
            break;
    }

    if(isCoordInRange(movedCoord) == false) {
        movedCoord = coord;
    }
    return movedCoord;
}

Player moverReverse(Player mover)
{
    if(mover == Player::P1) {
        mover = Player::P2;
    } else if(mover == Player::P2) {
        mover = Player::P1;
    }

    return mover;
}

void Wuzi::inputPort_3(int __attribute__((unused)) c)
{
    switchScene(1);
    return;
}

void Wuzi::inputPort_4(int c)
{
    ScenePack_4 &sp4 = scenePacks._4;

    if(isVerticalArrow(c) == true) {
        sp4.quitMenu.inputPort(c);
        paintQuitMenu(sp4.quitMenu);
    }

    if(c == ENTER) {
        if(sp4.quitMenu.getHighLight() == 0) {
            switchScene(2);
        } else {
            switchScene(1);
        }
    }

    return;
}
