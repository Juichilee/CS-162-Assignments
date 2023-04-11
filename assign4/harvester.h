/****************************************
 ** Program Filename: thrower.h
 ** Author: Juichi Lee
 ** Description: header file for thrower.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef Harvester_H
#define Harvester_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Harvester:public Ant{	
		
	public:
		//Constructor
		Harvester();
		
		//Virtual functions
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
