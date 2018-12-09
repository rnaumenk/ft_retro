#include "Bot3.hpp"
#include "Map.hpp"

Bot3::Bot3( void ) : Enemy()
{
	this->_health = 5;
	this->_defaultHealth = 5;
	_x = -1;
	_y = -1;
}

Bot3::Bot3( Bot3 const & src )
{
	*this = src;
}

Bot3::~Bot3( void )
{
}

Bot3 &						Bot3::operator=( Bot3 const & rhs )
{
	this->_char = rhs.getChar();
	this->_health = rhs.getHealth();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

void						Bot3::changeTheCoords( void )
{
	if (_x == 1)
	{
		_x = 118;
		srand(clock());
		_y = rand() % 28 + 1;
	}
	int i[3] = {1, 0, -1};
	srand(clock());
	if (this->_y < 28 && this->_y > 1) {
		this->_y += i[rand() % 3];
	}
	else if (this->_y >= 28 && this->_y > 1) {
		this->_y += i[rand() % 2 + 1];
	}
	else if (this->_y < 28 && this->_y <= 1) {
		this->_y += i[rand() % 2];
	}
	int j[5] = {1, -1, -1, 0, -1};
	if (this->_x < 118 && this->_x > 1) {
		this->_x += j[rand() % 5];
	}
	else if (this->_x >= 118 && this->_x > 1) {
		this->_x += j[rand() % 2 + 3];
	}
	else if (this->_x < 118 && this->_x <= 1) {
		this->_x += j[rand() % 3];
	}
}

void						Bot3::spawn( void )
{
	_x = 118;
	srand(clock());
	_y = rand() % 28 + 1;
	_char = (char*)"#";
}
