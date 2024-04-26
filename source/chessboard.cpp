// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#include "..\include\chessboard.h"
#include "..\include\console.h"
#include "..\include\common.h"
#include "..\include\misc.h"
#include "..\include\ui.h"

int pieceColor(Piece piece);
char pieceChar(Piece piece);

Chessboard::Chessboard(void)
{
    for(int i = 0; i < EDGE_LENGTH; i++) {
        for(int j = 0; j < EDGE_LENGTH; j++) {
            setPieceToCoord(Coord(i, j), Piece());
        }
    }
}

void Chessboard::paintChessboard(void)
{
    paintBox(Rect(Coord(CHESSBOARD_X-1, CHESSBOARD_Y), Coord(CHESSBOARD_X+EDGE_LENGTH+1, CHESSBOARD_Y+EDGE_LENGTH+1)));    
    paintPieces();

    return;
}

void Chessboard::paintPieces(void)
{
    for(int i = 0; i < EDGE_LENGTH; i++) {
        for(int j = 0; j < EDGE_LENGTH; j++) {
            putchar_ex(Coord(CHESSBOARD_X+1+j, CHESSBOARD_Y+1+i), pieceColor(container[j][i]), pieceChar(container[j][i]));
        }
    }

    return;
}


int pieceColor(Piece piece)
{
    switch(piece.player) {
        case Player::Invalid:
            return BLACK_BACK_WHITE_CHAR;
        case Player::P1:
            return BLACK_BACK_BLUE_CHAR;
        case Player::P2:
            return BLACK_BACK_GREEN_CHAR;
        case Player::Winner:
            return BLACK_BACK_RED_CHAR;
    }
    return BLACK_BACK_BLACK_CHAR;
}

char pieceChar(Piece piece)
{
    if(piece.player == Player::Invalid) {
        return '.';
    } else {
        return 'x';
    }
}
