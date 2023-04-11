#include <iostream>
#include <string>
#include "circle.h"
using namespace std;

//Functions
void Circle::calculate_area(){
	cout << "Circle Radius: "<< 3.14*radius*radius << endl;
}


//Accessors Mutators
int Circle::get_radius(){
	return radius;
}
void Circle::set_radius(int a){
	radius = a;
}

//Constructor
Circle::Circle(string a, string b, int c):Shape(a, b){
	name = a;
	color = b;
	radius = c;
}


