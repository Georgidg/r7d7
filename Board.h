#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Coordinate.h"
#include "BuildBoard.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;
class Board {

	BuildBoard** buildBoard;
	int _size;

public:
	Board();
	Board(int);
	Board(const Board&);
	~Board();
	BuildBoard& operator [](vector<int> vec);
	friend ostream& operator <<(ostream&, const Board&);
	Board& operator =(char);
	Board& operator =(Board&);
};
