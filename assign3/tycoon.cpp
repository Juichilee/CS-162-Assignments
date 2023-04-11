/**************************************************
 * Program: tycoon.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The .cpp for the class tycoon
 * **************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include "tycoon.h"
#include "businesscomplex.h"
#include "apartmentcomplex.h"
#include "house.h"
#include "property.h"
using namespace std;

//Functions
//pay_tax(): goes through the properties and multiplies their property value by the tax rate, adding them to a total, and subtracting the total from the player's balance.
void Tycoon::pay_tax(){
	int total = 0;
	for(int i = 0; i < num_properties; i++){
		total += properties[i].get_value() * properties[i].get_tax_rate();
	}
	balance -= total;
}

//pay_mortgage(): goes through the properties and gets their mortgage rates, adding them to a total, and subtracting the total from the player's balance. Also subtracts property debt for every mortgage payment. 
void Tycoon::pay_mortgage(){
	int total = 0;
	for(int i = 0; i < num_properties; i++){
		if(properties[i].get_debt() != 0){
			total += properties[i].get_mortgage();
			properties[i].set_debt(properties[i].get_debt() - properties[i].get_mortgage());	
		}
	}
	balance -= total;
}

//action(): lists all of the actions the player can take in a turn
void Tycoon::action(){
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\nWhat would you like to do? (enter line#)" << endl;
		cout << "1. Buy Property\n2. Sell Property\n3. Adjust Rent\n4. View Properties\n5. Next Turn" << endl; 
		cin >> input;
		int s = atoi(input.c_str());
		if(s != 0 && s <= 5){
			switch(s){
				case 1: buy_property();
					break;
				case 2: sell_property();
					break;
				case 3: adjust_property_rent();
					break;
				case 4:	view_properties();
					break;
				case 5: valid_input = true;
					break;
			}
		}else{
			cout << "Not valid. Please input valid choice" << endl;
		}
	}
}

//adjust_property_rent(): allows the player to adjust a rent for a particular property in their properties.
void Tycoon::adjust_property_rent(){
	view_properties();
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "Insert line number of desired property to adjust rent for('Q' to quit)" << endl; 
		cin >> input;
		if(input == "Q" || input == "q"){
			valid_input = true;
		}else{
			int s = atoi(input.c_str());
			if(s != 0 && s <= num_properties){
				cout << s-1 << endl;
				cout << properties[s-1].get_type() << endl;
				properties[s-1].set_rent();
				valid_input = true;	
			}else{
				cout << "Not valid. Please input valid choice" << endl;
			}
		}	
	}	
}

//buy_property(): allows the player to buy a property from the starting list of purchasable properties. Once a property is bought, a new property of the same type is generated to replace the bought property in the purchasable properties list. 
void Tycoon::buy_property(){
	view_purchasable();
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\nInsert line number of desired property to buy('Q' to quit)" << endl;
		cin >> input;
		if(input == "Q" || input == "q"){
			valid_input = true;
		}else{
			int s = atoi(input.c_str());
			if(s != 0 && s <= num_purchasable_properties){
				add_property(purchasable_properties[s-1]);
				if(s-1%3 == 0){
					purchasable_properties[s-1] = House();
				}else if(s-1%3 == 1){
					purchasable_properties[s-1] = ApartmentComplex();
				}else{
					purchasable_properties[s-1] = BusinessComplex();
				}	
				valid_input = true;
			}else{
				cout << "Not valid. Please input valid choice" << endl;
			}
		}
	}

}

//add_property(): adds a property to the player's list of properties.
void Tycoon::add_property(Property new_property){
	int new_num_properties = num_properties + 1;
	Property* new_properties = new Property[new_num_properties];
	if(num_properties != 0){
		for(int i = 0; i < num_properties; i++){
			new_properties[i] = properties[i];
		}
		delete[] properties;
		properties = NULL;
	}
	new_properties[num_properties] = new_property;
	set_num_properties(new_num_properties);
	set_properties(new_properties);
	cout << "Sucessfully purchased" << endl;
}

//view_properties(): displays all of the player's currently owned properties
void Tycoon::view_properties(){
	if(num_properties != 0){
		for(int i = 0; i < num_properties; i++){
			cout << i+1 << ". " << properties[i].get_type() <<" " << properties[i].get_location()<< " $" << properties[i].get_value() << endl;

		}
	}else{
		cout << "No properties owned" << endl;
	}
}

//view_purchasable(): displays all of the purchasable properties that the player can buy.
void Tycoon::view_purchasable(){
	cout << "Properties for Sale" << endl;
	for(int i = 0; i < num_purchasable_properties; i++){
		cout << i+1 << ". " <<  purchasable_properties[i].get_type() << " " << purchasable_properties[i].get_location() << " $" << purchasable_properties[i].get_value() << endl;
	}
}

//sell_property(): allows the player to sell a property, but only if all the tenants in the property are gone. 
void Tycoon::sell_property(){
	view_properties();
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\nInsert line number of desired property to sell ('Q' to quit)" << endl;
		cin >> input;
		if(input == "Q" || input == "q"){
			valid_input = true;
		}else{
			int s = atoi(input.c_str());
			if(num_properties != 0 && s != 0 && s <= num_properties){
				sell_property2(s-1);
				valid_input = true;
			}else{
				cout << "Not valid. Please input valid choice" << endl;
			}
		}
	}

}

//sell_property2(): additional segments of code from sell_property() function
void Tycoon::sell_property2(int index){
	if(properties[index].all_leave() == false){
		cout << "Unable to sell because there are still tenants" << endl;
	}else{
		string input;
		bool valid_input = false;
		while(!valid_input){
			cout << "\nWhat price would you like to sell it at? ('Q' to quit)" << endl;
			cin >> input;
			if(input == "Q" || input == "q"){
				valid_input = true;
			}else{
				int s = atoi(input.c_str());
				if(s != 0){
					sold_for(s, index);
					remove_property(index);	
					valid_input = true;
				}else{
					cout << "Not valid. Please input valid choice" << endl;
				}
			}
		}

	}
}

//sold_for(): generates a random number from 0-2 and determines whether the player got their asking price, the property value, or 10% less than the property value.
void Tycoon::sold_for(int asking_price, int index){
	int chance = rand()%3;
	switch(chance){
		case 0: balance += asking_price; 
			cout << "You got your asking price!" << endl;
			break;
		case 1: balance += properties[index].get_value();
			cout << "You got the property value!" << endl;
			break;
		case 2: balance += (properties[index].get_value()*0.9);
			cout << "You got 10 percent less than property value!" << endl;
			break;
	}	
	cout << "New balance: "<< balance << endl;
}

//remove_property(): removes a property from the player's properties
void Tycoon::remove_property(int index){
	int new_num_properties = num_properties-1;
	Property* new_properties = new Property[new_num_properties];
	for(int i = 0; i < new_num_properties; i++){
		
		if(i >= index){
			new_properties[i] = properties[i+1];	
		}else{
			new_properties[i] = properties[i];
		}
	}
	num_properties = new_num_properties;
	set_properties(new_properties);
}

//random_event(): generates a random event that affects the player's properties each turn
void Tycoon::random_event(){
	int chance = rand()%6;
	switch(chance){
		case 0: 
			for(int i = 0; i < num_properties; i++){
				if(properties[i].get_location() == "Southeast"){
					properties[i].set_value(properties[i].get_value()/2);
				}
			}
			cout << "A Hurricane! SE Property value decreases by 50%." << endl;
			break;
		case 1:
			for(int i = 0; i < num_properties; i++){
				if(properties[i].get_location() == "Midwest"){
					properties[i].set_value(properties[i].get_value()*2/3);
				}
			} 
			cout << "A Tornado! MW Property value decreases by 30%" << endl;
			break;
		case 2: 
			for(int i = 0; i < num_properties; i++){
				if(properties[i].get_location() == "Northwest"){
					properties[i].set_value(properties[i].get_value()*0.9);
				}
			}
			cout << "An Earthquake! NW Property value decreases by 10%" << endl;
			break;
		case 3:
			for(int i = 0; i < num_properties; i++){
				if(properties[i].get_location() == "Southwest"){
					properties[i].set_value(properties[i].get_value()*3/4);
				}
			}
			cout << "A Wildfire! SW Property value decreases by 25%" << endl;
			break;
		case 4:
			for(int i = 0; i < num_properties; i++){
				properties[i].set_value(properties[i].get_value()*2/3);
			}
			cout << "A Stock Market Crash! All Property value decreases by 30%" << endl;
			break;
		case 5: 
			int chance2 = rand()%4;
			if(chance2 == 0){
				for(int i = 0; i < num_properties; i++){
					if(properties[i].get_location() == "Southwest"){
						properties[i].set_value(properties[i].get_value()*6/5);
					}
				}
				cout << "Gentrification! SW Property value increases by 20%" << endl;
	
			}else if(chance2 == 1){
				for(int i = 0; i < num_properties; i++){
					if(properties[i].get_location() == "Midwest"){
						properties[i].set_value(properties[i].get_value()*6/5);
					}
				}
				cout << "Gentrification! MW Property value increases by 20%" << endl;
	

			}else if(chance2 == 2){
				for(int i = 0; i < num_properties; i++){
					if(properties[i].get_location() == "Northwest"){
						properties[i].set_value(properties[i].get_value()*6/5);
					}
				}
				cout << "Gentrification! NW Property value increases by 20%" << endl;
	

			}else{
				for(int i = 0; i < num_properties; i++){
					if(properties[i].get_location() == "Southeast"){
						properties[i].set_value(properties[i].get_value()*6/5);
					}
				}
				cout << "Gentrification! SE Property value increases by 20%" << endl;
			}
			break;
	}	
}

//Accessors and Mutators
int Tycoon::get_balance(){
	return balance;
}

Property* Tycoon::get_properties(){
	return properties;
}

void Tycoon::set_balance(int a){
	balance = a;
}

void Tycoon::set_properties(Property* a){
	properties = a;
}

void Tycoon::set_num_properties(int a){
	num_properties = a;
}

int Tycoon::get_num_properties(){
	return num_properties;
}

Property* Tycoon::get_purchasable_properties(){
	return purchasable_properties;
}

void Tycoon::set_purchasable_properties(Property* a){
	purchasable_properties = a;
}

int Tycoon::get_num_purchasable_properties(){
	return num_purchasable_properties;
}
		
void Tycoon::set_num_purchasable_properties(int a){
	num_purchasable_properties = a;
}

//Constructor and Big 3
Tycoon::Tycoon(){
	balance = 500000;
	properties = NULL;
	num_properties = 0;
	num_purchasable_properties = 9;
	purchasable_properties = new Property[num_purchasable_properties];
	for(int i = 0; i < num_purchasable_properties; i++){
		if(i % 3 == 0){
			purchasable_properties[i] = House();
		}else if(i % 3 == 1){
			purchasable_properties[i] = ApartmentComplex();
		}else{
			purchasable_properties[i] = BusinessComplex();
		}
	}
}

Tycoon::~Tycoon(){
	delete [] purchasable_properties;
	purchasable_properties = NULL;
	delete [] properties;
	properties = NULL;
}

Tycoon::Tycoon(const Tycoon& a){
	properties = new Property[a.num_properties];
	for(int i = 0; i < a.num_properties; i++){
		properties[i] = a.properties[i];
	}
	purchasable_properties = new Property[a.num_purchasable_properties];
	for(int i = 0; i < a.num_purchasable_properties; i++){
		purchasable_properties[i] = a.purchasable_properties[i];
	}

	balance = a.balance;
	num_properties = a.num_properties;
	num_purchasable_properties = a.num_purchasable_properties;
}
		
Tycoon& Tycoon::operator=(const Tycoon& a){
	if(properties != NULL){
		delete[] properties;
	}
	if(purchasable_properties != NULL){
		delete[] purchasable_properties;
	}
	if(&a != this){
		properties = new Property[a.num_properties];
		for(int i = 0; i < a.num_properties; i++){
			properties[i] = a.properties[i];
		}
		purchasable_properties = new Property[a.num_purchasable_properties];
		for(int i = 0; i < a.num_purchasable_properties; i++){
			purchasable_properties[i] = a.purchasable_properties[i];
		}

		balance = a.balance;
		num_properties = a.num_properties;	
		num_purchasable_properties = a.num_purchasable_properties;
	}
}
	

