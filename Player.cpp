#include "Player.hpp"


Player::Player() {

	_life = 3;
	_x = 5;
	_y =5;
}

Player::Player(const Player &rhs) {

	*this = rhs;
}

Player& Player::operator=(Player const &rhs) {

	_life = rhs._life;
	return *this;
}

Player::~Player() {}

int Player::get_x() {

	return _x;
}

int Player::get_y() {

	return _y;
}

int Player::get_life() {

	return _life;
}

void Player::set_x(int k) {

	_x = k;
}

void Player::set_y(int k) {

	_y = k;
}

void Player::set_life(int k) {

	_life = k;
}