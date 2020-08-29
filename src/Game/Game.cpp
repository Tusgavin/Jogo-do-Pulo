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

void Game::print_board() const
{
	this->game_board->print_board();
}

void Game::print_players() const
{
	for (auto it = this->game_players.begin(); it != this->game_players.end(); ++it)
	{
		(*it)->print_player_info();
	}
}