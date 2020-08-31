#pragma once

#include <iostream>
#include <memory>

struct Node
{
	int value;
	int position_x;
	int position_y;

	Node * node_x_p;  // x-axis positive
	Node * node_x_n;  // x-axis negative
	Node * node_y_p;  // y-axis positive
	Node * node_y_n;  // y-axis negative
}

class Tree
{
private:
	std::unique_ptr<Node> root;

public:
	Tree(int _position_x, int _position_y, int _value);
	~Tree();

	void add_node_to_tree(int _flag, int _position_x, int _position_y, int _value);

}