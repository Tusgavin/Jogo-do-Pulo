#include "Player.hpp"

#define DEBUG_PLAYER 0

Player::Player(int _id, int _pos_x, int _pos_y)
	: id = _id 
{
	this->pos = std:::make_pair(_pos_x, _pos_y);
}

Player::~Player() 
{

}

void Player::print_player_info() const
{
	std::cout << "Player ID: " << this->id << std::endl;
	std::cout << "Position: " << std::get<0>(this->pos) << ", " << std::get<1>(this->pos) << std::endl;
	std::cout << "Is wiiner: " << this->is_winner << std::endl;
}