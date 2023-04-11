/****************************************
 ** Program Filename: fire.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for fire
 ** Date: 11/24/18
 * *************************************/
#include "fire.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Fire::Fire(){
	type = "F";
	armor = 1;
	position = 0;
	food_cost = 4;
	attack_value = 3;	
}

//Virtual function
void Fire::attack(Bug* targ){
	cout << "Fire ant attacking" << endl;
}

void Fire::check_target(vector<Bug*>* board){
	bool detonate = false;
	for(int i = 0; i < board[position].size(); i++){
		if(board[position][i]->get_type() == "B"){
			attack(board[position][i]);
			detonate = true;
			break;	
		}
	}
	//Attack phase
	if(detonate){
		for(int j = 0; j < board[position].size(); j++){
			Bug* targ = board[position][j];
			targ->set_armor(targ->get_armor() - attack_value);
		}	
		armor = 0;
	}
}


