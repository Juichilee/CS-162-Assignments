/**************************************************
 * Program: pizza.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The implementation for pizza
 *************************************************/

#include <iostream>
#include <string>
#include "pizza.h"

/****************************
 * Name: Pizza(string, int, int, int, int ,string*) 
 * Description: Constructor for pizza class.
 * **************************/
Pizza::Pizza(string p_name, int s_cost, int m_cost, int l_cost,
			int num_i, string* i){
	name = p_name;
	small_cost = s_cost;
	medium_cost = m_cost;
	large_cost = l_cost;
	num_ingredients = num_i;
	ingredients = i;
}

/****************************
 * Name: Pizza() 
 * Description: Default constructor for pizza class.
 * **************************/
Pizza::Pizza(){
	name = "";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
}

/****************************
 * Name: ~Pizza() 
 * Description: Deconstructor for pizza class.
 * **************************/
Pizza::~Pizza(){
	delete [] ingredients;
	ingredients = NULL;
}

/****************************
 * Name: Pizza(const Pizza&) 
 * Description: Copy constructor for pizza class.
 * **************************/
Pizza::Pizza(const Pizza& a){

	name = a.name;

	small_cost = a.small_cost;

	medium_cost = a.medium_cost;

	large_cost = a.large_cost;

	num_ingredients = a.num_ingredients;

	ingredients = new string[a.num_ingredients];

	std::copy(a.ingredients, a.ingredients+num_ingredients, ingredients);
}

/****************************
 * Name: Pizza::operator=(const Pizza&) 
 * Description: Assignment operator overload for pizza class.
 * **************************/
Pizza& Pizza::operator =(const Pizza& a){

	if(&a != this){
		
		name = a.name;

		small_cost = a.small_cost;

		medium_cost = a.medium_cost;

		large_cost = a.large_cost;

		num_ingredients = a.num_ingredients;

		ingredients = new string[a.num_ingredients];

		std::copy(a.ingredients, a.ingredients+num_ingredients, ingredients);

	}

	return* this;

}

//Accessors Mutators
string Pizza::get_name(){
	return name;
}

void Pizza::set_name(string new_name){
	name = new_name;
}	

int Pizza::get_small_cost(){
	return small_cost;
}	
	
void Pizza::set_small_cost(int new_small_cost){
	small_cost = new_small_cost;
}

int Pizza::get_medium_cost(){
	return medium_cost;
}	
	
void Pizza::set_medium_cost(int new_medium_cost){
	medium_cost = new_medium_cost;
}

int Pizza:: get_large_cost(){
	return large_cost;
}
	
void Pizza::set_large_cost(int new_large_cost){
	large_cost = new_large_cost;
}

int Pizza::get_num_ingredients(){
	return num_ingredients;
}	

void Pizza::set_num_ingredients(int new_num_ingredients){
	num_ingredients = new_num_ingredients;
}	

string* Pizza::get_ingredients(){
	return ingredients;
}	

void Pizza::set_ingredients(string* new_ingredients){
	ingredients = new_ingredients;
}


