// Wuzi chess game 
// program by ET-16G, Apr. 22 2024

#pragma once
#include "chessboard.h"
#include "common.h"
#include "coord.h"

class Solution {
public:
    Solution() = delete;
    Solution(Chessboard _chessboard)
    {
        chessboard = _chessboard;
        resetWeightTable();
    }

    Coord placing(void);

private:
    void resetWeightTable(void)
    {
        for(int i = 0; i < EDGE_LENGTH; i++) {
            for(int j = 0; j < EDGE_LENGTH; j++) {
                if(chessboard.getPieceFromCoord(Coord(i, j)).player == Player::Invalid) {
                    weight[i][j] = 0;
                } else {
                    weight[i][j] = -1;
                }
            }
        }
    }

    void assignWeight(void);
    int assignWeight_signle(Coord coord);
    Coord pickupBestCoord(void);

    Chessboard chessboard;
    int weight[EDGE_LENGTH][EDGE_LENGTH];
};
