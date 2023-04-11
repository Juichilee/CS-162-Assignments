/****************************************
 ** Program Filename: sthrower.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for short thrower
 ** Date: 11/24/18
 * *************************************/
#include "sthrower.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Sthrower::Sthrower(){
	type = "sT";
	armor = 1;
	position = 0;
	food_cost = 3;
	attack_value = 1;	
}

//Virtual function
void Sthrower::attack(Bug* targ){
	cout << "Short thrower attacking" << endl;
	targ->set_armor(targ->get_armor() - attack_value);
}

void Sthrower::check_target(vector<Bug*>* board){
	int a = position-2; int b = position-1; int c = position+1; int d = position+2; 
	int targetpos[4] = {a, b, c, d}; //stores target positions
	bool bees = false;
	int target;
	for(int j = 0; j < 4; j++){
		if(bees == true){
			break;
		}else{
			if(targetpos[j] >= 0 && targetpos[j] < 10){
				for(int i = 0; i < board[targetpos[j]].size(); i++){
					if(board[targetpos[j]][i]->get_type() == "B"){
						bees = true;
						target = targetpos[j];
						break;
					}
				}
			}
		}
	}
	//Attack phase
	if(bees	== true){
		for(int s = 0; s < board[target].size(); s++){
			if(board[target][s]->get_type() == "B"){
				attack(board[target][s]);
			}
		}
	}
}


