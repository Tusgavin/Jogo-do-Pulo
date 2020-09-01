#include "Board.hpp"

Board::Board(int _dimension_x, int _dimension_y) 
	: dimension_x(_dimension_x),  dimension_y(_dimension_y) 
{

	this->matrix_board.resize(_dimension_x);

	for (auto i = 0; i < _dimension_x; ++i) 
	{
		this->matrix_board.at(i).resize(_dimension_y);
	}

	this->graph.resize(_dimension_x * _dimension_y);
}

Board::~Board() 
{

}

int Board::get_dimension_x() const
{
	return this->dimension_x;
}

int Board::get_dimension_y() const
{
	return this->dimension_y;
}

Matrix<int> Board::get_matrix_board() const
{
	return this->matrix_board;
}

int Board::get_value_in_position(int _x, int _y) const
{
	return this->matrix_board.at(_x).at(_y);
}

void Board::set_value_to_board(int _x, int _y, int _value)
{
	this->matrix_board.at(_x).at(_y) = _value;
}

void Board::populate_graph()
{
	int count_vertices = 0;

	for (auto i = 0; i < this->get_dimension_x(); ++i)
	{
		for (auto j = 0; j < this->get_dimension_y(); ++j)
		{
			int value = this->get_value_in_position(i, j);
			
			std::pair<int, int> position;

			position.first = i;
			position.second = j;

			count_vertices = (((this->get_dimension_y())* i) + (1 + j) - 1);

			if (value == 0)
			{
				break;
			}

			if (i - value >= 0)
			{
				position.first = i - value;
				this->graph.at(count_vertices).push_back(position);
			}

			position.first = i;
			position.second = j;

			if (i + value < this->get_dimension_x())
			{
				position.first = i + value;
				this->graph.at(count_vertices).push_back(position);
			}

			position.first = i;
			position.second = j;

			if (j - value >= 0)
			{
				position.second = j - value;
				this->graph.at(count_vertices).push_back(position);
			}

			position.first = i;
			position.second = j;

			if (j + value < this->get_dimension_y())
			{
				position.second = j + value;
				this->graph.at(count_vertices).push_back(position);
			}


			count_vertices++;
		}
	}
}

bool Board::BFS(std::pair<int, int> _position, int dist[], int pred[])
{
	int total = this->dimension_y * this->dimension_x;

	bool * visited = new bool[total];

	for (auto i = 0; i < total; ++i)
	{
		visited[i] = false;
		dist[i] = 99999;
		pred[i] = -1;
	}


	std::pair<int, int> temp_pair_1;
	std::pair<int, int> temp_pair_2;

	std::list<std::pair<int, int>> queue;

	// ----- Formula para converter posições de matrix em um único inteiro -----
	auto formula = [](int x, int y, int total_col){
		return ((total_col)*(x) + (y + 1) - 1);
	};

	int index = formula(_position.first, _position.second, get_dimension_y());

	visited[index] = true;
	dist[index] = 0;

	queue.push_back(_position);


	while(!queue.empty())
	{
		temp_pair_1 = queue.front();

		int index2 = formula(temp_pair_1.first, temp_pair_1.second, get_dimension_y());

		queue.pop_front();

		for (auto it = this->graph.at(index2).begin(); it != this->graph.at(index2).end(); ++it)
		{	

			int index3 = formula(it->first, it->second, get_dimension_y());

			if (!visited[index3])
			{
				visited[index3] = true;

				dist[index3] = dist[index2] + 1;
				pred[index3] = index2;

				temp_pair_2.first = it->first;
				temp_pair_2.second = it->second;

				queue.push_back(temp_pair_2);

				if ((temp_pair_2.first == (get_dimension_x() - 1)) && (temp_pair_2.second == (get_dimension_y() - 1)))
				{
					return true;
				}
				
			}
		}
	}

	return false;
}

int Board::get_value_matrix_by_abs_index(int _index) const
{
	int x = _index / get_dimension_y();
	int y = _index % get_dimension_y();

	return get_value_in_position(x, y);
}