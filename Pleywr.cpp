#include "pleywr.h"


const Coordinate Champion::play(const Board& board)
{
	int n=board.size()-1;
	Coordinate c{n,0};
	if(board[c].get()=='.') return c;
	for(int i=0;i<=n;i++)
	{
		Coordinate c{i,n-i};
		if(board[c].get()=='.') return c;
	}
	Coordinate c1{0,0};
	return c1;
}
