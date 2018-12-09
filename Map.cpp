#include "Map.hpp"

Map::Map() {

	_height = 30;
	_width = 120;
	_mheight = 30;
	_mwidth = 40;
	_pause = 2;
	_score = 0;
}

Map::Map(const Map &rhs) {

	*this = rhs;
}

Map& Map::operator=(Map const &rhs) {

	_height = rhs._height;
	_width = rhs._width;
	return *this;
}

int Map::get_height() {

	return _height;
}

int Map::get_width() {

	return _width;
}

int Map::get_score() {

	return _score;
}

int Map::get_pause() {

	return _pause;
}

WINDOW* Map::get_map() {

	return _map;
}

WINDOW* Map::get_menu() {

	return _menu;
}

void Map::set_score(int k) {

	_score += k * 10;
}

void Map::set_height(int k) {

	_height = k;
}

void Map::set_width(int k) {

	_width = k;
}

void Map::set_pause(int k) {

	_pause = k;
}

Map::~Map() {}

void Map::rs_set_color() {

	init_pair(1, COLOR_WHITE, COLOR_BLACK);		//player
	init_pair(2, COLOR_WHITE, COLOR_BLACK);		// menu
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);	//bots
	init_pair(4, COLOR_BLUE, COLOR_BLACK);	//bots
	init_pair(5, COLOR_RED, COLOR_BLACK); 		//bots
}

void Map::init_map() {

	initscr();
	noecho();
	curs_set(0);
	start_color();
	rs_set_color();
	cbreak();
	keypad(stdscr, TRUE);
	_map = newwin(_height, _width, 0, 0);
	_menu = newwin(_mheight, _mwidth, 0, 121);
	refresh();
}