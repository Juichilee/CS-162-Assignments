#include <iostream>
#include <string>
#include "shape.h"
using namespace std;
		
//Accessors Mutators
string Shape::get_name(){
	return name;
}

string Shape::get_color(){
	return color;
}

void Shape::set_name(string a){
	name = a;
}

void Shape::set_color(string a){
	color = a;
}

//Constructor
Shape::Shape(string a, string b){
	name = a;
	
	color = b;
}

