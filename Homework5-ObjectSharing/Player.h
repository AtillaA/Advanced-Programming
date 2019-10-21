#ifndef _PLAYER_H
#define _PLAYER_H

#include "Board.h"
#include <iostream>
#include <random>
#include <string>

using namespace std;
class Player
{
public:
	Player(Board & common, string s);//constructor
	bool rollDice();//main rolling func
	double calculateScore();//only a double division
	void display();//displaying player info after each turn
private:
	string name;
	Board & onlyboard;
	int *collected;
	int *moved;
};

#endif