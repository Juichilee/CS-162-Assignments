/****************************************
 ** Program Filename: game.h
 ** Author: Juichi Lee
 ** Description: header file for game.cpp
 ** Date: 11/24/18
 * *************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "bug.h"
#include "ant.h"
#include "bee.h"
#include "thrower.h"
#include "harvester.h"
#include "fire.h"
#include "lthrower.h"
#include "sthrower.h"
#include "ninja.h"
#include "wall.h"
#include "bodyguard.h"
using namespace std;

class Game{
	private:
		vector<Bug*>* board;
		int num_food;
		int board_size;		
	
	public:
		//Accessors Mutators
		int get_num_food();
		void set_num_food(int);
		int get_board_size();

		//Constructor + Big 3
		Game();
		~Game();
		Game(const Game&);
		Game& operator=(const Game&);

		//Functions
		void print_greetings();
		bool check_space_ants(int);
		int check_winlose();
		void add_ant(Ant*);
		void choose_unit();
		void generate_bee();
		void player_action();
		void action();
		void bee_attack(Bug*);
		void bee_move(Bug*);
		void bee_action(Bug*);
		void ant_action(Bug*);
		void remove_dead();
		void add_bug(Bug*, int);
		void remove_bug();
		void print_board();
		void print_numbered_b();	
};
#endif
