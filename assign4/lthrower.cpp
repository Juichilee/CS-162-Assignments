/****************************************
 ** Program Filename: lthrower.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for long thrower
 ** Date: 11/24/18
 * *************************************/
#include "lthrower.h"
#include "ant.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Lthrower::Lthrower(){
	type = "lT";
	armor = 1;
	position = 0;
	food_cost = 4;
	attack_value = 1;	
}

//Virtual function
void Lthrower::attack(Bug* targ){
	cout << "Long thrower attacking" << endl;
	targ->set_armor(targ->get_armor() - attack_value);
}

void Lthrower::check_target(vector<Bug*>* board){
	vector<int> targetpos;
	for(int l = 0; l < 10; l++){
		if(position - l >= 4 || position - l <= -4){
			targetpos.push_back(l); //Stores target positions
		}
	}
	bool bees = false;
	int target;
	for(int j = 0; j < targetpos.size(); j++){
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


