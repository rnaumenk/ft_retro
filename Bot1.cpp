#include "Bot1.hpp"

Bot1::Bot1( void ) : Enemy()
{
	_x = -1;
	_y = -1;
}

Bot1::Bot1( Bot1 const & src )
{
	*this = src;
}

Bot1::~Bot1( void )
{
}

Bot1 &						Bot1::operator=( Bot1 const & rhs )
{
	this->_char = rhs.getChar();
	this->_health = rhs.getHealth();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

void						Bot1::changeTheCoords( void )
{
	if (_x == 1)
	{
		_x = 118;
		srand(clock());
		_y = rand() % 28 + 1;
	}
	this->_x--;
}

void						Bot1::spawn( void )

{
	_x = 118;
	srand(clock());
	_y = rand() % 28 + 1;
	_char = (char*)"o";
}