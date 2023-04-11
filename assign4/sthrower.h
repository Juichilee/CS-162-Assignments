/****************************************
 ** Program Filename: sthrower.h
 ** Author: Juichi Lee
 ** Description: header file for short thrower.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef STHROWER_H
#define STHROWER_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Sthrower:public Ant{	
		
	public:
		//Constructor
		Sthrower();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
