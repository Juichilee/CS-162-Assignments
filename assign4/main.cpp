#include <iostream>
#include <string>
#include "game.h"
#include "bee.h"
#include "bug.h"
#include "ant.h"
using namespace std;

int main(){

Game game1;
game1.print_greetings();

bool end = false;
int count = 0;
cout << "\n*******GAME START*******\n" << endl;
while(!end){
cout << "       [Turn: " << count << "]" << endl;

game1.print_board();

game1.player_action();

cout << "\n-------Turn Events-------" << endl;

game1.action();

if(count%2 == 0){

	game1.generate_bee();

}

game1.remove_dead();

count ++;

int condition = game1.check_winlose();

switch(condition){
	case 0:	cout << "Queen's dead. You Lose!" << endl;
		end  = true;
		break;
	case 1: cout << "All bees dead. You Win!" << endl;
		end = true;
		break;
	default:
		break;
}

cout << "-------------------------" << endl;

}

return 0;

}
