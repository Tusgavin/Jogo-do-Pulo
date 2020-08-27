#pragma once

#include <iostream>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

class Board 
{
private:

	int dimension_x;
	int dimension_y;

	Matrix<int> matrix_board;

public:

	Board(int _dimension_x, int _dimension_y);
	~Board();

	void add_value_to_board(int x, int y, int value);

	void print_board() const;

};
