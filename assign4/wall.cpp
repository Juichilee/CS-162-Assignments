/****************************************
 ** Program Filename: wall.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for wall
 ** Date: 11/24/18
 * *************************************/
#include "wall.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Wall::Wall(){
	type = "W";
	armor = 4;
	position = 0;
	food_cost = 4;
	attack_value = 0;	
}

//Virtual function
void Wall::attack(Bug* targ){
}

void Wall::check_target(vector<Bug*>* board){
}


