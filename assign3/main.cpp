/**************************************************
 * Program: main.cpp
 * Author: Juichi Lee
 * Date: 11/11/18
 * Description: The main for assignment3
 *************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "tycoon.h"
using namespace std;

int main(){
	srand(time(NULL));
	cout << "Welcome to Tycoon Real Estate Simulator 2018!" << endl;
	bool end = false;
	Tycoon t1;
	int turn_count;
	while(!end){
		int balance = t1.get_balance();
		if(balance == 1000000 || balance == 0){
			if(balance == 1000000){
				cout << "You Win!!" << endl;
			}else{
				cout << "You Lose!!" << endl;
			}
			break;
		}

		cout << "Current Balance: $" << t1.get_balance() << endl;
		t1.action();
		t1.pay_mortgage();
		if(turn_count%12 == 0){
			t1.pay_tax();
		}	
		t1.random_event();
		turn_count++;
	}
/*
	cout << "Set Rent" << endl;
	h1.set_rent();
	cout << "Payment: "<< h1.collect_rent() << endl; 
	h1.print();
*/


return 0;
}
/*
	Tycoon t1;
	cout << t1.get_balance() << endl;
	cout << t1.get_num_properties() << endl;

	cout << "House" << endl;
	House h1;
	h1.print();
	h1.remove_tenant();
	cout << "NEW" << endl;
	h1.print();
		
	cout << "\nApartments" << endl;	
	ApartmentComplex ap1;
	ap1.print();	
	ap1.remove_tenant(1);
	cout << "NEW" << endl;
	ap1.print();	
	ap1.remove_tenant(3);
	cout << "NEW" << endl;
	ap1.print();
	
	cout << "\nBusiness Complex" << endl;
	BusinessComplex bc1;
	bc1.print();
	bc1.remove_tenant(1);
	cout << "NEW" << endl;
	bc1.print();
*/
