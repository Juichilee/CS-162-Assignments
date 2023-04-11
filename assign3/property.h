/**************************************************
 * Program: property.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .h for parent class property
 *************************************************/
#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <string>
using namespace std;

class Property{

	protected:
		string type;
		int value;
		double tax_rate;
		int mortgage;
		int debt;
		string location;
	
	public:
		//Accessors Mutators
		string get_type();

		int get_value();

		void set_value(int);	
	
		double get_tax_rate();

		int get_mortgage();

		int get_debt();

		void set_debt(int);	
	
		string get_location();

		//Constructor and Big 3
		
		Property();

		~Property();

		Property(const Property&);
		
		Property& operator=(const Property&);
	
		//Virtual Functions
		bool all_leave();
		void virtual set_rent();

};
#endif
