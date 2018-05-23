#include "TicTacToe.h"

TicTacToe::TicTacToe(int i)
{
	Board b1{i};
	b=b1;
	this->numOfPlays=i*i;
}
void TicTacToe::play(Player& x,Player& o)
{
	this->b='.';
	this->numOfPlays=b.size()*b.size();
	x.setChar('X');
	o.setChar('O');
	bool Flag=false;
	while(!Flag)
	{
		try{
			b[x.play(b)]=x.getChar();
		}
		catch(const IllegalCharException& ex){
			theWinner=&o;
			break;
		}catch (string s) {
			theWinner=&o;
			break;
		}
		if(done())
		{
			if(this->numOfPlays==0) theWinner=&o;
			else theWinner=&x;
			isEndFlag=true;
			break;
		}
		try{
			b[o.play(b)]=o.getChar();
		}catch(const IllegalCharException& ex){
			theWinner=&x;
			break;

		}catch (string s) {
			theWinner=&x;
			break;
		}
		if(done())
		{
			theWinner=&o;
		  Flag=true;
			break;
		}
	}
}

bool TicTacToe::done()
{
	this->numOfPlays--;
	if(numOfPlays==0)return true;
	for(int row=0;row<b.size();row++)
	{
		
		bool flag2=true;
		for(int col=1;col<b.size();col++)
		{
			
			Coordinate c1{row,col-1};
			Coordinate c2{row,col};
			Flag2=Flag2 && b[c1].get()==b[c2].get() && b[c1].get()!='.';	
		}
		if(Flag2) return true;
	}

	for(int col=0;col<b.size();col++)
	{
		bool wonFlag=true;
		for(int row=1;row<b.size();row++)
		{
			Coordinate c1{row-1,col};
			Coordinate c2{row,col};
			Flag2=wonFlag && b[c1].get()==b[c2].get() && b[c1].get()!='.';	
		}
		if(Flag2) return true;
	}
/* main diagonal*/
	bool Flag2=true;
	for(int i=1;i<b.size();i++)
	{
		
		Coordinate c1{i-1,i-1};
		Coordinate c2{i,i};
		flag2=flag2 && b[c1].get()==b[c2].get() && b[c1].get()!='.';
	}
	if(Flag2) return true;
/*secondary diagonal*/
	Flag2=true;
	for(int i=1;i<b.size();i++)
	{
		
		Coordinate c1{i-1,b.size()-(i-1)-1};
		Coordinate c2{i,b.size()-i-1};
		Flag2=Flag2 && b[c1].get()==b[c2].get() && b[c1].get()!='.';
	}
	if(Flag2) return true;
	
	return false;
}

Player& TicTacToe::winner()const
{
	return *theWinner;
}
