/**************************************************
 * Program: menu.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The implementation for menu
 *************************************************/

#include <iostream>
#include <string>
#include "menu.h"
#include "restaurant.h"

/****************************
 * Name: Menu(int , Pizza*)
 * Description: Constructor for menu class.
 * **************************/
Menu::Menu(int num_p, Pizza* p){
	num_pizzas = num_p;
	pizzas = p;
}

/****************************
 * Name: Menu()
 * Description: Default constructor for menu class.
 * **************************/
Menu::Menu(){
	num_pizzas = 0;
	pizzas = NULL;
}

/****************************
 * Name: ~Menu() 
 * Description: Deconstructor for menu class.
 * **************************/
Menu::~Menu(){
	
	delete [] pizzas;
	pizzas = NULL;	
}

/****************************
 * Name: Menu(const Menu&)
 * Description: Copy constructor for menu class.
 * **************************/
Menu::Menu(const Menu& a){

	num_pizzas = a.num_pizzas;

	pizzas = new Pizza[a.num_pizzas];

	std::copy(a.pizzas, a.pizzas + num_pizzas, pizzas);

}

/****************************
 * Name: Menu::operator=(const Menu&) 
 * Description: Assignment overload operator for menu class.
 * **************************/
Menu& Menu::operator =(const Menu& a){

	if(&a != this){

		num_pizzas = a.num_pizzas;

		delete [] pizzas;

		pizzas = new Pizza[a.num_pizzas];

		std::copy(a.pizzas, a.pizzas + num_pizzas, pizzas);

	}	
	return *this;
}

//Functions
/****************************
 * Name: search_pizza_by_cost(int, string) 
 * Description: Searches for pizzas based on the cost and size of pizza. Returns a menu with the searched pizzas.
 * **************************/
Menu Menu::search_pizza_by_cost(int upper_bound, string size){
	Menu* search_menu(this);
	Pizza* search_pizzas = search_menu->get_pizzas();

	if(size == "S" || size == "s"){
		for(int j = num_pizzas-1; j >= 0; j--){
			if(search_pizzas[j].get_small_cost() > upper_bound){
				search_menu->remove_from_menu(j);
			}
		}
		
	}else if(size == "M" || size == "m"){
		for(int s = num_pizzas-1; s >= 0; s--){
			if(search_pizzas[s].get_medium_cost() > upper_bound){
				search_menu->remove_from_menu(s);
			}
		}
	}else{
		for(int i = num_pizzas-1; i >= 0; i--){
			if(search_pizzas[i].get_large_cost() > upper_bound){
				search_menu->remove_from_menu(i);
			}
		}

	}
	return *search_menu;
}

/****************************
 * Name: search_pizza_by_ingredients_to_include() 
 * Description: Searches for pizzas by ingredients to include. Returns a menu with searched pizzas.
 * **************************/
Menu Menu::search_pizza_by_ingredients_to_include(){
	string input;
	Menu* search_menu = new Menu();
	bool finish_search = false;
	while(!finish_search){
		cout << "What item would you like to include?" << endl;	
		getline(cin, input);
		for(int i = 0; i < this->get_num_pizzas(); i++){	
			string* ingredients = pizzas[i].get_ingredients();
			for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
				if(ingredients[j] == input){
					search_menu->add_to_menu(pizzas[i]);
				}
			}
		}

		cout <<	"Do you want to include another item?(Y/N)" << endl;
		getline(cin, input);
		if(input == "N" || input == "n"){
			finish_search = true;
		}
	}
	return *search_menu;
}

/****************************
 * Name: search_pizza_by_ingredients_to_exclude() 
 * Description: Searches for pizzas by ingredients to exclude. Returns a menu with searched pizzas.
 * **************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(){
	string input;
	Menu* search_menu(this);
	bool finish_search = false;
	while(!finish_search){
		cout << "What item would you like to exclude?" << endl;	
		getline(cin, input);
		for(int i = this->get_num_pizzas()-1; i >= 0; i--){	
			string* ingredients = pizzas[i].get_ingredients();
			for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
				if(ingredients[j] == input){
					search_menu->remove_from_menu(i);
					break;
				}
			}
		}

		cout <<	"Do you want to exclude another item?(Y/N)" << endl;
		getline(cin, input);
		if(input == "N" || input == "n"){
			finish_search = true;
		}
	}
	return *search_menu;
}

/****************************
 * Name: add_to_menu(Pizza) 
 * Description: Adds the selected pizza to the current menu. 
 * **************************/
void Menu::add_to_menu(Pizza pizza_to_add){
	int new_num_pizzas = 1 + this->get_num_pizzas();
	Pizza* new_pizzas = new Pizza[new_num_pizzas];
	for(int i = 0; i < num_pizzas; i++){
		new_pizzas[i] = pizzas[i];
	}
	new_pizzas[num_pizzas] = pizza_to_add;
	set_num_pizzas(new_num_pizzas);
	set_pizzas(new_pizzas);
}

/****************************
 * Name: remove_from_menu(int) 
 * Description: Removes the selected pizza from the current menu.
 * **************************/
void Menu::remove_from_menu(int index_of_pizza_on_menu){
	int new_num_pizzas = num_pizzas-1;
	Pizza* new_pizzas = new Pizza[new_num_pizzas];
	for(int i = 0; i < new_num_pizzas; i++){
		
		if(i >= index_of_pizza_on_menu){
			new_pizzas[i] = pizzas[i+1];	
		}else{
			new_pizzas[i] = pizzas[i];
		}
	}
	num_pizzas = num_pizzas-1;
	pizzas = new_pizzas;
}

//Accessors Mutators
int Menu::get_num_pizzas(){
	return num_pizzas;
}
	
Pizza* Menu::get_pizzas(){
	return pizzas;
}

void Menu::set_num_pizzas(int new_num_pizzas){
	num_pizzas = new_num_pizzas;
}

void Menu::set_pizzas(Pizza* new_pizzas){
	pizzas = new_pizzas;
}		

