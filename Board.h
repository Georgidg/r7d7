

#ifndef UNTITLED1_BOARD_H
#define UNTITLED1_BOARD_H

#include <iostream>
#include <string>
#include "Coordinate.h"
#include "square.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;
class Board{

	square** board;
	int _size;

public:
	Board();
	Board(int);
	Board(const Board&);
	~Board();
	square& operator [](Coordinate)const;
	friend ostream& operator <<(ostream&, const Board&);
	Board& operator =(char);
	Board& operator =(Board&);
	int size()const{return _size;}
	int size(){return _size;}
};

#endif //UNTITLED1_BOARD_H
