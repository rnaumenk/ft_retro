#ifndef BOT2_HPP
# define BOT2_HPP

# include "Enemy.hpp"
#include <iostream>

class Bot2 : public Enemy
{
public:
	Bot2( void );
	Bot2( Bot2 const & src );
	~Bot2( void );
	
	Bot2 &						operator=( Bot2 const & rhs );
	void						changeTheCoords( void );
	void						spawn( void );

};

#endif
