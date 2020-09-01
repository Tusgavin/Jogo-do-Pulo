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

void Board::set_dimension_x(int _dimension_x)
{
	this->dimension_x =_dimension_x;
}

void Board::set_dimension_y(int _dimension_y)
{
	this->dimension_y =_dimension_y;
}

void Board::set_value_to_board(int _x, int _y, int _value)
{
	this->matrix_board.at(_x).at(_y) = _value;
}

void Board::print_board() const
{
	for (auto row = this->matrix_board.begin(); row != this->matrix_board.end(); ++row)
	{
		for (auto col = row->begin(); col != row->end(); ++col)
		{
			std::cout << (*col) << " ";
		}

		std::cout << std::endl;
	}
}

void Board::print_graph() const
{
	for (auto i = this->graph.begin(); i != this->graph.end(); ++i)
	{

		for (auto j = i->begin(); j != i->end(); ++j)
		{
			std::cout << "(" << j->first << ", " << j->second << ")";
		}

		std::cout << std::endl;
	}
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

			if (value == 0)
			{
				break;
			}

			if (i - value >= 0)
			{
				position.first = i - value;
				this->graph.at(count_vertices).push_back(position);
			}

			if (i + value < this->get_dimension_x())
			{
				position.first = i + value;
				this->graph.at(count_vertices).push_back(position);
			}

			if (j - value >= 0)
			{
				position.second = j - value;
				this->graph.at(count_vertices).push_back(position);
			}

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
	//std::cout << "Index:" << index << std::endl;

	visited[index] = true;
	dist[index] = 0;

	queue.push_back(_position);

	//std::list<std::pair<int, int>>::iterator it;


	while(!queue.empty())
	{
		temp_pair_1 = queue.front();

		int index2 = formula(temp_pair_1.first, temp_pair_1.second, get_dimension_y());

		//std::cout << "[" << temp_pair_1.first << "," << temp_pair_1.second << "]" << std::endl;
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
			}
		}

	}

	if ((temp_pair_1.first == (get_dimension_x() - 1)) && (temp_pair_1.second == (get_dimension_y() - 1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}