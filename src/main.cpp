

#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"


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

	std::vector<std::string> chars = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};

	for (auto i = 0; i < amount_players_i; ++i) 
	{
		std::cin >> position_player_x_i;
		std::cin >> position_player_y_i; 

		std::unique_ptr<Player> new_player = std::make_unique<Player>(i, position_player_x_i, position_player_y_i, chars.at(i));
		game->add_player_to_game(std::move(new_player));
	}

	// ----- Loop principal -----
	int winner_count = 0;
	int loser_count = 0;
	int smallest_path = 99999;

	for (auto i = 0; i < amount_players_i; ++i)
	{
		int dist[total];
		int pred[total];

		Player * current_player = game->get_game_player(i);

		int current_position_x = current_player->get_player_position_x();
		int current_position_y = current_player->get_player_position_y();
		
		std::pair<int, int> current_position = std::make_pair(current_position_x, current_position_y);

		bool success_BFS = game->get_game_board()->BFS(current_position, dist, pred);

		// ----- Se algum player chega ao final -----
		if (success_BFS)
		{
			std::vector<int> path; 

			// ----- Printando shortest path -----
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
		  
		  	int l_m = game->get_game_board()->get_value_matrix_by_abs_index(path[1]);
		  	current_player->set_last_moviment(l_m);

		  	int f_m = game->get_game_board()->get_value_matrix_by_abs_index(path[dist[dest]]);
		  	current_player->set_first_moviment(f_m);

		  	current_player->set_path_l(dist[dest]);

		  	if (dist[dest] < smallest_path)
		  	{
		  		smallest_path = dist[dest];
		  	}

		  	current_player->set_is_winner(true);
		  	//std::cout << current_player->get_name() << ":" << current_player->get_path_l() << std::endl;


		  	winner_count++;

		}
		else
		{
			loser_count++;
		}
	}

	//std::cout << "Smallest path: " << smallest_path << std::endl; 

	// ----- Se todos os players perderam ------
	if (loser_count == amount_players_i)
	{
		std::cout << "SEM VENCEDORES" << std::endl;
	}
	else
	{
		if (winner_count == 1)
		{
			for (auto i = 0; i < amount_players_i; ++i)
			{
				if (game->get_game_player(i)->get_is_winner())
				{
					std::cout << game->get_game_player(i)->get_name() << std::endl;
					std::cout << game->get_game_player(i)->get_path_l() << std::endl;
					break;
				}
			}
		}
		else
		{
			std::vector<Player*> winner_smallest_path;
			int qnt_players = 0;

			for (auto i = 0; i < amount_players_i; ++i)
			{
				if (game->get_game_player(i)->get_path_l() == smallest_path)
				{
					winner_smallest_path.push_back(game->get_game_player(i));
					qnt_players++;
				}
			}

			if (qnt_players == 1)
			{
				std::cout << winner_smallest_path.at(0)->get_name() << std::endl;
				std::cout << winner_smallest_path.at(0)->get_path_l() << std::endl;
				
			}
			else
			{
				int smallest_l_m = winner_smallest_path.at(0)->get_last_moviment();
				int qnt_players_smallest = 0;

				for (auto i = 1; i < qnt_players; ++i)
				{
					if (winner_smallest_path.at(i)->get_last_moviment() < smallest_l_m)
					{
						smallest_l_m = winner_smallest_path.at(i)->get_last_moviment();
						qnt_players_smallest = 0;
					}
					else if (winner_smallest_path.at(i)->get_last_moviment() == smallest_l_m)
					{
						qnt_players_smallest++;
					}
				}
				int smallest_f_m = 9999;


				if (qnt_players_smallest > 0)
				{
					for (auto i = 0; i < qnt_players; ++i)
					{
						if (winner_smallest_path.at(i)->get_last_moviment() == smallest_l_m)
						{
							if (winner_smallest_path.at(i)->get_first_moviment() < smallest_f_m)
							{
								smallest_f_m = winner_smallest_path.at(i)->get_first_moviment();
							}
						}
					}
				}

				for (auto i = 0; i < qnt_players; ++i)
				{
					if (winner_smallest_path.at(i)->get_last_moviment() == smallest_l_m)
					{
						if (winner_smallest_path.at(i)->get_first_moviment() == smallest_f_m)
						{
							std::cout << winner_smallest_path.at(i)->get_name() << std::endl;
							std::cout << winner_smallest_path.at(i)->get_path_l() << std::endl;
							break;
						}
					}
				}
			}
		}
	}


	return 0;
}