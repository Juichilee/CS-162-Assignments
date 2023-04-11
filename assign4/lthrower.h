/****************************************
 ** Program Filename: lthrower.h
 ** Author: Juichi Lee
 ** Description: header file for lthrower.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef LTHROWER_H
#define LTHROWER_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Lthrower:public Ant{	
		
	public:
		//Constructor
		Lthrower();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
