// Wuzi chess game 
// program by ET-16G, Apr. 22 2024

#include <vector>
#include "../include/chessboard.h"
#include "../include/combat.h"
#include "../include/console.h"
#include "../include/coord.h"
#include "../include/misc.h"

int score(int length, int free);

Coord Solution::placing(void)
{
    assignWeight();   
    return pickupBestCoord();
}

void Solution::assignWeight(void)
{
    for(int i = 0; i < EDGE_LENGTH; i++) {
        for(int j = 0; j < EDGE_LENGTH; j++) {
            if(weight[i][j] == 0) {
                weight[i][j] = assignWeight_signle(Coord(i, j));
            }
        }
    }

    return;
}

int Solution::assignWeight_signle(Coord coord)
{
    Player enumPlayers[2] = {
        Player::P1, Player::P2
    };

    int result = 0;
    for(int i = 0; i < 2; i++) {
        Player baseMover = enumPlayers[i];
        chessboard.setPieceToCoord(coord, Piece(baseMover));
        for(int direction = HORIZONTAL; direction <= RIGHT_OBLIQUE; direction++) {
            result += score(chessboard.checkGameover_singleDirection(direction, coord),
                            chessboard.amountOfFreeExtremePoint(direction, coord)); 
        }
    }

    chessboard.setPieceToCoord(coord, Piece(Player::Invalid));
    return result;
}

int score(int length, int free)
{
    int scoreTable[3][4] =
    {
        {1, 1, 1, 1}, {5, 10, 50, 200}, {10, 80, 320, 4000}
    };

    if(length >= 5) {
        return 4000;
    } 

    return scoreTable[free][length-1];
}

Coord Solution::pickupBestCoord(void)
{
    std::vector<Coord> coords;
    int maxWeight = 1;

    for(int i = 0; i < EDGE_LENGTH; i++) {
        for(int j = 0; j < EDGE_LENGTH; j++) {
            int w = weight[i][j];
            
            if(w >= maxWeight) {
                if(w > maxWeight) {
                    coords.clear();
                    maxWeight = w;
                }

                coords.push_back(Coord(i, j));
            }
        }
    }

    int size = coords.size();
    return coords[getRandomNumber(0, size-1)];
}
