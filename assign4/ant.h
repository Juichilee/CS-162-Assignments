/****************************************
 ** Program Filename: ant.h
 ** Author: Juichi Lee
 ** Description: header file for ant.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef ANT_H
#define ANT_H
#include "bug.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ant: public Bug{	
	protected:
		int food_cost;
		
	public:
		//Accessors Mutators
		int get_food_cost();

		//Constructor
		Ant();

		//Virtual function
		virtual void attack(Bug*)=0;
		virtual void check_target(vector<Bug*>*)=0; 
};
#endif
