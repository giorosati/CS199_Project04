/*********************************************************************
** Program Filename: myll.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: myLL class implementation file CS199_400 Project 4
*********************************************************************/

#include "myLL.hpp"
#include "node.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

myLL::myLL()			//default constructor
{
	head = NULL;
}

myLL::~myLL()			//deconstructor
{
	//cout << "myLL deconstructor has run" << endl;
}

/*********************************************************************
** Function: displayList
** Description: If there are no elements in the list, outputs
** "There are no items in the list."
** Otherwise it iterates through the entire list outputing
** each monster's name on a new line.
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void myLL::displayList()
{
	if (head == NULL)
	{
		cout << "There are no items in the list." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		Node* tempNode = head;
		cout << tempNode->value->getType() << endl;	//outputs monster name
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;						//set tempNode to the next node
			cout << tempNode->value->getType() << endl;//outputs nodes after head
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: addValue
** Description: Adds a new node for a monster added to the list
** and updates all necessary pointers.
** Pre-Conditions: monster pointer argument received
** Post-Conditions: the list will have an additinal node at the end.
*********************************************************************/
void myLL::addValue(Monster* valueIn)
{
	if (head == NULL)		//case where no nodes exist
	{
		head = new Node;
		head->value = valueIn;
		head->next = NULL;
		cout << endl;
	}
	else					//adds a node to the end of the list
	{
		Node* lastNode = findLast(head);
		lastNode->next = new Node;
		lastNode->next->value = valueIn;
		lastNode->next->next = NULL;
		cout << endl;
	}
}

/*********************************************************************
** Function: removeLast
** Description: If the list is empty outputs:
** "You cannot remove an element from an empty list!"
** Othersie uses findLast to locate the last node, deletes the last node
** and updates the next pointer on the new last node.
** Pre-Conditions: none
** Post-Conditions: if the list was not empty, the list will be one node
** shorter.
*********************************************************************/
void myLL::removeLast()
{
	if (head == NULL)
	{
		cout << "You cannot remove an element from an empty list!" << endl;
		cout << endl;
	}
	else
	{
		Node* tempNode = head;
		if (tempNode->next == NULL)	//case where only one node exists
		{
			head = NULL;
			delete tempNode;
		}
		else if (tempNode->next->next == NULL)	//case where only two nodes exits
		{
			tempNode->next = NULL;
			delete tempNode->next;
		}
		else
		{
			{
				while (tempNode->next->next != NULL)
					tempNode = tempNode->next;
			}
			tempNode->next = NULL;
			delete tempNode->next;
		}
	}
	cout << endl;
}

/*********************************************************************
** Function: sort
** Description: Sorts the linked list in ascending order
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void myLL::sort()
{
	vector<Node*> nodes;
	Node* tempNode = head;
	while (tempNode != NULL)
	{
		nodes.push_back(tempNode);
		tempNode = tempNode->next;
	}

	tempNode = nodes[0];
	bool swap;
	do
	{
		swap = false;
		for (unsigned count = 0; count < nodes.size()-1; count++)
		{
			if (nodes[count]->value->getType().at(0) > nodes[count + 1]->value->getType().at(0))
			{
				tempNode = nodes[count];
				nodes[count] = nodes[count + 1];
				nodes[count + 1] = tempNode;
				swap = true;
			}
		}
	} while (swap);

	head = nodes[0];
	head->next = nodes[1];
	for (int i = 1; i < (nodes.size() - 1); i++)
	{
		nodes[i]->next = nodes[i + 1];
	}
	nodes[nodes.size() - 1]->next = NULL;
}

/*********************************************************************
** Function: search
** Description: Sorts the linked list in ascending order
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool myLL::search(string searchString)
{
	if (head == NULL)
	{
		return false;
	}
	else
	{
		Node* tempNode = head;
		while (tempNode != NULL)
		{
			if (tempNode->value->getType() == searchString)
			{
				return true;
			}
			tempNode = tempNode->next;						//set tempNode to the next node
		}
		return false;
	}
}

/*********************************************************************
** Function: attack
** Description: If the list is empty outputs:
** "There are no monsters in the list."
** Othersie iterates through the entire list calling the attack
** function for each monster in the list.
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void myLL::attack()
{
	if (head == NULL)
	{
		cout << "There are no monsters in the list." << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		Node* tempNode = head;
		tempNode->value->attack();		//outputs monster name
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;		//set tempNode to the next node
			tempNode->value->attack();	//outputs nodes after head
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: findLast
** Description: Finds the last node in the list by searching for the node
** with next = NULL.
** Pre-Conditions: none
** Post-Conditions: returns the pointer to the last node in the list
*********************************************************************/
Node*  myLL::findLast(Node* head)
{
	Node* tempNode = head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}