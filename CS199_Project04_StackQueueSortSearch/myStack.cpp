/*********************************************************************
** Program Filename: myStack.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: myStack class implementation file CS199_400 Project 4
*********************************************************************/


//includes
#include "myStack.hpp"
#include <iostream>

using std::cout;
using std::endl;

myStack::myStack()				//default constructor
{
	head = NULL;
}

myStack::~myStack()				//deconstructor
{}

Monster* myStack::peek()			//return top node
{
	if (head != NULL)
	{
		return head->value;
		cout << endl;
	}
	else
	{
		return NULL;
	}

}

void myStack::pop()				//remove the top node
{
	Node* tempNode = head;
	head = head->next;
	delete tempNode;
}

void myStack::push(Monster* valueIn)	//add a node to the top of the list
{
	if (head == NULL)
	{
		Node* newNode = new Node;
		head = newNode;
		head->value = valueIn;
		head->next = NULL;
	}
	else
	{
		Node* newNode = new Node;
		newNode->value = valueIn;
		newNode->next = head;
		head = newNode;
		cout << endl;
	}
}