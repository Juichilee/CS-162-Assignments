/**************************************************
 * Program: main.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The header file for menu
 *************************************************/

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "pizza.h"

using namespace std;

class Menu{

	private:

		int num_pizzas;

		Pizza* pizzas;

	
	public:
		//Accessors Mutators

		int get_num_pizzas();

		Pizza* get_pizzas();

		void set_num_pizzas(int);

		void set_pizzas(Pizza*);
		
		Menu(int, Pizza*);

		Menu();

		~Menu();

		Menu(const Menu&);
		
		Menu& operator=(const Menu&);
	
		//Functions

		Menu search_pizza_by_cost(int, string);

		Menu search_pizza_by_ingredients_to_include();
		
		Menu search_pizza_by_ingredients_to_exclude();

		void add_to_menu(Pizza);

		void remove_from_menu(int);

};

#endif
