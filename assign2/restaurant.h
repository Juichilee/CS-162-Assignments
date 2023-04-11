/**************************************************
 * Program: restaurant.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The header file for restaurant
 *************************************************/

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

struct employee{
	
	string id;

	string first_name;
	
	string last_name;

	string password;

};

struct hours{

	string day;

	string open_hour;
	
	string close_hour;

};

class Restaurant{

	private:
		
		Menu* menu;

		employee* employees;
		
		int num_employees;

		hours* week;

		string name;

		string phone;

		string address;
		
	public:	

		//Accessors Mutators
		void write_to_menu();

		int stringtoint(string);
		
		void set_menu(Menu*);

		void set_employees(employee*);
		
		void set_num_employees(int);

		void set_week(hours*);

		void set_name(string);

		void set_phone(string);

		void set_address(string);

		Menu* get_menu();

		employee* get_employees();

		int get_num_employees();

		hours* get_week();

		string get_name();

		string get_phone();

		string get_address();

		//Functions
		void load_menu(fstream&);

		void load_employees(fstream&);		

		void load_week(fstream&);		

		void load_name_phone_address(fstream&);
	
		void load_data();
	
		bool login(string id, string password);
		
		void view_menu();
		
		void view_hours();

		void view_address();

		void view_phone();

		void search_menu_by_price();

		void search_by_ingredients();

		void place_order(Pizza*);

		void place_order();			

		void change_hours();

		void add_to_menu();

		void remove_from_menu();

		void view_orders();

		void remove_orders();
		
		Restaurant(Menu*, employee*, int, hours*, string,
			string, string);
		
		Restaurant();		

		~Restaurant();
		
		Restaurant(const Restaurant&);

		Restaurant& operator=(const Restaurant&);
};

#endif
