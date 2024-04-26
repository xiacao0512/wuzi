// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#include <stdio.h>
#include "..\include\common.h"
#include "..\include\console.h"
#include "..\include\menu.h"
#include "..\include\misc.h"
#include "..\include\scene.h"
#include "..\include\ui.h"
#include "..\include\wuzi.h"

void Wuzi::switchScene(int _scene)
{
    scene = _scene;

    switch(scene) {
        case 1:
            switchScene_1();
            break;
        case 2:
            switchScene_2();
            break;
        case 3:
            switchScene_3();
            break;
        case 4:
            switchScene_4();
            break;
    }

    return;
}

void Wuzi::switchScene_1(void)
{
    ScenePack_1 &sp1 = scenePacks._1;
    ScenePack_4 &sp4 = scenePacks._4;

    if(sp4.isEnable == true) {
        sp4.isEnable = false;
    }

    chessboard = Chessboard();
    chessboard.paintChessboard();
    paintMainMenu();

    sp1.modeChooseMenu = Menu(14, Coord(WORD_X, 13));
    sp1.modeChooseMenu.add("1 Player     ");
    sp1.modeChooseMenu.add("2 Players    ");
    sp1.modeChooseMenu.add("Quit         ");
    sp1.modeChooseMenu.paintMenu();

    return;
}

void Wuzi::switchScene_2(void)
{
    ScenePack_1 &sp1 = scenePacks._1;
    ScenePack_2 &sp2 = scenePacks._2;
    ScenePack_4 &sp4 = scenePacks._4;

    if(sp4.isEnable == true) {
        sp2 = sp4.sp2;
        sp4.isEnable = false;
    } else {
        sp2.mode = sp1.modeChooseMenu.getHighLight();
        sp2.mover = Player::P1;
        sp2.currentCoord = Coord(0, 0);
    }
    paintGameElements();

    gotoXY_Complex(sp2.currentCoord);
    paintCoord(Coord(0, 0));

    return;
}

void Wuzi::switchScene_3(void)
{
    ScenePack_2 &sp2 = scenePacks._2;
    ScenePack_3 &sp3 = scenePacks._3;

    sp3.winner = sp2.mover;

    chessboard.paintChessboard();
    paintGamePanel();
    paintWinnerPanel(scenePacks._3.winner);

    return;
}

void Wuzi::switchScene_4(void)
{
    ScenePack_2 &sp2 = scenePacks._2;
    ScenePack_4 &sp4 = scenePacks._4;

    sp4.isEnable = true;
    sp4.sp2 = sp2;

    sp4.quitMenu = Menu(10, Coord(30, 14));
    sp4.quitMenu.add("No        ");
    sp4.quitMenu.add("Yes       ");
    paintQuitMenu(sp4.quitMenu);

    return;
}
