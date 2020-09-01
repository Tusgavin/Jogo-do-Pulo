#include "Player.hpp"

Player::Player(int _id, int _pos_x, int _pos_y, std::string _name)
	: id(_id), player_position_x(_pos_x), player_position_y(_pos_y) , name(_name)
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

bool Player::get_is_stuck() const
{
	return this->is_stuck;
}

int Player::get_last_moviment() const
{
	return this->last_moviment;
}

std::string Player::get_name() const
{
	return this->name;
}

void Player::set_name(std::string _name)
{
	this->name = _name;
}

void Player::set_id(int _id)
{
	this->id = _id;
}

void Player::set_is_winner(bool _is_winner)
{
	this->is_winner= _is_winner;
} 

void Player::set_player_position_x(int _pos_x)
{
	this->player_position_x = _pos_x;
}

void Player::set_player_position_y(int _pos_y)
{
	this->player_position_y = _pos_y;
}

void Player::set_is_stuck(bool _is_stuck)
{
	this->is_stuck = _is_stuck;
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

void Player::move_player(int _pos_x, int _pos_y)
{
	this->set_player_position_x(_pos_x);
	this->set_player_position_y(_pos_y);
}

bool Player::comp_by_last_moviment(const std::unique_ptr<Player>& player1, const std::unique_ptr<Player>& player2)
{
	return player1->get_last_moviment() < player2->get_last_moviment();
}