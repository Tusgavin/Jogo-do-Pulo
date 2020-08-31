#pragma once

#include <iostream>


class Player 
{
private:
	int id;

	bool is_winner = false;
	bool is_stuck = false;

	int player_position_x;
	int player_position_y;

	int last_moviment = -1;

	Tree possible__moviments;

public:

	Player(int _id, int _pos_x, int _pos_y);
	~Player();
	
	int get_id() const;
	bool get_is_winner() const;
	int get_player_position_x() const;
	int get_player_position_y() const;
	bool get_is_stuck() const;
	int get_last_moviment() const;

	void set_id(int _id);
	void set_is_winner(bool _is_winner);
	void set_player_position_x(int _pos_x);
	void set_player_position_y(int _pos_y);
	void set_is_stuck(bool _is_stuck);
	void set_last_moviment(int _mov);

	void print_player_info() const;

	void move_player(int _pos_x, int _pos_y);
};