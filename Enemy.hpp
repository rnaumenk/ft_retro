#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
public:
	Enemy( void );
	Enemy( Enemy const & src );
	~Enemy( void );
	
	Enemy &						operator=( Enemy const & rhs );
	char *						getChar( void ) const;
	int							getHealth( void ) const;
	int							getX( void ) const;
	int							getY( void ) const;
	void						setX( int const x );
	void						setY( int const y );
	int							kill( void );
	void						kill( int );
	virtual void				changeTheCoords( void ) = 0;

protected:
	char *						_char;
	int							_health;
	int 						_defaultHealth;
	int							_x;
	int							_y;

};

#endif
