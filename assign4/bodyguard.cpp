/****************************************
 ** Program Filename: bodyguard.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for bodyguard
 ** Date: 11/24/18
 * *************************************/
#include "bodyguard.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Bodyguard::Bodyguard(){
	type = "Bg";
	armor = 2;
	position = 0;
	food_cost = 4;
	attack_value = 0;	
}

//Virtual function
void Bodyguard::attack(Bug* targ){
	cout << "Bodyguard attacking" << endl;
}

void Bodyguard::check_target(vector<Bug*>* board){

}


