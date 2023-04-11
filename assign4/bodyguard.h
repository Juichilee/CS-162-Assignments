/****************************************
 ** Program Filename: bodyguard.h
 ** Author: Juichi Lee
 ** Description: header file for bodyguard.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef BODYGUARD_H
#define BODYGUARD_H
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

class Bodyguard:public Ant{	
		
	public:
		//Constructor
		Bodyguard();

		//Virtual function
		virtual void attack(Bug*);
		virtual void check_target(vector<Bug*>*); 
};
#endif
