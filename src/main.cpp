

#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"

#define DEBUG_MAIN 0

int main(int argc, char * argv[]) 
{
	int dimension_x_i;
	int dimension_y_i;
	int amount_players_i;
	int board_values_i;

	std::cin >> dimension_x_i;
	std::cin >> dimension_y_i;
	std::cin >> amount_players_i;

	int total = dimension_y_i * dimension_x_i;

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

	board->populate_graph();

	// ----- Cira Novo Jogo movendo propriedade do ponteiro para board -----
	std::unique_ptr<Game> game(new Game(std::move(board)));

	// ----- Cria Players e preenche com dados -----
	int position_player_x_i;
	int position_player_y_i;

	std::vector<std::string> chars = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

	for (auto i = 0; i < amount_players_i; ++i) 
	{
		std::cin >> position_player_x_i;
		std::cin >> position_player_y_i; 

		std::unique_ptr<Player> new_player = std::make_unique<Player>(i, position_player_x_i, position_player_y_i, chars.at(i));
		game->add_player_to_game(std::move(new_player));
	}

	std::vector<int> random_entries = {5, 2, 3};

	for (auto i = 0; i < amount_players_i; ++i) 
	{
		game->get_game_player(i)->set_last_moviment(random_entries.at(i));
	}	
/*

	// ----- Loop principal -----
	while (true)
	{		
		for (auto i = 0; i < amount_players_i; ++i)
		{
			int dist[total];
			int pred[total];

			Player * current_player = game->get_game_player(i);

			int current_position_x = current_player->get_player_position_x();
			int current_position_y = current_player->get_player_position_y();

			int current_value_on_board = game->get_game_board()->get_value_in_position(current_position_x, current_position_y);
			
			std::pair<int, int> current_position = std::make_pair(current_position_x, current_position_y);

			std::cout << game->get_game_board()->BFS(current_position, dist, pred) << std::endl;

			current_player->set_last_moviment(current_value_on_board);

			std::cout << current_player->get_name() << " -> " << current_value_on_board << std::endl;		

			//current_player->set_player_position_x(new_position.first);
			//current_player->set_player_position_y(new_position.second);
			
			if (game->check_winner(i))
			{
				game->get_game_player(i)->print_player_info();
				break;
			}
			// checa se venceu
			
		}

		game->sort_players_queue();
		game->reset_players_id(amount_players_i);	
	}

	for (auto i = 0; i < amount_players_i; ++i) 
	{
		game->get_game_player(i)->print_player_info();
	}

*/

	int dist[total];
	int pred[total];

	Player * current_player = game->get_game_player(0);

	int current_position_x = current_player->get_player_position_x();
	int current_position_y = current_player->get_player_position_y();

	int current_value_on_board = game->get_game_board()->get_value_in_position(current_position_x, current_position_y);

	std::pair<int, int> current_position = std::make_pair(current_position_x, current_position_y);

	std::cout << game->get_game_board()->BFS(current_position, dist, pred) << std::endl;

	std::vector<int> path; 

	auto formula = [](int x, int y, int total_col){
		return ((total_col)*(x) + (y + 1) - 1);
	};

    int dest = formula(dimension_x_i - 1, dimension_y_i - 1, dimension_y_i);
    int crawl = dest;
    path.push_back(dest);

    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
  
    // distance from source is in distance array 
    std::cout << "Shortest path length is : "
         << dist[dest]; 
  
    // printing path from source to destination 
    std::cout << "\nPath is::\n"; 
    for (int i = path.size() - 1; i >= 0; i--) {
    	std::cout << path[i] << " "; 
    } 

	current_player->set_last_moviment(current_value_on_board);

	std::cout << current_player->get_name() << " -> " << current_value_on_board << std::endl;

#if DEBUG_MAIN

	std::cout << "-----" << std::endl;
	std::cout << "Printing Board" << std::endl;
	game->get_game_board()->print_board();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Players" << std::endl;
	for (auto i = 0; i < amount_players_i; ++i)
	{
		game->get_game_player(i)->print_player_info();
	}
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Graph" << std::endl;
	game->get_game_board()->print_graph();
	std::cout << "-----" << std::endl;
#endif


	return 0;
}