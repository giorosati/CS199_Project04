/*********************************************************************
** Program Filename: myQueue.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: myQueue class implementation file CS199_400 Project 4
*********************************************************************/


//includes
#include "myQueue.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;


myQueue::myQueue()				//default constructor
{
	head = NULL;
}

myQueue::~myQueue()				//deconstructor
{}

Monster* myQueue::peekFirst()		//return value of the node at the front of the queue
{
	if (head != NULL)
	{
		return head->value;
	}
	else
	{
		std::cout << "the list is empty";
	}
}

Monster* myQueue::peekLast()		//return value of the node at the end of the queue
{
	if (head != NULL)
	{
		Node* tempNode = head;
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		return tempNode->value;
	}
	else
	{
		std::cout << "the list is empty";
	}
}

void myQueue::enqueue()			//add node to teh end of the queue
{


}

void myQueue::dequeue()			//remove node from the front of the queue
{


}