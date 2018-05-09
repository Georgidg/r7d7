#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(int i, int j) {
	this->i = i;
	this->j = j;
}

string IllegalCoordinateException::theCoordinate() const {
	return (to_string(i) + "," + to_string(j));
}