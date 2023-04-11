/****************************************
 ** Program Filename: bee.h
 ** Author: Juichi Lee
 ** Description: header file for bee.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef BEE_H
#define BEE_H
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Bee: public Bug{	
	public:
		//Functions
		void move();

		//Constructor
		Bee();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
