#include <iostream>
#include <string>
#include "rectangle.h"
using namespace std;

//Functions
void Rectangle::calculate_area(){
	cout << "Rectangle Area: " << length * width << endl;
}

//Accessors Mutators
int Rectangle::get_length(){
	return length;
}
void Rectangle::set_length(int a){
	length = a;
}

int Rectangle::get_width(){
	return width;
}
void Rectangle::set_width(int a){
	width = a;
}

//Constructor
Rectangle::Rectangle(string a, string b, int l, int w):Shape(a, b){
	name = a;
	color = b;
	length = l;
	width = w;
}

