#include <iostream>

#include "Board.hpp"
#include "Player.hpp"

#define DEBUG_MAIN 0

int main(int argc, char * argv[]) 
{
	// ----- Tratamento da entrada -----
	
	int dimension_x_i;
	int dimension_y_i;
	int amount_players_i;
	int board_values_i;

	std::cin >> dimension_x_i;
	std::cin >> dimension_y_i;
	std::cin >> amount_players_i;

	// ----- Cria Tabuleiro -----
	Board * board = new Board(dimension_x_i, dimension_y_i);

	// ----- Preenche valores -----
	for (auto i = 0; i < dimension_x_i; ++i)
	{
		for (auto j = 0; j < dimension_y_i; ++j)
		{
			std::cin >> board_values_i;
			board->add_value_to_board(i, j, board_values_i);
		}
	}

	// ----- Cria Players e preenche com dados -----


#if DEBUG_MAIN

	std::cout << "-----" << std::endl;
	std::cout << "Printing Board" << std::endl;
	board->print_board();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Player" << std::endl;

	std::cout << "-----" << std::endl;

#endif



	return 0;
}