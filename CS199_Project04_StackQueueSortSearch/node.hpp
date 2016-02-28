/*********************************************************************
** Program Filename: node.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: node struct header file CS199_400 Project 4 - Winter 2016
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include "monster.hpp"

struct Node
{
	Monster* value;
	Node* next;
};

#endif
