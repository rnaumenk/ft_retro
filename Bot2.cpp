#include "Bot2.hpp"
#include "Map.hpp"

Bot2::Bot2( void ) : Enemy()
{
	this->_health = 3;
	this->_defaultHealth = 3;
	_x = -1;
	_y = -1;
}

Bot2::Bot2( Bot2 const & src )
{
	*this = src;
}

Bot2::~Bot2( void )
{
}

Bot2 &						Bot2::operator=( Bot2 const & rhs )
{
	this->_char = rhs.getChar();
	this->_health = rhs.getHealth();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

void						Bot2::changeTheCoords( void )
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
	this->_x--;
}

void						Bot2::spawn( void )
{
	_x = 118;
	srand(clock());
	_y = rand() % 28 + 1;
	_char = (char*)"x";
}
