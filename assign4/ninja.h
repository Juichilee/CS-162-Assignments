/****************************************
 ** Program Filename: ninja.h
 ** Author: Juichi Lee
 ** Description: header file for ninja.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef NINJA_H
#define NINJA_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Ninja:public Ant{	
		
	public:
		//Constructor
		Ninja();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
