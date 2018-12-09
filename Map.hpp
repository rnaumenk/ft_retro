#ifndef MAP_HPP
#define MAP_HPP

#include <curses.h>

class Map {

private:

	int			_height;
	int			_width;
	int			_mheight;
	int			_mwidth;
	int			_pause;
	int			_score;
	WINDOW		*_menu;
	WINDOW		*_map;

public:

	Map( void );
	Map( const Map & rhs );
	~Map();

	Map &operator=( Map const & rhs );
	int				get_pause();
	int				get_height();
	int				get_width();
	int				get_score();
	WINDOW*			get_map();
	WINDOW*			get_menu();

	void	set_score(int k);
	void	set_pause(int k);
	void	set_height(int k);
	void	set_width(int k);

	void	init_map();
	void	rs_set_color();

};

#endif
