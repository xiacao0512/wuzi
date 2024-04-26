// Wuzi chess game 
// program by ET-16G, Apr. 5 2024

#pragma once

#define CONSOLE_WIDTH   80
#define CONSOLE_HEIGHT  24
#define EDGE_LENGTH     18

#define CHESSBOARD_X    2
#define CHESSBOARD_Y    2
#define SPILT_LINE_X    26
#define WORD_X          29

#define QUIT_BOX_X_UL   28
#define QUIT_BOX_Y_UL   13
#define QUIT_BOX_X_LR   40
#define QUIT_BOX_Y_LR   16

enum Player {
    Invalid = 0,
    P1 = 1,
    P2 = 2,
    Winner = 3
};

#define MODE_1PLAYER    0
#define MODE_2PLAYERS   1
#define MODE_QUIT       2

#define ARROW_UP    72
#define ARROW_DOWN  80
#define ARROW_LEFT  75
#define ARROW_RIGHT 77
#define ENTER       13
#define ESC         27

#define BLANK           219
#define UPPER_LEFT      201
#define UPPER_RIGHT     187
#define LOWER_LEFT      200
#define LOWER_RIGHT     188
#define STICK_HORI      205
#define STICK_VERT      186

#define NO_WIN          0
#define HORIZONTAL      1
#define VERTICAL        2
#define LEFT_OBLIQUE    3
#define RIGHT_OBLIQUE   4

#define BLACK_BACK_WHITE_CHAR   0x07
#define WHITE_BACK_BLACK_CHAR   0x70
#define BLACK_BACK_BLACK_CHAR   0x00
#define BLACK_BACK_BLUE_CHAR    0x09
#define BLACK_BACK_GREEN_CHAR   0x0a
#define BLACK_BACK_RED_CHAR     0x0c
