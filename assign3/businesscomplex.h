/**************************************************
 * Program: businesscomplex.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .h for child class businesscomplex
 * **************************************************/
#ifndef BUSINESSCOMPLEX_H
#define BUSINESSCOMPLEX_H
#include <iostream>
#include <string>
#include "property.h"
#include "business.h"
using namespace std;

class BusinessComplex : public Property{

	private:
		Business* tenants;

		int* rents;
	
		int size;
	
	public:
		//Accessors and Mutators
		
		Business* get_tenants();

		int* get_rents();

		void virtual set_rent();
		
		//Constructor and Big 3
		
		BusinessComplex();

		~BusinessComplex();

		BusinessComplex(const BusinessComplex&);
		
		BusinessComplex& operator=(const BusinessComplex&);

		//Functions
		int collect_rent();
		
		bool all_leave();		
	
		void print();
			
		void remove_tenant(int);	
};
#endif
