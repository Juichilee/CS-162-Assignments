/**************************************************
 * Program: apartmentcomplex.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .h for child class apartmentcomplex
 * **************************************************/
#ifndef APARTMENTCOMPLEX_H
#define APARTMENTCOMPLEX_H
#include <iostream>
#include <string>
#include "property.h"
#include "citizen.h"
using namespace std;

class ApartmentComplex : public Property{

	private:
		Citizen* tenants;

		int* rents;
	
		int size;
	
	public:
		//Accessors and Mutators
		
		Citizen* get_tenants();

		int* get_rents();

		void virtual set_rent();
		
		//Constructor and Big 3
		
		ApartmentComplex();

		~ApartmentComplex();

		ApartmentComplex(const ApartmentComplex&);
		
		ApartmentComplex& operator=(const ApartmentComplex&);

		//Functions
		int collect_rent();
		
		bool all_leave();

		void print();
			
		void remove_tenant(int);	
};
#endif
