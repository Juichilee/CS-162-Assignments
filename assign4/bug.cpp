/****************************************
 ** Program Filename: bug.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for bug
 ** Date: 11/24/18
 * *************************************/
#include <iostream>
#include <string>
#include "bug.h"

//Accessors Mutators
int Bug::get_armor(){
	return armor;
}
string Bug::get_type(){
	return type;
}
int Bug::get_position(){
	return position;
}
	
int Bug::get_attack_value(){
	return attack_value;
}

void Bug::set_armor(int a){
	armor = a;
}
void Bug::set_type(string a){
	type = a;
}
void Bug::set_position(int a){
	position = a;
}

void Bug::set_attack_value(int a){
	attack_value = a;
}

//Constructor
Bug::Bug(){
	type = "Bug";
	armor = 1;
	position = 0;
}

