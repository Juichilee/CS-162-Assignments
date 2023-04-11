/****************************************
 ** Program Filename: bee.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for bee
 ** Date: 11/24/18
 * *************************************/
#include <iostream>
#include <string>
#include "bee.h"
#include "bug.h"

using namespace std;

//Functions
void Bee::move(){
	position += 1;
}

//Constructor
Bee::Bee(){
	type = "B";
	armor = 3;
	position = 9;
	attack_value = 1;
}

//Virtual function
void Bee::check_target(vector<Bug*>*){
}

void Bee::attack(Bug* targ){
	cout << "Bee attacking" << endl;
	targ->set_armor(targ->get_armor() - attack_value);
	
}
