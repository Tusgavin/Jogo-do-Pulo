#pragma once

#include <iostream>
#include <pair>

template<typename T>
using Position = std::pair<T, T>;

class Player 
{
private:
	int id;
	bool is_winner = false;

	Position pos;

public:

	Player(int _id, int _pos_x, int _pos_y);
	~Player();
	

	void print_player_info() const;
};
