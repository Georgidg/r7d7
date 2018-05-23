#include "Player.h"

class TicTacToe
{

	public:
		
		Player* theWinner;
		Board b;
		int numOfPlays;

		TicTacToe(int);
		void play(Player&,Player&);
		Board board()const{return b;}
    	Player& winner()const;
	private:
		bool done();
};
