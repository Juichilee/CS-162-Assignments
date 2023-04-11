/**************************************************
 * Program: house.h
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .h for child class house
 * **************************************************/
#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <string>
#include "property.h"
#include "citizen.h"
using namespace std;

class House : public Property{

	private:
		Citizen tenant;
		
		int rent;	
	public:
		//Accessors and Mutators
		
		Citizen get_tenant();
		
		int get_rent();

		void virtual set_rent();
		
		//Constructor and Big 3
		
		House();

		~House();

		House(const House&);
		
		House& operator=(const House&);
		
		//Functions
		void print();
		
		int collect_rent();
		
		bool all_leave();		

		void remove_tenant();	
};
#endif
