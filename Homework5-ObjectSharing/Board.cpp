#include <iostream>
#include "Board.h"

using namespace std;

Board:: Board()
	//Dynamically allocate new memory and fill it with 0 initially
{
	moves=new int;
	score=new int;
	*moves=0;
	*score=0;
}

void Board::incrementmoves()
{
	*moves+=1;
}

void Board::incrementscore(int num)
{
	*score+=num;
}

void Board:: display()
{
	cout << "Total points: " << *score << endl;
	cout << "Total moves: " << *moves << endl;
}
bool Board:: BeyondLimit()
{//check if game is on 

	return (*score>=50 || *moves >=15);
	
}