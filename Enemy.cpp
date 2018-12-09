#include "Enemy.hpp"

Enemy::Enemy( void ) : _health(1), _defaultHealth(1)
{
}

Enemy::Enemy( Enemy const & src )
{
	*this = src;
}

Enemy::~Enemy() {}

Enemy &								Enemy::operator=( Enemy const & rhs )
{
	this->_char = rhs.getChar();
	this->_health = rhs.getHealth();
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

char *						Enemy::getChar( void ) const
{
	return (this->_char);
}

int							Enemy::getHealth( void ) const
{
	return (this->_health);
}

int							Enemy::getX( void ) const
{
	return (this->_x);
}

int							Enemy::getY( void ) const
{
	return (this->_y);
}

void						Enemy::setX( int const x )
{
	this->_x = x;
}

void						Enemy::setY( int const y )
{
	this->_y = y;
}

int							Enemy::kill( void )
{
	if (--_health == 0) {
		_x = 118;
		srand(clock());
		_y = rand() % 28 + 1;
		this->_health = this->_defaultHealth;
		return (this->_defaultHealth);
	}
	return (0);
}

void						Enemy::kill( int )
{
		_x = 118;
		srand(clock());
		_y = rand() % 28 + 1;
		this->_health = this->_defaultHealth;
}