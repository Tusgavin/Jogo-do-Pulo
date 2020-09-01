#pragma once

#include <iostream>
#include <memory>
#include <queue>

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

	Board * get_game_board() const;
	Player * get_game_player(int _id) const;

};