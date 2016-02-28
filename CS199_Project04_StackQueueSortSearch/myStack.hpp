/*********************************************************************
** Program Filename: myStack.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: myStack class header file CS199_400 Project 4
*********************************************************************/

#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#include "node.hpp"

class myStack
{
protected:

	Node* head;

public:
	myStack();				//default constructor
	myStack(Node*);			//constructor w/ node pointer
	~myStack();				//deconstructor
	Monster* peek();			//return top node
	void pop();				//remove the top node
	void push(Monster*);		//add a node to the top of the list
};
#endif