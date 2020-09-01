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