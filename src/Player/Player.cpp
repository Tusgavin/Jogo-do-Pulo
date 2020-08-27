#include "Player.hpp"

#define DEBUG_PLAYER 0

Player::Player(int _id, int _pos_x, int _pos_y)
	: id(_id), player_position_x(_pos_x), player_position_y(_pos_y) 
{

}

Player::~Player() 
{

}

int Player::get_id() const
{
	return this->id;
}

bool Player::get_is_winner() const
{
	return this->is_winner;
}

int Player::get_player_position_x() const
{
	return this->player_position_x;
}

int Player::get_player_position_y() const
{
	return this->player_position_y;
}

void Player::set_is_winner(bool _is_winner)
{
	this->is_winner = _is_winner;
} 

void Player::set_player_position_x(int _pos_x)
{
	this->player_position_x = _pos_x;
}

void Player::set_player_position_y(int _pos_y)
{
	this->player_position_y = _pos_y;
}

void Player::print_player_info() const
{
	std::cout << "Player ID: " << this->id << std::endl;
	std::cout << "Position X: " << this->player_position_x << ", Position Y: " << this->player_position_y << std::endl;
	std::cout << "Is wiiner: " << this->is_winner << std::endl;
}