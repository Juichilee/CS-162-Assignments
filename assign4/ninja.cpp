/****************************************
 ** Program Filename: ninja.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for ninja
 ** Date: 11/24/18
 * *************************************/
#include "ninja.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Ninja::Ninja(){
	type = "N";
	armor = 1;
	position = 0;
	food_cost = 6;
	attack_value = 1;	
}

//Virtual function
void Ninja::attack(Bug* targ){
	cout << "Ninja attacking" << endl;
}

void Ninja::check_target(vector<Bug*>* board){
	bool assassinate = false;
	for(int i = 0; i < board[position].size(); i++){
		if(board[position][i]->get_type() == "B"){
			attack(board[position][i]);
			assassinate = true;
			break;	
		}
	}
	//Attack phase
	if(assassinate){
		for(int j = 0; j < board[position].size(); j++){
			if(board[position][j]->get_type() == "B"){
				Bug* targ = board[position][j];
				targ->set_armor(targ->get_armor() - attack_value);
			}
		}	
	}
}


