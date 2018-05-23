#pragma once
#include<iostream>
#include "Board.h"


using namespace std;

class Player
{
	public:
		Player(){return;}
		char myChar='\0';
		
		virtual char getChar(){return myChar;}
		virtual void setChar(char c){myChar=c;}
		virtual const Coordinate play(const Board& board);

		virtual const string name()const{return "";}
		
};
