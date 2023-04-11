/**************************************************
 * Program: main.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The main for assignment2
 *************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "restaurant.h"
#include "pizza.h"
#include "menu.h"

using namespace std;

int main(){

Restaurant* restaurant = new Restaurant();

restaurant->load_data();
bool quit = false;

while(!quit){
	cout << "\nWelcome to " << restaurant->get_name();
	cout << "\n=======================" << endl;

	cout << "Are you a customer(C) or employee(E) or would you like to quit(Q)?" << endl;
	string input;
	cin >> input;
	if(input == "C" || input == "c"){
		bool logout = false;
		while(logout != true){
			cout << endl;
			cout << "What would you like to do?" << endl;
			cout << "1. View Menu\n2. Search by Cost\n3. Search by Ingredients\n4. Place Order\n5. View Hours\n6. View Address\n7. View Phone \n8. Log out" << endl;
			int input2;
			cin >> input2;
	
			switch(input2){
				
				case 1:
					restaurant->view_menu();
					break;
				case 2:
					restaurant->search_menu_by_price();
					break;
				case 3:
					restaurant->search_by_ingredients();
					break;
				case 4: 
					restaurant->place_order();
					break;
				case 5:
					restaurant->view_hours();
					break;
				case 6: 
					restaurant->view_address();
					break;
				case 7: 
					restaurant->view_phone();
					break;
				
				default: 
					logout = true;
			}	
			restaurant->load_data();
		}

	}else if(input == "E" || input == "e"){
		bool login = false;
		bool logout2 = false;
		while(!login){
			string id, password;
			cout << "Please Enter your Company Issued ID" << endl;
			cin >> id;
			cout << "Please Enter your password" << endl;
			cin >> password;
			if(restaurant->login(id, password) == true){
				login = true;
			}else{
				string login2;
				cout << "Incorrect Login. (T to try again, Q to quit)" << endl;
				cin >> login2;
				if(login2 == "Q" || login2 == "q"){
					login = true;
					logout2 = true;	
				}
			}

		}

		while(logout2 != true){
			cout << endl;
			cout << "What would you like to do?" << endl;
			cout << "1. Change hours\n2. View Orders\n3. Remove Orders\n4. Add Item to Menu\n5. Remove Item from Menu\n6. View Menu\n7. View Hours\n8. View Address\n9. View Phone\n10. Log out" << endl;
			int input3;
			cin >> input3;
	
			switch(input3){
			
				case 1:
					restaurant->change_hours();	
					break;
				case 2:
					restaurant->view_orders();
					break;
				case 3:
					restaurant->remove_orders();
					break;
				case 4: 
					restaurant->add_to_menu();
					break;
				case 5:
					restaurant->remove_from_menu();
					break;
				case 6:
					restaurant->view_menu();
					break;
				case 7:
					restaurant->view_hours(); 
					break;
				case 8: 
					restaurant->view_address();
					break;
				case 9:
					restaurant->view_phone();
					break;
			
				default:
					logout2 = true;
			}
			restaurant->load_data();
		}

		
	}else{
		cout << "See you again soon!\n" << endl;
		quit = true;
	}
//	delete restaurant;
}
return 0;
}
