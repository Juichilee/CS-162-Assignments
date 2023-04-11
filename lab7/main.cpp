#include <iostream>
#include <string>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;

int main(){

Shape* shapes[2];

shapes[0] = new Circle("circle1","Red", 5);
shapes[1] = new Rectangle("rectangle1", "Blue", 4, 5);

for(int i = 0; i < 2; i++){
	shapes[i]->calculate_area();
}
for(int i = 0; i < 2; i++){
	delete shapes[i];
}

return 0;
}
