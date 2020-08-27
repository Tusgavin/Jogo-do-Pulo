#include "Board.hpp"

#define DEBUG_BOARD 0

Board::Board(int _dimension_x, int _dimension_y) 
	: dimension_x(_dimension_x),  dimension_y(_dimension_y) 
{

	this->matrix_board.resize(_dimension_x);

	for (auto i = 0; i < _dimension_x; ++i) {
		for (auto j = 0; j < _dimension_y; ++j) {
			this->matrix_board.at(i).resize(_dimension_y);
		}
	}
}

Board::~Board() 
{

}

void Board::add_value_to_board(int x, int y, int value)
{
	this->matrix_board.at(x).at(y) = value;
}

void Board::print_board() const
{
	for (auto row = this->matrix_board.begin(); row != this->matrix_board.end(); ++row)
	{
		for (auto col = row->begin(); col != row->end(); ++col)
		{
			std::cout << *col << " ";
		}

		std::cout << std::endl;
	}
}
