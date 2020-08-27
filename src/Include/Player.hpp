#pragma once

#include <iostream>


class Player 
{
private:
	int id;
	bool is_winner = false;

	int player_position_x;
	int player_position_y;

public:

	Player(int _id, int _pos_x, int _pos_y);
	~Player();
	
	int get_id() const;
	bool get_is_winner() const;
	int get_player_position_x() const;
	int get_player_position_y() const;

	//void set_id(int _id);
	void set_is_winner(bool _is_winner);
	void set_player_position_x(int _pos_x);
	void set_player_position_y(int _pos_y);

	void print_player_info() const;
};
