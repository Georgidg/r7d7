#pragma once
#include<iostream>
#include "Board.h"


using namespace std;

class Player
{
	public:
		Player(){return;}
		char myChar='\0';
		virtual const Coordinate play(const Board& board);
		virtual void setChar(char c){myChar=c;}
		virtual const string name()const{return "";}
		virtual char getChar(){return myChar;}
		
};
