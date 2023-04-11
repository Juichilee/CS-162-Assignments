#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include "shape.h"
using namespace std;

class Rectangle:public Shape{
	private:
		int length;
		int width;
	public:
		//Accessors Mutators
		int get_length();
		void set_length(int);
		int get_width();
		void set_width(int);

		//Constructor
		Rectangle(string, string, int, int);
		//Functions
		virtual void calculate_area();
};




#endif
