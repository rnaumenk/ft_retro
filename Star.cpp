#include "Star.hpp"

int								Star::_randhelper = 1;

Star::Star( void )
{
	int		i[13] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	srand(time(0) * clock() * _randhelper * _randhelper);
	_randhelper++;
	_visibility = i[rand() % 13];
}

Star::Star( Star const & src )
{
	*this = src;
}

Star::~Star( void )
{
}

Star &							Star::operator=( Star const & rhs )
{
	this->_visibility = rhs.getVisibility();
	return (*this);
}

int								Star::getVisibility( void ) const
{
	return (this->_visibility);
}
