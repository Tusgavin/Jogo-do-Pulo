#include "Player.hpp"

Player::Player(int _id, int _pos_x, int _pos_y, std::string _name)
	: id(_id), player_position_x(_pos_x), player_position_y(_pos_y) , name(_name)
{

}

Player::~Player() 
{

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


int Player::get_last_moviment() const
{
	return this->last_moviment;
}

std::string Player::get_name() const
{
	return this->name;
}

int Player::get_path_l() const
{
	return this->path_l;
}

int Player::get_first_moviment() const
{
	return this->first_moviment;
}

void Player::set_first_moviment(int _first_moviment)
{
	this->first_moviment = _first_moviment;
}

void Player::set_path_l(int _path_l)
{
	this->path_l = _path_l;
}

void Player::set_is_winner(bool _is_winner)
{
	this->is_winner= _is_winner;
} 

void Player::set_last_moviment(int _mov)
{
	this->last_moviment = _mov;
}

void Player::print_player_info() const
{
	std::cout << "Player ID: " << this->id << std::endl;
	std::cout << "Position X: " << this->player_position_x << ", Position Y: " << this->player_position_y << std::endl;
	std::cout << "Is winner: " << this->is_winner << std::endl;
}
