// Wuzi chess game 
// program by ET-16G, Apr. 22 2024

#include <conio.h>
#include "../include/chessboard.h"
#include "../include/common.h"
#include "../include/console.h"
#include "../include/misc.h"
#include "../include/ui.h"

#define POLARITY_POSITIVE       1
#define POLARITY_NEGATIVE       2

Coord moveCoordInOneStep(Coord coord, int direction, int polarity);

int Chessboard::checkGameover(Coord coord)
{
    for(int direction = HORIZONTAL; direction <= RIGHT_OBLIQUE; direction++) {
        if(checkGameover_singleDirection(direction, coord) >= 5) {
            return direction;
        }
    }

    return NO_WIN;
}

void Chessboard::flagWinChesses(Coord coord, int direction)
{
    Player baseMover = getPieceFromCoord(coord).player;
    setPieceToCoord(coord, Piece(Player::Winner));

    int remains = 4;
    int polarity = POLARITY_POSITIVE;
    Coord stCoord = moveCoordInOneStep(coord, direction, polarity);

    while(remains > 0) {
        if(isPiecesContact(stCoord, baseMover) == false) {
            polarity = POLARITY_NEGATIVE;
            stCoord = moveCoordInOneStep(coord, direction, polarity);
        } else {
            setPieceToCoord(stCoord, Piece(Player::Winner));
            remains--;

            stCoord = moveCoordInOneStep(stCoord, direction, polarity);
        }
    }

    return;
}

int Chessboard::checkGameover_singleDirection(int direction, Coord coord)
{
    int score = 1;
    int polarity = POLARITY_POSITIVE;
    Player baseMover = container[coord.x][coord.y].player;

    while(polarity <= POLARITY_NEGATIVE) {
        Coord stCoord = coord;

        while(isPiecesContact(stCoord, baseMover) == true) {
            score++;
            stCoord = moveCoordInOneStep(stCoord, direction, polarity);
        }

        polarity++;
        score--;
    }

    return score;
}


int Chessboard::amountOfFreeExtremePoint(int direction, Coord coord)
{
    int amount = 0;
    int polarity = POLARITY_POSITIVE;
    Player baseMover = container[coord.x][coord.y].player;

    while(polarity <= POLARITY_NEGATIVE) {
        Coord stCoord = coord;

        while(isPiecesContact(stCoord, baseMover) == true) {
            stCoord = moveCoordInOneStep(stCoord, direction, polarity);
        }

        if(isCoordInRange(stCoord) == true) {
            if(getPieceFromCoord(stCoord).player == Player::Invalid) {
                amount++;
            }
        }
        
        polarity++;
    }

    return amount;
}

Coord moveCoordInOneStep(Coord coord, int direction, int polarity)
{
    int polarityMarker = 0;

    if(polarity == POLARITY_POSITIVE) {
        polarityMarker = 1;
    } else if(polarity == POLARITY_NEGATIVE) {
        polarityMarker = -1;
    }

    Coord stCoord = coord;
    switch(direction) {
        case HORIZONTAL:
            stCoord.x += polarityMarker;
            break;
        case VERTICAL:
            stCoord.y += polarityMarker;
            break;
        case LEFT_OBLIQUE:
            stCoord.x += polarityMarker;
            stCoord.y += polarityMarker;
            break;
        case RIGHT_OBLIQUE:
            stCoord.x += polarityMarker;
            stCoord.y -= polarityMarker;
            break;
    }

    return stCoord;
}

bool Chessboard::isPiecesContact(Coord coord, Player baseMover)
{
    if(isCoordInRange(coord) == true && getPieceFromCoord(coord).player == baseMover) {
        return true;
    } else {
        return false;
    }
}
