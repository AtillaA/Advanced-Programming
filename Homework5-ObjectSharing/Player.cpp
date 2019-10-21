#include "Board.h"
#include <iostream>
#include <random>
#include "Player.h"
#include <string>

using namespace std;

Player:: Player(Board & common, string s)
	:onlyboard(common),name(s)
{//Dynamically allocate new memory from heap and initialize them to 0
	collected=new int;
	moved=new int;
	*collected=0;
	*moved=0;
}

void Player:: display()
{
	cout << "Player name:" << name << endl;
	cout << "Points:" << *collected << endl;
	cout << "Number Of Moves:" << *moved << endl;
}
bool Player:: rollDice()
{
	
	bool check=true;
	if(onlyboard.BeyondLimit())
	{
		check=false;
		
	}
	else
	{
		//create a random generator
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 6);//returns integers btw (1,6)
		int rannum=dis(gen);//dice value
		cout << "Dice: " << rannum << endl;//print dice value
		//update privates of two classes
		*collected +=rannum;
		onlyboard.incrementscore(rannum);
		*moved+=1;
		onlyboard.incrementmoves();
		//display player info
		display();
		//check if next round will be played or empty
		if(onlyboard.BeyondLimit())
			check=false;
	}
	return check;
}
double Player:: calculateScore()
{
	//double division to calculate score of player
	double rtrvalue=*collected;
	rtrvalue=rtrvalue/(*moved);
	return rtrvalue;
}
