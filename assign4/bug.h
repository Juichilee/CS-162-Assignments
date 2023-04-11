/****************************************
 ** Program Filename: bug.h
 ** Author: Juichi Lee
 ** Description: header file for bug.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef BUG_H
#define BUG_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bug{
	protected:
		string type; //bug type
		int armor; //varies from bug
		int position; //from 0-9;
		int attack_value;
	public:
		//Accessors Mutators
		int get_armor();
		string get_type();
		int get_position();
		int get_attack_value();
		void set_armor(int);
		void set_type(string);
		void set_position(int);
		void set_attack_value(int a);

		//Constructor
		Bug();

		//Virtual function
		virtual void attack(Bug*) = 0;
		virtual void check_target(vector<Bug*>*) = 0;
};
#endif
