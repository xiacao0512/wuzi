// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once
#include "chessboard.h"
#include "scene.h"

struct Wuzi {
    void exec(void);
    void switchScene(int _scene);
    void inputPort(int c);

    int scene;
    Chessboard chessboard;
    ScenePacks scenePacks;

private:
    void switchScene_1(void);
    void switchScene_2(void);
    void switchScene_3(void);
    void switchScene_4(void);

    void inputPort_1(int c);
    void inputPort_2(int c);
    void inputPort_3(int c);
    void inputPort_4(int c);

    void paintGameElements(void);
};
