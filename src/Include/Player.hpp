#pragma once

#include <iostream>
#include <memory>

class Player 
{
private:
	int id;

	bool is_winner = false;

	int player_position_x;
	int player_position_y;

	int last_moviment = 99999;
	int first_moviment = 99999;

	std::string name;

	int path_l = 99999;

public:

	Player(int _id, int _pos_x, int _pos_y, std::string _name);
	~Player();
	
	bool get_is_winner() const;
	std::string get_name() const;

	int get_player_position_x() const;
	int get_player_position_y() const;

	int get_first_moviment() const;
	int get_last_moviment() const;
	int get_path_l() const;

	void set_first_moviment(int _first_moviment);
	void set_last_moviment(int _mov);
	void set_path_l(int _path_l);

	void set_is_winner(bool _is_winner);

	void print_player_info() const;
};