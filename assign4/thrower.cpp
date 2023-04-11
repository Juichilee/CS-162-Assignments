/****************************************
 ** Program Filename: thrower.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for thrower
 ** Date: 11/24/18
 * *************************************/
#include "thrower.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Thrower::Thrower(){
	type = "T";
	armor = 1;
	position = 0;
	food_cost = 4;
	attack_value = 1;	
}

//Virtual function
void Thrower::attack(Bug* targ){
	cout << "Thrower attacking" << endl;
	targ->set_armor(targ->get_armor() - attack_value);
}

void Thrower::check_target(vector<Bug*>* board){
	for(int i = 0; i < board[position].size(); i++){
		if(board[position][i]->get_type() == "B"){
			attack(board[position][i]);
			break;	
		}
	}
}


