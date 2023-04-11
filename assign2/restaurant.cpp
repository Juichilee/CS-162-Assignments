/**************************************************
 * Program: restaurant.cpp
 * Author: Juichi Lee
 * Date: 12/14/18
 * Description: The implementation for restaurant
 *************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "menu.h"
#include "restaurant.h"

using namespace std;

/****************************
 * Name: Restaurant(Menu*, employee*, int, hours*, string, string, string) 
 * Description: Constructor for the restaurant class.
 * **************************/
Restaurant::Restaurant(Menu* m, employee* e, int ne, hours* w, string n, string p, string a){
	menu = m;
	employees = e;
	num_employees = ne;
	week = w;
	phone = p;
	address = a;
	name = n;
}

/****************************
 * Name: Restaurant()
 * Description: Default constructor for restaurant class.
 * **************************/
Restaurant::Restaurant(){
	menu = NULL;
	employees = NULL;
	num_employees = 0;
	week = NULL;
	phone = "";
	address = "";
	name = "";
}

/****************************
 * Name: ~Restaurant() 
 * Description: Deconstructor for restaurant class.
 * **************************/
Restaurant::~Restaurant(){
	delete [] employees;
	employees = NULL;
	delete [] week;
	week = NULL;
	delete menu;
	menu = NULL;
	num_employees = 0;
}

/****************************
 * Name: Restaurant(const Restaurant&) 
 * Description: Copy constructor for restaurant class.
 * **************************/
Restaurant::Restaurant(const Restaurant& a){
	menu = new Menu();
	*menu = *(a.menu);
	employees = new employee[a.num_employees];
	for(int i = 0; i < a.num_employees; i++){
		employees[i] = a.employees[i];
	}
	week = new hours[7];
	for(int j = 0; j < 7; j++){
		week[j] = a.week[j];
	}
	phone = a.phone;
	address = a.address;
	name = a.name;
}

/****************************
 * Name: Restaurant::operator=(const Restaurant&)) 
 * Description: Assignment Overload operator for restaurant class.
 * **************************/
Restaurant& Restaurant::operator=(const Restaurant& a){
	if(this->employees != NULL){
		delete[] employees;
	}
	if(this->week != NULL){
		delete[] week;
	}
	if(this->menu != NULL){
		delete menu;
	}

	if(&a != this){
		menu = new Menu();
		*menu = *(a.menu);
		employees = new employee[a.num_employees];
		for(int i = 0; i < a.num_employees; i++){
			employees[i] = a.employees[i];
		}
		week = new hours[7];
		for(int j = 0; j < 7; j++){
			week[j] = a.week[j];
		}
		phone = a.phone;
		address = a.address;
		name = a.name;
	}
}

//Functions
/****************************
 * Name: load_data()
 * Description: Reads all the data from the txt files and assigns them to the proper member variables.
 * **************************/
void Restaurant::load_data(){
	fstream restaurant_in;
	restaurant_in.open("restaurant_info.txt");

	this->load_name_phone_address(restaurant_in); //Name, phone, and address
	
	this->load_week(restaurant_in);//Week	
	restaurant_in.close();

	//Employees
	fstream employee_in;
	employee_in.open("employee.txt");
	this->load_employees(employee_in);
	employee_in.close();
	
	//Menu
	fstream menu_in;
	menu_in.open("menu.txt");
	this->load_menu(menu_in);
	menu_in.close();
}

/****************************
 * Name: login(string, string)
 * Description: Returns a bool based whether the id and password match an id and password in the database.
 * **************************/
bool Restaurant::login(string id, string password){
	for(int i = 0; i < num_employees; i++){
		if(employees[i].id == id && employees[i].password == password){
			cout << "\nWelcome " << employees[i].first_name << " " << employees[i].last_name << endl;
			return true;			
		}
	} 	
	return false;
}

/****************************
 * Name: view_menu()
 * Description: Gets menu data from the member variables of the menu and ouputs it to the terminal.
 * **************************/
void Restaurant::view_menu(){
	cout << "PIZZA MENU" << "\n=======================" << endl;
	Pizza* pizzas = menu->get_pizzas();	
	int num_pizzas = menu->get_num_pizzas();	
	
	for(int i = 0; i < num_pizzas; i++){
		string* ingredients = pizzas[i].get_ingredients();
		cout << pizzas[i].get_name() <<" "<< pizzas[i].get_small_cost() <<" "<< pizzas[i].get_medium_cost() <<" "<< pizzas[i].get_large_cost() <<" "<< pizzas[i].get_num_ingredients();
		for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
			cout <<" "<< ingredients[j];
		}
		cout << "\n";
	}
}

/****************************
 * Name: write_to_menu()
 * Description: Takes the current menu and writes its data to the menu.txt.
 * **************************/
void Restaurant::write_to_menu(){
	ofstream out_menu("menu.txt");
	Pizza* pizzas = menu->get_pizzas();
	int num_pizzas = menu->get_num_pizzas();
	for(int i = 0; i < num_pizzas; i++){
		string* ingredients = pizzas[i].get_ingredients();
		out_menu<< pizzas[i].get_name() <<" "<< pizzas[i].get_small_cost() <<" "<< pizzas[i].get_medium_cost() <<" "<< pizzas[i].get_large_cost() <<" "<< pizzas[i].get_num_ingredients();
		for(int j = 0; j < pizzas[i].get_num_ingredients(); j++){
			out_menu <<" "<< ingredients[j];
		}
		out_menu << "\n";
	}
	out_menu.close();
}

/****************************
 * Name: view_hours() 
 * Description: Prints the current week.
 * **************************/
void Restaurant::view_hours(){
	cout << "HOURS (AM-PM)" << "\n=======================" << endl;
	hours* week = this->get_week();	

	for(int i = 0; i < 7; i++){
		cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;	
	}
}

/****************************
 * Name: view_address() 
 * Description: Prints the current address.
 * **************************/
void Restaurant::view_address(){
	cout << "Address" << "\n=======================" << endl;
	cout << address << endl;
}

/****************************
 * Name: view_phone() 
 * Description: Prints the current phone number.
 ****************************/
void Restaurant::view_phone(){
	cout << "Phone number" << "\n=======================" << endl;
	cout << phone << endl;
}

/****************************
 * Name: search_menu_by_price() 
 * Description: Searches the menu using upperbound cost and size of pizza. Returns a menu of pizzas that fit the parameters and asks the user if they want to place an order.
 * **************************/
void Restaurant::search_menu_by_price(){
	string input1, input2;
	getline(cin,input1);
	cout << "Enter upperbound cost of pizza(Q to quit)" << endl;
	getline(cin, input1);
	cout << "Enter desired size(S, M, L)(Defaulted to L)" << endl;
	getline(cin, input2);
	int input3 = stringtoint(input1);
	if(input3 == 0){
		cout << "Quitting" << endl;
	}else{
		Menu search_menu = menu->search_pizza_by_cost(input3, input2);	
		Restaurant* restaurant2(this);
		restaurant2->set_menu(&search_menu);
		restaurant2->view_menu();
		cout << "\nWould you like to place an order from your search?(Y/N)" << endl;
		getline(cin, input1);
		if(input1 == "Y" || input1 == "y"){
			restaurant2->place_order();
		}else{
			cout << "Quitting" << endl;
		}
	}
	
}

/****************************
 * Name: search_by_ingredients() 
 * Description: Searches the menu based on inputted ingredients to include or exclude. Returns a menu of pizzas that fit the parameters and asks the user if they want to place an order.
 * **************************/
void Restaurant::search_by_ingredients(){
	string input;
	getline(cin, input);
	Restaurant* restaurant2(this);
	cout << "Would you like to search for ingredients you want to include(I) or exclude(E)?(Q to quit)" << endl;
	getline(cin, input);
	if(input == "I" || input == "i"){
		Menu include_menu = menu->search_pizza_by_ingredients_to_include();
		cout << "Here are the pizzas we found" << endl;
		restaurant2->set_menu(&include_menu);
		restaurant2->view_menu();
		cout << "\nWould you like to place an order based on your search?(Y/N)" << endl;
		getline(cin, input);
		if(input == "Y" || input == "y"){
			restaurant2->place_order();
		}else{
			cout << "Quitting" << endl;
		}	
	}else if(input == "E" || input == "e"){
		Menu exclude_menu = menu->search_pizza_by_ingredients_to_exclude();
		cout << "Here are the pizzas we found" << endl;
		restaurant2->set_menu(&exclude_menu);
		restaurant2->view_menu();
		cout << "\nWould you like to place an order based on your search?(Y/N)" << endl;
		getline(cin, input);
		if(input == "Y" || input == "y"){
			restaurant2->place_order();
		}else{
			cout << "Quitting" << endl;
		}		
	}else{
		cout << "Quitting" << endl;
	}

}

/****************************
 * Name: place_order() 
 * Description: Places an order to the order.txt based on the line number of a pizza on the menu of the restaurant.
 * **************************/
void Restaurant::place_order(){
	this->view_menu();
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\nInsert line number of desired pizza ('Q' to quit)" << endl;
		cin >> input;
		if(input == "Q" || input == "q"){
			valid_input = true;
		}else{
			int s = atoi(input.c_str());
			if(s != 0 && s <= menu->get_num_pizzas()){
				Pizza* pizzas = menu->get_pizzas();
				this->place_order(&(pizzas[s-1]));
				valid_input = true;
			}else{
				cout << "Not valid. Please input valid choice" << endl;
			}
		}
	}
}

/****************************
 * Name: place_order(Pizza*) 
 * Description: Overloaded method of place_order. Takes the pizza selection in the argument and creates the order, prompting the user some information. Assigns complete order to order.txt.
 * **************************/
void Restaurant::place_order(Pizza* selection){
	fstream orders_in;
	orders_in.open("orders.txt");
	string line;
	int num_orders = 0;	
	while(getline(orders_in, line)){
		num_orders++;
	}
	orders_in.close();
	ofstream orders_out("orders.txt", ios::app);
	int order_num = num_orders+1;
	string c_name1, c_name2, CC, c_address, c_phone, c_size, c_quantity;
	getline(cin, c_name1);
	cout << "What is your name?" << endl;
	getline(cin, c_name2);
	cout << "What is your CC?" << endl;
	getline(cin, CC);
	cout << "What is your address?" << endl;
	getline(cin, c_address);
	cout << "What is your phone?" << endl;
	getline(cin, c_phone);
	cout << "What size pizza?(S, M, L)" << endl;
	getline(cin, c_size);
	cout << "Quantity of selected pizza?" << endl;		
	getline(cin, c_quantity);
	string order = c_name2+" "+CC+" "+c_address+" "+c_phone+" "+selection->get_name()+" "+c_size+" "+c_quantity;
	cout << "Order placed: " << order << endl;
	orders_out << order_num << " " << order << endl;
	orders_out.close();
}	

/****************************
 * Name: change_hours() 
 * Description: Changes the hours in the week. Prompts the user to select a day to change and then prompts them to change the opening and closing hour. Writes the changes to the restaurant_info.txt file.
 * **************************/
void Restaurant::change_hours(){
	string input;
	getline(cin, input);
	int index = 0;
	cout << "Select a day (S,M,T,W,R,F,Sa)" << endl;
	getline(cin, input);
	if(input == "S" || input == "s"){
		index = 0;
	}else if(input == "M" || input == "m"){
		index = 1;
	}else if(input == "T" || input == "t"){
		index = 2;
	}else if(input == "W" || input == "w"){
		index = 3;
	}else if(input == "R" || input == "r"){
		index = 4;
	}else if(input == "F" || input == "f"){
		index = 5;
	}else if(input == "Sa" || input == "SA" || input == "sa"){
		index = 6;
	}else{
		cout << "Defaulted to Sunday" << endl;
		index = 0;
	}
	cout << "Enter new opening hour" << endl;
	getline(cin, input);
	week[index].open_hour = input;
	cout << "Enter new closing hour" << endl;
	getline(cin, input);
	week[index].close_hour = input;
	ofstream info("restaurant_info.txt");
	info << name << endl;
	info << phone << endl;
	info << address << endl;
	info << "7" << endl;
	for(int i = 0; i < 7; i++){
		info << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
	}
	cout << "Changes to hours successfully made" << endl;
}

/****************************
 * Name: stringtoint(string)
 * Description: Takes a string and casts it into an int.
 * **************************/
int Restaurant::stringtoint(string s){
	return atoi(s.c_str());
}

/****************************
 * Name: add_to_menu() 
 * Description: Prompts the user with parameters to create the pizza. Writes the created pizza to the menu.txt file. 
 * **************************/
void Restaurant::add_to_menu(){
	bool valid_input = false;
	string line, p_name, p_small_cost, p_medium_cost, p_large_cost, p_num_ingredients;
	int small_cost, medium_cost, large_cost, num_ingredients;
	getline(cin, line);
	while(!valid_input){	
		cout << "Pizza name" << endl;
		getline(cin, p_name);
		cout << "Small cost" << endl;
		getline(cin, p_small_cost);
		cout << "Medium cost" << endl;
		getline(cin, p_medium_cost);
		cout << "Large cost" << endl;
		getline(cin, p_large_cost);
		cout << "Number of ingredients" << endl;
		getline(cin, p_num_ingredients);
		small_cost = stringtoint(p_small_cost); medium_cost = stringtoint(p_medium_cost); large_cost = stringtoint(p_large_cost); num_ingredients = stringtoint(p_num_ingredients);
		if(small_cost != 0 && medium_cost != 0 && large_cost != 0 && num_ingredients != 0){
			valid_input = true;
		}else{
			cout << "Costs and number of ingredients must be integers" << endl;
		}
	}
	string* p_ingredients = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++){
		string ingredient;
		cout << "Insert ingredient" << endl;
		getline(cin, ingredient);
		p_ingredients[i] = ingredient;
	}

	Pizza* add_pizza = new Pizza(p_name, small_cost, medium_cost, large_cost, num_ingredients, p_ingredients);
	int num_pizzas = menu->get_num_pizzas();
	Pizza* new_pizzas = new Pizza[num_pizzas + 1];
	Pizza* pizzas = menu->get_pizzas();
	for(int j = 0; j < num_pizzas; j++){
		new_pizzas[j] = pizzas[j];
	}	
	new_pizzas[num_pizzas] = *add_pizza;
	pizzas = new_pizzas;
	menu->set_num_pizzas(num_pizzas + 1);
	ofstream menu_out("menu.txt", ios::app);
	menu_out << p_name <<" "<< small_cost <<" "<< medium_cost <<" "<< large_cost << " "<< num_ingredients;
	for(int s = 0; s < num_ingredients; s++){
		menu_out << " " << p_ingredients[s];
	}
	menu_out << "\n";
	cout << "Successfully Added Pizza" << endl;
}

/****************************
 * Name: remove_from_menu() 
 * Description: Prompts the user to input the line of pizza they wish to remove. Removes pizza from the menu and writes the changes to the menu.txt file.
 * **************************/
void Restaurant::remove_from_menu(){
	string input;
	this->view_menu();
	getline(cin, input);
	cout << "\nEnter the line of the pizza you wish to remove(Type 0 to quit)" << endl;
	getline(cin, input);
	int line = stringtoint(input);
	if(line != 0){
		menu->remove_from_menu(line-1);
		write_to_menu();
		cout << "Successfully Removed Pizza" << endl;
	}else{
		cout <<"Quitting"<< endl;
	}
}

/****************************
 * Name: view_orders() 
 * Description: Prints the orders from the orders.txt file.
 * **************************/
void Restaurant::view_orders(){
	fstream orders;
	orders.open("orders.txt");
	string line;
	cout << "Orders" << "\n=======================" << endl;
	while(getline(orders, line)){
		cout << line << endl;
	}
	orders.close();
}

/****************************
 * Name: remove_orders() 
 * Description: Removes all the orders fro the orders.txt file.
 * **************************/
void Restaurant::remove_orders(){
	ofstream orders_out("orders.txt");
	orders_out << "";
	orders_out.close();
	cout << "Orders Removed" << endl;
}

/****************************
 * Name: load_menu(fstream&) 
 * Description: Loads the data from the menu.txt file into the restaurant.
 * **************************/
void Restaurant::load_menu(fstream& menu_in){
	string line2;
	int num_pizzas = 0;	
	while(getline(menu_in, line2)){
		num_pizzas++;
	}	
	menu_in.close();
	menu_in.open("menu.txt");
	//if(this->menu != NULL) delete [] this->menu;
	Menu* menu = new Menu();
	//if(menu->get_pizzas() != NULL) menu->set_pizzas(NULL);
	Pizza* pizzas = new Pizza[num_pizzas];
	menu->set_num_pizzas(num_pizzas);
	string p_name;
	int small_cost = 0;
	int medium_cost = 0;
	int large_cost = 0;
	int num_ingredients = 0;
	string* ingredients;
	for(int j = 0; j < num_pizzas; j++){
		menu_in >> p_name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
		pizzas[j].set_name(p_name);
		pizzas[j].set_small_cost(small_cost);
		pizzas[j].set_medium_cost(medium_cost);
		pizzas[j].set_large_cost(large_cost);
		pizzas[j].set_num_ingredients(num_ingredients);
		ingredients = new string[num_ingredients];
		for(int h = 0; h < num_ingredients; h++){
			menu_in >> ingredients[h];
		} 
		pizzas[j].set_ingredients(ingredients);
	}
	menu->set_num_pizzas(num_pizzas);
	menu->set_pizzas(pizzas);
	this->set_menu(menu);
	
	//delete [] ingredients;
	//delete [] pizzas;
	//delete menu;
}

/****************************
 * Name: load_employees(fstream&) 
 * Description: Loads the data from the employees.txt file into the restaurant.
 * **************************/
void Restaurant::load_employees(fstream& employee_in){
	string line;
	int num_employees = 0;
	while(getline(employee_in, line)){
		num_employees++;
	}
	this->num_employees = num_employees;
	employee_in.close();
	employee_in.open("employee.txt");
	//if(this->employees != NULL) delete [] this->employees;
	employee* l_employees = new employee[num_employees];
	for(int s = 0; s < num_employees; s++){
		employee_in >> l_employees[s].id >> l_employees[s].first_name >> l_employees[s].last_name >> l_employees[s].password;
	}	
	this->employees = l_employees;
	//delete [] l_employees;
}

/****************************
 * Name: load_week(fstream&)
 * Description: Loads the data from the restaurant_info.txt file into the restaurant.
 * **************************/
void Restaurant::load_week(fstream& restaurant_in){
	int num_days = 0;
	restaurant_in >> num_days;
	//if(this->week != NULL) delete []this->week;
	hours* l_week = new hours[num_days];
	for(int i = 0; i < num_days; i++){
		restaurant_in >> l_week[i].day >> l_week[i].open_hour >> l_week[i].close_hour;
	}
	this->week = l_week;
	//delete [] l_week;
}

/****************************
 * Name: load_name_phone_address(fstream&) 
 * Description: Loads the data from the restaurant_info.txt file into the restaurant.
 * **************************/
void Restaurant::load_name_phone_address(fstream& restaurant_in){
	string l_name;
	string l_phone;
	string l_address;	
	getline(restaurant_in, l_name);
	getline(restaurant_in, l_phone);
	getline(restaurant_in, l_address);
	this->name = l_name;
	this->phone = l_phone;
	this->address = l_address;

}

//Accessors Mutators
void Restaurant::set_menu(Menu* new_menu){
	menu = new_menu;
}
void Restaurant::set_employees(employee* new_employees){
	employees = new_employees;
}
void Restaurant::set_week(hours* new_week){
	week = new_week;
}
void Restaurant::set_name(string new_name){
	name = new_name;
}
void Restaurant::set_phone(string new_phone){
	phone = new_phone;
}
void Restaurant::set_address(string new_address){
	address = new_address;
}
void Restaurant::set_num_employees(int new_employees){
	num_employees = new_employees;
}
Menu* Restaurant::get_menu(){
	return menu;
}
employee* Restaurant::get_employees(){
	return employees;
}
int Restaurant::get_num_employees(){
	return num_employees;
}
hours* Restaurant::get_week(){
	return week;
}
string Restaurant::get_name(){
	return name;
}
string Restaurant::get_phone(){
	return phone;
}
string Restaurant::get_address(){
	return address;
}

