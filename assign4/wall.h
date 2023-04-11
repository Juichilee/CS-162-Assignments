/****************************************
 ** Program Filename: wall.h
 ** Author: Juichi Lee
 ** Description: header file for wall.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef WALL_H
#define WALL_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Wall:public Ant{	
		
	public:
		//Constructor
		Wall();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
