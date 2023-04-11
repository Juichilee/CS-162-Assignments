#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include <string>
#include "tenant.h"
using namespace std;

class Citizen: public Tenant{

	public:
		//Constructor and Big 3
		
		Citizen();

		~Citizen();

		Citizen(const Citizen&);
		
		Citizen& operator=(const Citizen&);	
};
#endif
