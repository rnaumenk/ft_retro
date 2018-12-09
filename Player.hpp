#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {

private:

	int			_life;
	int			_x;
	int			_y;

public:

	Player( void );
	Player( const Player & rhs );
	~Player();

	Player &operator=( Player const & rhs );
	int				get_x();
	int				get_y();
	int				get_life();
	void			set_life(int k);
	void			set_x(int k);
	void			set_y(int k);

};

#endif
