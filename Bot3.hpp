#ifndef BOT3_HPP
# define BOT3_HPP

# include "Enemy.hpp"

class Bot3 : public Enemy
{
public:
	Bot3( void );
	Bot3( Bot3 const & src );
	~Bot3( void );
	
	Bot3 &						operator=( Bot3 const & rhs );
	void						changeTheCoords( void );
	void						spawn( void );

};

#endif
