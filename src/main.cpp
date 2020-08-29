
#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"

#define DEBUG_MAIN 1

int main(int argc, char * argv[]) 
{
	int dimension_x_i;
	int dimension_y_i;
	int amount_players_i;
	int board_values_i;

	std::cin >> dimension_x_i;
	std::cin >> dimension_y_i;
	std::cin >> amount_players_i;

	// ----- Cria Tabuleiro e Novo Jogo -----
	std::unique_ptr<Board> board(new Board(dimension_x_i, dimension_y_i));

	// ----- Preenche valores do Tabuleiro -----
	for (auto i = 0; i < dimension_x_i; ++i)
	{
		for (auto j = 0; j < dimension_y_i; ++j)
		{
			std::cin >> board_values_i;
			board->set_value_to_board(i, j, board_values_i);
		}
	}

	// ----- Cira Novo Jogo movendo propriedade do ponteiro para board -----
	std::unique_ptr<Game> game(new Game(std::move(board)));

	// ----- Cria Players e preenche com dados -----
	int position_player_x_i;
	int position_player_y_i;

	for (auto i = 0; i < amount_players_i; ++i) 
	{
		std::cin >> position_player_x_i;
		std::cin >> position_player_y_i; 

		std::unique_ptr<Player> new_player = std::make_unique<Player>(i, position_player_x_i, position_player_y_i);
		game->add_player_to_game(std::move(new_player));
	}


#if DEBUG_MAIN

	std::cout << "-----" << std::endl;
	std::cout << "Printing Board" << std::endl;
	game->print_board();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Players" << std::endl;
	for (auto i = 0; i < amount_players_i; ++i)
	{
		game->get_game_player(i)->print_player_info();
	}
	std::cout << "-----" << std::endl;

#endif

	return 0;
}