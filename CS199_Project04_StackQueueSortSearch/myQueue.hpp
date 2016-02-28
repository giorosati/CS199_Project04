/*********************************************************************
** Program Filename: myQueue.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: myQueue class header file CS199_400 Project 4
*********************************************************************/

#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

#include "node.hpp"

class myQueue
{
protected:

	Node* head;

public:
	myQueue();					//default constructor
	~myQueue();					//deconstructor
	Monster* peekFirst();		//return value of the node at the front of the queue
	Monster* peekLast();		//return value of the node at the end of the queue
	void enqueue();				//add node to teh end of the queue
	void dequeue();				//remove node from the front of the queue
};
#endif