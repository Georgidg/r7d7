
#include "Board.h"
Board::Board(int size) {
	this->size =size;
	this->buildBoard = new BuildBoard*[size];
	for (int i=0;i<size;i++) {
		buildBoard[i] = new BuildBoard[size];
	}
}
ostream & operator<<(ostream & os,const Board & board) {
	for(int i = 0;i<board.size;i++){
		for(int j = 0;j<board.size;j++){
			os<< board.buildBoard[i][j];
		}
		os<<"\n";
	}
	return os;
}

Board& Board::operator=(char c) {
	if(c=='X'||c=='O'||c=='.') {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				this->buildBoard[i][j] = c;
			}
		}
	}
	else throw IllegalCharException(c);
	return *this;
}
Board& Board::operator=(Board & board) {
	this->~Board();
	this->size = board.size;
	this->buildBoard = new BuildBoard*[board.size];
	for (int i=0;i<board.size;i++) {
		buildBoard[i] = new BuildBoard[board.size];
	}
	for (int i = 0; i < board.size; i++) {
		for (int j = 0; j < board.size; j++) {
			this->buildBoard[i][j].set(board.buildBoard[i][j].get());
		}
	}
	return *this;
}
BuildBoard& Board::operator[](vector<int> vec){
	if(vec[0]>=0 && vec[1]>=0 && vec[0]<size && vec[1]<size){
		return this->buildBoard[vec[0]][vec[1]];
	}
	else throw IllegalCoordinateException(vec[0],vec[1]);

}

Board::Board()
{
	this->size=0;
	this->buildBoard =NULL;
}

Board::Board(const Board& board)
{
	this->size= board.size;
	this->buildBoard = new BuildBoard*[size];
	for (int i=0;i<size;i++) {
		buildBoard[i] = new BuildBoard[size];
	}
	for (int i = 0; i < board.size; i++) {
		for (int j = 0; j < board.size; j++) {
			this->buildBoard[i][j].set(board.buildBoard[i][j].get());
		}
	}
}

Board::~Board(){
    for (int i = 0; i <size ; ++i) {
            delete[] buildBoard[i];
    }delete[] buildBoard;
}
