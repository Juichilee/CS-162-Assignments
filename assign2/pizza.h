/**************************************************
 * Program: pizza.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The header for pizza
 *************************************************/

#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>

using namespace std;

class Pizza{

	private:

		string name;

		int small_cost;

		int medium_cost;

		int large_cost;

		int num_ingredients;

		string* ingredients;
	
	public:
		//Accessors Mutators	
		string get_name();

		void set_name(string);	

		int get_small_cost();	
	
		void set_small_cost(int);

		int get_medium_cost();	
	
		void set_medium_cost(int);

		int get_large_cost();
	
		void set_large_cost(int);

		int get_num_ingredients();		

		void set_num_ingredients(int);	

		string* get_ingredients();	

		void set_ingredients(string*);

		Pizza(string, int, int, int,
			int, string*);
		//Functions
		Pizza();		

		~Pizza();

		Pizza(const Pizza&);

		Pizza& operator=(const Pizza&);

};

#endif
