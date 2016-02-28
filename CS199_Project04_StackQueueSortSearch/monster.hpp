/*********************************************************************
** Program Filename: monster.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-02-28
** Description: Monster class header file CS199_400 Project 4
*********************************************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP

//includes
#include <string>

//usings
using std::string;

class Monster
{
protected:
	int strength;
	int numAttacks;
	string typeOf;

public:
	~Monster();						//deconstructor
	virtual void attack() = 0;		//virtual attack()
	string getTypeOf();				//function prototype
};

#endif
