// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once

#include "common.h"
#include "menu.h"

void initScreen(void);
void initScreenWhenQuit(void);
void paintBox(Rect rect);

void paintMainMenu(void);
void paintGamePanel(void);
void paintMoverPanel(Player player);
void paintWinnerPanel(Player winner);
void paintQuitMenu(Menu quitMenu);
void paintCoord(Coord coord);