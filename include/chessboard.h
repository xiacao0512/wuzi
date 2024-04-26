// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once
#include "common.h"
#include "coord.h"
#include "misc.h"

struct Piece {
    Piece(void) 
    {
        player = Player::Invalid;
    }

    Piece(Player _player) 
    {
        player = _player;
    }

    Player player;  
};

struct Chessboard {
    Chessboard(void);

    Piece getPieceFromCoord(Coord coord)
    {
        if(isCoordInRange(coord) == true) {
            return container[coord.x][coord.y];
        }

        return Piece();
    }

    void setPieceToCoord(Coord coord, Piece piece)
    {
        if(isCoordInRange(coord) == true) {
            container[coord.x][coord.y] = piece;
        }

        return;
    }

    void paintChessboard(void);
    int checkGameover(Coord coord);
    void flagWinChesses(Coord coord, int direction);
    int checkGameover_singleDirection(int direction, Coord coord);
    int amountOfFreeExtremePoint(int direction, Coord coord);

    Piece container[EDGE_LENGTH][EDGE_LENGTH];

private:
    void paintPieces(void);
    bool isPiecesContact(Coord coord, Player baseMover);
};
