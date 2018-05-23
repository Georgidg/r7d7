
#include "Board.h"
Board::Board(int _size) {
	this->_size =_size;
	this->buildBoard = new BuildBoard*[_size];
	for (int i=0;i<_size;i++) {
		buildBoard[i] = new BuildBoard[_size];
	}
}
ostream & operator<<(ostream & os,const Board & board) {
	for(int i = 0;i<board._size;i++){
		for(int j = 0;j<board._size;j++){
			os<< board.buildBoard[i][j];
		}
		os<<"\n";
	}
	return os;
}

Board& Board::operator=(char c) {
	if(c=='X'||c=='O'||c=='.') {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				this->buildBoard[i][j] = c;
			}
		}
	}
	else throw IllegalCharException(c);
	return *this;
}
Board& Board::operator=(Board & board) {
	this->~Board();
	this->_size = board._size;
	this->buildBoard = new BuildBoard*[board._size];
	for (int i=0;i<board._size;i++) {
		buildBoard[i] = new BuildBoard[board._size];
	}
	for (int i = 0; i < board._size; i++) {
		for (int j = 0; j < board.s_ize; j++) {
			this->buildBoard[i][j].set(board.buildBoard[i][j].get());
		}
	}
	return *this;
}
BuildBoard& Board::operator[](vector<int> vec){
	if(vec[0]>=0 && vec[1]>=0 && vec[0]<_size && vec[1]<_size){
		return this->buildBoard[vec[0]][vec[1]];
	}
	else throw IllegalCoordinateException(vec[0],vec[1]);

}

Board::Board()
{
	this->_size=0;
	this->buildBoard =NULL;
}

Board::Board(const Board& board)
{
	this->_size= board._size;
	this->buildBoard = new BuildBoard*[_size];
	for (int i=0;i<_size;i++) {
		buildBoard[i] = new BuildBoard[_size];
	}
	for (int i = 0; i < board._size; i++) {
		for (int j = 0; j < board._size; j++) {
			this->buildBoard[i][j].set(board.buildBoard[i][j].get());
		}
	}
}

Board::~Board(){
    for (int i = 0; i <_size ; ++i) {
            delete[] buildBoard[i];
    }delete[] buildBoard;
}
