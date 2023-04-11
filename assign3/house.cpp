/**************************************************
 * Program: house.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .cpp for child class house
 * **************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include "house.h"
#include "citizen.h"
using namespace std;

//Functions
//collect_rent(): checks if the tenant left and returns rent if they haven't
int House::collect_rent(){
	if(tenant.get_left() == false){
		return rent;
	}
}

//remove_tenant(): sets the variable left to true
void House::remove_tenant(){
	tenant.leave();
}	

//all_leave(): checks if all the tenants left the building
bool House::all_leave(){
	if(tenant.get_left() == false){
		return false;
	}
	return true;
}

//print(): prints house information
void House::print(){
	cout << "Type:" << type << endl;
	cout << "Value:" << value << endl;
	cout << "Mortgage:" << mortgage << endl;
	cout << "Tax_rate:" << tax_rate << endl;
	cout << "Location:" << location << endl;
	cout << "Rent:" << rent << endl;
	cout << "Tenant Budgets and Agreeability:" << endl;
	cout << tenant.get_budget() << "&"<< tenant.get_agreeability() << "&" << tenant.get_left() << endl;
}

//Constructor and Big 3
		
House::House(){
	tenant = Citizen();
	type = "House";
	rent = 500; //lowest budget for citizen
	value = rand()%500001 + 100000;
	mortgage  = rand()%501 + 1;
	debt = value;
	tax_rate = 0.015;
	int x = rand()%4;
	switch (x){
		case 0: location = "Northeast";
			break;
		case 1: location = "Southwest";
			break;
		case 2: location = "Midwest";
			break;
		case 3: location = "Northwest";
			break;
	}
}

House::~House(){
}

House::House(const House& a){
	type = a.type;
	tenant = a.tenant;
	rent = a.rent;
	value = a.value;
	tax_rate = a.tax_rate;
	mortgage = a.mortgage;
	debt = a.debt;
	location = a.location;	
}
		
House& House::operator=(const House& a){
	if(&a != this){
		type = a.type;
		tenant = a.tenant;
		rent = a.rent;
		value = a.value;
		tax_rate = a.tax_rate;
		mortgage = a.mortgage;
		debt = a.debt;
		location = a.location;	
	}
}

//Accessors and Mutators
		
Citizen House::get_tenant(){
	return tenant;
}
		
int House::get_rent(){
	return rent;
}

void House::set_rent(){
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "What is the new rent for this house?" << endl; 
		cin >> input;
		int s = atoi(input.c_str());
		if(s != 0){
			rent = s;
			if(rent > tenant.get_budget()){
				if(tenant.get_agreeability() == 1){
				rent = 0;
				}else{
					tenant.leave();
				}
			}
		}else{
			cout << "Not valid. Please input valid choice" << endl;
		}
	}
}
		
