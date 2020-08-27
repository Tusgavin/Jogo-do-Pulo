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

	int get_dimension_x() const;
	int get_dimension_y() const;
	Matrix<int> get_matrix_board() const;

	void set_dimension_x(int _dimension_x);
	void set_dimension_y(int _dimension_y);

	void set_value_to_board(int x, int y, int value);

	void print_board() const;

};
