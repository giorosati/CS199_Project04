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
using std::endl;


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
		return NULL;
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
		return NULL;
	}
}

void myQueue::enqueue(Monster* mPointer)			//add node to the end of the queue
{
	if (head == NULL)
	{
		head = new Node;
		head->value = mPointer;
		head->next = NULL;
	}
	else
	{
		Node* tempNode = head;
		while (tempNode->next != NULL)	//find last node
		{
			tempNode = tempNode->next;
		}
		Node* newNode = new Node;
		newNode->value = mPointer;
		newNode->next = NULL;
		tempNode->next = newNode;
	}
}


void myQueue::dequeue()			//remove node from the front of the queue
{
	if (head == NULL)
	{}
	else
	{
		if (head->next == NULL)		//case where only one node
		{
			Node* tempNode = head;
			head = NULL;
			delete tempNode;
		}
		else
		{
			Node* tempNode = head;
			head = head->next;
			delete tempNode;
		}
	}
}