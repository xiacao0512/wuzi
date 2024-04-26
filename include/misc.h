// Wuzi chess game 
// program by ET-16G, Apr. 8 2024

void gotoXY_Complex(Coord sCoord);
bool isHorizonalArrow(int c);
bool isVerticalArrow(int c);
bool isCoordInRange(Coord coord);

void paintBlackRect(Rect rect);
void paintHorizontalStick(int start_x, int y, int length);
void paintVerticalStick(int x, int start_y, int length);
void paintBox(Rect rect);

int getRandomNumber(int max, int min);
