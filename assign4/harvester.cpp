/****************************************
 ** Program Filename: thrower.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for thrower
 ** Date: 11/24/18
 * *************************************/
#include "harvester.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Harvester::Harvester(){
	type = "H";
	armor = 1;
	position = 0;
	food_cost = 2;
	attack_value = 0;	
}
//Functions
void Harvester::attack(Bug* targ){
}

void Harvester::check_target(vector<Bug*>* board){
}

