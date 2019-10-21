#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
using namespace std;

class Board
{
public:
	Board();//constructor
	void incrementmoves(); //add +1 moves pointer
	void incrementscore(int num); //add +num score pointer
	void display(); //display board info
	bool BeyondLimit();//returns true if game should be over

private:
	int* score;
	int* moves;
};


#endif