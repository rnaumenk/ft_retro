#ifndef BOT1_HPP
# define BOT1_HPP

# include "Enemy.hpp"

class Bot1 : public Enemy
{
public:
	Bot1( void );
	Bot1( Bot1 const & src );
	~Bot1( void );
	
	Bot1 &						operator=( Bot1 const & rhs );
	void						changeTheCoords( void );
	void						spawn( void );

};

#endif
