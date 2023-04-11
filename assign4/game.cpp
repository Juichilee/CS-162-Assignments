/****************************************
 ** Program Filename: game.cpp
 ** Author: Juichi Lee
 ** Description: .cpp file for game
 ** Date: 11/24/18
 * *************************************/
#include <iostream>
#include <string>
#include "game.h"

using namespace std;

//Functions
//Bee Functions
/****************************************
 ** Function name: bee_action(Bug*)
 ** Description: Executes bee_move.
 * *************************************/
void Game::bee_action(Bug* c_bee){
	bee_move(c_bee);
}

/****************************************
 ** Function name: bee_move(Bug*)
 ** Description: Move all bees in a space if there are no ants blocking them.
 * *************************************/
void Game::bee_move(Bug* c_bee){
	int i = 0;
	int position = c_bee->get_position();
	bool no_ants = true;
	Bug* target; //Store ant target pointer 
	for(i = 0; i < board[position].size(); i++){		
		if(board[position][i]->get_type() != "B"){ //Cannot detect ninjas
			if(board[position][i]->get_type() != "N"){
				no_ants = false;
				target = board[position][i]; //Ant target
			}else{
				no_ants = true;
			}
		}
		if(board[position][i]->get_type() == "Bg"){
			no_ants = false;
			target = board[position][i]; //Bodyguard taunt
			break;
		}
	}
	if(no_ants){
		for(i = board[position].size()-1; i >= 0; i--){
			if(board[position][i]->get_type() != "N"){
				board[position][i]->set_position(position-1);
				board[position-1].push_back(board[position][i]);
				board[position].erase(board[position].begin()+i);
			}
		}
	}else{
		c_bee->attack(target);	
	}
}

/****************************************
 ** Function name: ant_action(Bug*)
 ** Description: Executes ant actions, mainly check target and attack. Undergoes polymorphism.
 * *************************************/
//Ant Functions
void Game::ant_action(Bug* c_ant){
	if(c_ant->get_type() == "H"){
		cout << "Harvester harvesting" << endl;
		set_num_food(get_num_food()+1);
	}else{
		c_ant->check_target(board);
	}
}

/****************************************
 ** Function name: check_space_ants(int)
 ** Description: Checks space in position for ants. Returns true if there are ants, false if there are no ants.
 * *************************************/
bool Game::check_space_ants(int position){
	bool ants = false;
	for(int i = 0; i < board[position].size(); i++){
		if(board[position][i]->get_type() != "B"){
			return true;
		}
	}
	return ants;
}

/****************************************
 ** Function name: add_ant(Ant*)
 ** Description: adds selected ant to the board. Doesn't allow new ant placement into spaces that already have ants. Bodyguard is the exception. Subtracts ants food cost from food supply. 
 * *************************************/
void Game::add_ant(Ant* new_ant){
	if(num_food >= new_ant->get_food_cost()){
		string input;
		bool valid_input = false;
		while(!valid_input){
			print_numbered_b();
			cout << "\nWhere would you like to place the new ant?(enter position 2-9)" << endl;
			cin >> input;
			int s = atoi(input.c_str());
			if(s > 1 && s <= 9 ){
				if(check_space_ants(s-1) && new_ant->get_type() != "Bg"){ //Bodyguard exception
					cout << "Only one ant per space (exception bodyguards)" << endl;
				}else{
					add_bug(new_ant, s-1);
					num_food -= new_ant->get_food_cost();
					valid_input = true;
				}
			}else{
				cout << "Not valid position. Please input valid position" << endl;
			}
		}
	}else{
		cout << "Not enough food to create unit" << endl;
		delete new_ant;
	}
}

/****************************************
 ** Function name: remove_dead()
 ** Description: Removes all dead bugs with armors less than or equal to 0.
 * *************************************/
//Generic Functions
void Game::remove_dead(){
	
	for(int i = 0; i < board_size; i++){  //Iterates over entire board from left to right
		for(int j = board[i].size()-1; j >= 0; j--){ //older bugs have priority
			if(board[i][j]->get_armor() <= 0){
				cout << board[i][j]->get_type() << " died" << endl;
				delete board[i][j];
				board[i].erase(remove(board[i].begin(), board[i].end(), board[i][j]), board[i].end());
			}			
		}
	}	
}

/****************************************
 ** Function name: choose_unit()
 ** Description: Allows player to choose a unit to add to the board.
 * *************************************/
void Game::choose_unit(){
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\n       [Food: " << num_food << "]" << endl;
		cout << "Which ant would you like to create?(enter line#)('Q' to quit)" << endl;
		cout << "1. Harvester (cost: 2)\n2. Thrower (cost: 4)\n3. Fire (cost:4)\n4. Long Thrower (cost 3)\n5. Short Thrower (cost 3)\n6. Wall (cost 4)\n7. Ninja (cost 6)\n8. Bodyguard (cost 4)" << endl; 
		cin >> input;
		if(input == "q" || input == "Q"){
			valid_input = true;
		}else{
			int s = atoi(input.c_str());
			if(s > 0 && s <= 8){
				switch(s){
					case 1: add_ant(new Harvester());
						valid_input = true;
						break;

					case 2: add_ant(new Thrower());
						valid_input = true;
						break;

					case 3: add_ant(new Fire());	
						valid_input = true;
						break;

					case 4: add_ant(new Lthrower());
						valid_input = true;
						break;
						
					case 5: add_ant(new Sthrower());
						valid_input = true;
						break;

					case 6: add_ant(new Wall());
						valid_input = true;
						break;
	
					case 7: add_ant(new Ninja());
						valid_input = true;
						break;

					case 8: add_ant(new Bodyguard());
						valid_input = true;
						break;

				}
			}else{
				cout << "Not valid. Please input valid choice" << endl;
			}
		}
	}
}

/****************************************
 ** Function name: player_action()
 ** Description: Prompts the player with actions they can take in a turn, mainly creating a new ant on the board, or continuing to the next turn.
 * *************************************/
void Game::player_action(){
	string input;
	bool valid_input = false;
	while(!valid_input){
		cout << "\nWhat would you like to do? (enter line#)" << endl;
		cout << "1. Create new ant\n2. Next turn" << endl; 
		cin >> input;
		int s = atoi(input.c_str());
		if(s > 0 && s <= 2){
			switch(s){
				case 1:
					choose_unit();
					valid_input = true;
					break;
				case 2: 
					valid_input = true;
					break;
			}
		}else{
			cout << "Not valid. Please input valid choice" << endl;
		}
	}
}

/****************************************
 ** Function name: generate_bee()
 ** Description: Generates a new bee on the 10th square.
 * *************************************/
void Game::generate_bee(){
	Bee* n_bee = new Bee();
	board[board_size-1].push_back(n_bee);
	n_bee->set_position(board_size-1);
	cout << "Generated New Bee" << endl;
}

/****************************************
 ** Function name: action()
 ** Description: Loops over board from left to right, executing each bug in each space's action.
 * *************************************/
void Game::action(){
	int i = 0;
	for(i = 0; i < board_size; i++){  //Iterates over entire board from left to right
		for(int j = 0; j < board[i].size(); j++){ //older bugs have priority
			if(board[i][j]->get_type() == "B"){		
				bee_action(board[i][j]);
			}else{
				ant_action(board[i][j]);
			}	
		}
	}	
} 

/****************************************
 ** Function name: add_bug(Bug*, position)
 ** Description: Adds a bug to the position in the board and sets the bug's position to that position.
 * *************************************/
void Game::add_bug(Bug* new_bug, int position){
	board[position].push_back(new_bug);
	new_bug->set_position(position);	
}

/****************************************
 ** Function name: print_greetings()
 ** Description: Prints the greetings for the game.
 * *************************************/
void Game::print_greetings(){
	cout << "\n\n" << endl;
	cout << "     /////////////////////////////" << endl;
	cout << "     |  Welcome to the classic...|" << endl;
	cout << "     |     ANTS VS SOME BEES     |" << endl;
	cout << "     /////////////////////////////" << endl;
	cout << "	Made by: Juichi Lee"<< endl;
	cout << "	Date: 11/24/18"<< endl;
	cout << "\n           RULES:\n1. Defeat the all the bees(B) to win.\n2. If any bees reach 1st square(Q) you lose.\n3. Bees generate every 2 turns and have 1 attack, 3 armor.\n4. Create and place ants on the board to stop them!\n5. Only 1 ant can exist per space(| |) however Bodyguard is exception." << endl;
	cout << "\n           ANTS:\n1.Harvester-adds 1 food to food supply each turn.\n2.Thrower-inflicts 1 attack on one bee occupying its square.\n3.Fire-upon death, kills all bees on its square.\n4.Long Thrower-inflicts 1 attack to all bees on squares closest to it but at least 4 squares away in both directions.\n5.Short Thrower-inflicts 1 attack to all bees on squares closest to it but no more than 2 squares away in both directions.\n6.Wall-occupies a space to block 4 bee attacks.\n7.Ninja-cannot block bees. Bees that pass by ninja take 1 attack from it.\n8.Bodyguard-the only ant that can occupy another ant's square. Bodyguard taunts bees into attacking it first, blocking 2 bee attacks." << endl;
}

/****************************************
 ** Function name: print_numbered_b()
 ** Description: Prints board with numbers representing space number.
 * *************************************/
void Game::print_numbered_b(){
	int i = 0;
	int j = 0;
	cout << "|";	
	for(i = 0; i < board_size; i++){
		cout << i+1 << ".";
		if(i == 0){
			cout << "Q";
		}else if(i == 9){
			cout << "HV";
		}
		for(j = 0; j < board[i].size(); j++){
			cout << board[i][j]->get_type();
		}
		cout << "|";
	}
	cout << endl;
}

/****************************************
 ** Function name: print_board()
 ** Description: Prints board with all bugs.
 * *************************************/
void Game::print_board(){
	cout << "       [Food: " << num_food << "]" << endl;
	int i = 0;
	int j = 0;
	cout << "   ANTSIDE--|";	
	for(i = 0; i < board_size; i++){
		if(i == 0){
			cout << "Q";
		}else if(i == 9){
			cout << "HV";
		}
		for(j = 0; j < board[i].size(); j++){
			cout << board[i][j]->get_type();
		}
		cout << "|";
	}
	cout << "--BEESIDE" << endl;
}

/****************************************
 ** Function name: check_winlose()
 ** Description: Checks if the player won, lost, or is still going.
 * *************************************/
int Game::check_winlose(){ //0 is lose, 1 is win, 2 is nothing happens
	int i = 0;
	int j = 0;
	int num_bees = 0;
	for(i = 0; i < board_size; i++){
		for(j = 0; j < board[i].size(); j++){
			if(board[i][j]->get_type() == "B"){
				num_bees ++;
			}
		}
	}
	if(num_bees != 0){
		for(i = 0; i < board[0].size(); i++){
			if(board[0][i]->get_type() == "B"){
				return 0;
			}
		}	
		return 2;
	}else{
		return 1;
	}
}

//Constructor + Big 3
Game::Game(){
	int i = 0;
	board_size = 10; //Board size
	board = new vector<Bug*>[board_size]; //Create dynamic board 10x1 dimension	
	num_food = 50; //Starting food for player	
	
}

Game::~Game(){
	int i = 0;
	int j = 0;

	for(i = 0; i < board_size; i++){
		for(j = 0; j < board[i].size(); j++){
			delete board[i][j]; //Delete pointers to (new) dynamically assigned memory
		}
		board[i].clear(); //Clear all vectors
	}
	delete [] board; //Delete entire board of vectors. 
	board = NULL;	

	num_food = 0;
	
	board_size = 0;
}

Game::Game(const Game&){
	
}

Game& Game::operator=(const Game&){

}

//Accessors Mutators
int Game::get_num_food(){
	return num_food;
}
void Game::set_num_food(int a){
	num_food = a;
}
int Game::get_board_size(){
	return board_size;
}
