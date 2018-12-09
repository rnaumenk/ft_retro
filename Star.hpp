#ifndef STAR_HPP
# define STAR_HPP

# include <time.h>
# include <iostream>

class Star
{
public:
	Star( void );
	Star( Star const & src );
	~Star( void );

	Star &				operator=( Star const & rhs );
	int					getVisibility( void ) const;

private:
	int					_visibility;
	static int			_randhelper;
};

#endif
