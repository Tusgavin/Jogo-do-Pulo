#include "Game.hpp"

Game::Game(std::unique_ptr<Board> _board)
	: game_board(std::move(_board))
{

}

Game::~Game()
{

}

void Game::add_player_to_game(std::unique_ptr<Player> _player)
{
	this->game_players.push_back(std::move(_player));
}

Board * Game::get_game_board() const
{
	return this->game_board.get();
}

Player * Game::get_game_player(int _id) const
{
	return this->game_players.at(_id).get();
}

void Game::sort_players_queue()
{
	std::sort(this->game_players.begin(), this->game_players.end(), Player::comp_by_last_moviment);
}

bool Game::check_winner(int _id)
{
	int pos_x = this->game_players.at(_id)->get_player_position_x();
	int pos_y = this->game_players.at(_id)->get_player_position_y();

	if ((pos_x == (this->game_board->get_dimension_x() - 1)) && (pos_y == (this->game_board->get_dimension_y() - 1)))
	{
		this->game_players.at(_id)->set_is_winner(true);
		return true;
	}
	else
	{
		return false;
	}
}

void Game::reset_players_id(int _amount_of_players)
{
	for (auto i = 0; i < _amount_of_players; ++i)
	{
		this->game_players.at(i)->set_id(i);
	}
}