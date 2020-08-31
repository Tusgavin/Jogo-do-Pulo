
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
			std::unique_ptr<Board> board(new Board(dimension_x_i, dimension_y_i));
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

	// ----- Loop principal -----
	while (true)
	{
		// get ordem players
		// para cada player
		for (auto i = 0; i < amount_players_i; ++i)
		{
			Player * current_player = game->get_game_player(i);

			//int current_position_x = current_player->get_player_position_x();
			//int current_position_y = current_player->get_player_position_y();

			//int current_value_on_board = game->game_board->get_value_in_position(current_position_x, current_position_y);
			// calcula BFS
			// anda com player
			int new_pos_x = 1;
			int new_pos_y = 1;
			current_player->set_player_position_x(new_pos_x);
			current_player->set_player_position_y(new_pos_y);
			// checa se venceu
		}
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
		game->get_game_player(i)->set_player_position_y(10);
	}
	std::cout << "-----" << std::endl;

#endif


	return 0;
}