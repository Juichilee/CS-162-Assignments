#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "shape.h"
using namespace std;

class Circle:public Shape{
	private:
		int radius;
	public:
		//Accessors Mutators
		int get_radius();
		void set_radius(int);
		
		//Constructor
		Circle(string, string, int);
		
		//Functions
		virtual void calculate_area();
};




#endif
