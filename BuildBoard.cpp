#include "BuildBoard.h"



BuildBoard::BuildBoard() {
	this->set('.');
}
BuildBoard::BuildBoard(char c) {
	this->set(c);
}
BuildBoard& BuildBoard::operator=(char c) {
	if(this->get()=='.'||c=='.')
	this->set(c);
	else throw IllegalCharException(c);
	return *this;
}
void BuildBoard::set(char c) {
	if (c == 'X' || c == 'O' || c == '.') {
		this->c = c;
	}
	else throw IllegalCharException(c);
}
const char BuildBoard::get()const {
	return this->c;
}
ostream & operator<<(ostream & os, const BuildBoard & s) {
	os << s.get();
	return os;
}

BuildBoard::operator char() const {
	return c;
}
bool operator==(BuildBoard& s, char c)
{
	if (s.get() == c) return true;
	return false;
}


