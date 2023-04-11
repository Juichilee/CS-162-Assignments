/**************************************************
 * Program: tycoon.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .h for the class tycoon
 * **************************************************/
#ifndef TYCOON_H
#define TYCOON_H
#include <iostream>
#include <string>
#include "property.h"
using namespace std;

class Tycoon{

	private:
		int balance;
		
		Property* properties;
	
		Property* purchasable_properties;		
	
		int num_properties;	

		int num_purchasable_properties;
	public:

		//Accessors and Mutators
		int get_balance();
		
		int get_num_properties();
	
		Property* get_properties();

		Property* get_purchasable_properties();

		int get_num_purchasable_properties();		

		void set_num_properties(int);
		
		void set_balance(int);

		void set_properties(Property*);

		void set_purchasable_properties(Property*);
		
		void set_num_purchasable_properties(int);		

		//Constructor and Big 3
		Tycoon();

		~Tycoon();

		Tycoon(const Tycoon&);
		
		Tycoon& operator=(const Tycoon&);
	
		//Functions
		void random_event();
		
		void pay_tax();
		
		void pay_mortgage();

		void action();

		void adjust_property_rent();

		void buy_property();

		void sell_property();
		
		void sell_property2(int);

		void add_property(Property);

		void remove_property(int);
		
		void view_properties();
		
		void view_purchasable();
		
		void sold_for(int, int);
};
#endif
