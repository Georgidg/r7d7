#include "Player.h"

class Pleywr: public Player
{
public:
	const string name() const override{return "THe winner is the one that soppus to be";}
	const Coordinate play(const Board& board) override;
};
