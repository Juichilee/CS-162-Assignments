/****************************************
 ** Program Filename: thrower.h
 ** Author: Juichi Lee
 ** Description: header file for thrower.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef THROWER_H
#define THROWER_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Thrower:public Ant{	
		
	public:
		//Constructor
		Thrower();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
