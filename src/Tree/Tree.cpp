#include "Tree.hpp"

Tree::Tree(int _position_x, int _position_y, int _value)
{
	this->root->position_x = _position_x;
	this->root->position_y = _position_y;
	this->root->value = _value;
	this->root->node_x_p = nullptr;
	this->root->node_x_n = nullptr;
	this->root->node_y_p = nullptr;
	this->root->node_x_n = nullptr;
}

Tree::~Tree()
{

}

void Tree::add_node_to_tree(int _flag, int _position_x, int _position_y, int _value)
{
	Node * new_node = new Node();

	new_node->position_x = _position_x;
	new_node->position_y = _position_y;
	new_node->value = _value;

	new_node->node_x_p = nullptr;
	new_node->node_x_n = nullptr;
	new_node->node_y_p = nullptr;
	new_node->node_x_n = nullptr;

	switch(_flag)
	{
		case 1:

		case 2:

		case 3:

		case 4:

		default:
			break;
	}
}