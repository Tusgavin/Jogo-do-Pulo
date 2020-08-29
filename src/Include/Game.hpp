#pragma once

#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"

class Game
{
private:

	std::unique_ptr<Board> game_board;
	std::vector<std::unique_ptr<Player>> game_players;

public:

	Game(std::unique_ptr<Board> _board);
	~Game();

	void add_player_to_game(std::unique_ptr<Player> _player);

	void print_board() const;
	void print_players() const;
};