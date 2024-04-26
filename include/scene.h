// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once
#include "common.h"
#include "coord.h"
#include "menu.h"

struct ScenePack_1 {
    Menu modeChooseMenu;
};

struct ScenePack_2 {
    int mode;
    Player mover;
    Coord currentCoord;
};

struct ScenePack_3 {
    ScenePack_3(void) {
        winner = Player::Invalid;
    }

    ScenePack_3(Player _winner) {
        winner = _winner;
    }

    Player winner;
};

struct ScenePack_4 {
    ScenePack_4(void) {
        isEnable = false;
    }

    ScenePack_4(bool _isEnable) {
        isEnable = _isEnable;
    }

    bool isEnable;
    Menu quitMenu;
    ScenePack_2 sp2;
};

struct ScenePacks {
    ScenePack_1 _1;
    ScenePack_2 _2;
    ScenePack_3 _3;
    ScenePack_4 _4;
};
