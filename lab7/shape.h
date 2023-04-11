#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;

class Shape{
	protected:
		string name;
		string color;
	public:
		//Accessors Mutators
		string get_name();
		string get_color();
		void set_name(string);
		void set_color(string);
		//Constructor
		Shape(string, string);
		//Virtual function
		virtual void calculate_area() = 0;

};




#endif
