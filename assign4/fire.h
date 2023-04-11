/****************************************
 ** Program Filename: fire.h
 ** Author: Juichi Lee
 ** Description: header file for fire.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef FIRE_H
#define FIRE_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Fire:public Ant{	
		
	public:
		//Constructor
		Fire();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
