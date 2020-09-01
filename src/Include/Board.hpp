#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <algorithm>


template <typename T>
using Matrix = std::vector<std::vector<T>>;

class Board 
{
private:

	int dimension_x;
	int dimension_y;

	Matrix<int> matrix_board;

	Matrix<std::pair<int, int>> graph;

public:

	Board(int _dimension_x, int _dimension_y);
	~Board();

	int get_dimension_x() const;
	int get_dimension_y() const;
	Matrix<int> get_matrix_board() const;
	int get_value_in_position(int _x, int _y) const;

	void set_dimension_x(int _dimension_x);
	void set_dimension_y(int _dimension_y);
	void set_value_to_board(int _x, int _y, int _value);

	void print_board() const;
	void print_graph() const;

	void populate_graph();

	bool BFS(std::pair<int, int> _position, int dist[], int pred[]);
};
