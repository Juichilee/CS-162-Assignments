/****************************************
 ** Program Filename: ant.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for ant
 ** Date: 11/24/18
 * *************************************/
#include "ant.h"
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Ant::Ant(){
	type = "A";
	armor = 1;
	position = 0;
	food_cost = 1;
}

//Accessors Mutators
int Ant::get_food_cost(){
	return food_cost;
}

