#include <iostream>
#include <string.h>
#include <cstdlib>
#include "./mult_div.h"
#include <new>

using std::endl;
using std::cout;
using std::cin;
using namespace std;

bool isNonZeroInteger(char *row, char *col){

	bool rowCheck = false;

	bool colCheck = false;

	for(int i = 0 ; i <strlen(row);i++){
		if(row[i] > '0' && row [i] <= '9'){
			rowCheck = true;
		}
	}

	for(int i = 0; i < strlen(col); i++){
		if(col[i] > '0' && col [i] <= '9'){
			colCheck = true;
		}
	}
return rowCheck && colCheck;
}


mult_div_values** create_table(int r, int c){
	
	mult_div_values** array = new mult_div_values*[r];

	for(int i = 0; i < r; i++){
		array[i] = new mult_div_values[c];
	}
	return array;
}


void set_mult_values(mult_div_values** mult_Array, int r, int c){
	
	cout << "Multiplication Table" << endl;
		
	for(int i = 0; i < r; i++) {
	
		cout << "  |  ";

		for(int j = 0; j < c; j++){
			int product = (i+1) * (j+1);
			mult_Array[i][j].mult = product;

			cout << mult_Array[i][j].mult <<  "  |  ";
		}
		cout << endl;

	}

}


void delete_table(mult_div_values** table, int r, int c){
	
	for(int i = 0; i < r; i++){
		delete [] table[i];	
	}
	delete [] table;	
}


void set_div_values(mult_div_values** div_Array, int r, int c){
	
	cout << endl;
	
	cout << "Division Table" << endl;

	for(int i = 0; i < r; i++){

		cout << "  |  ";

		for(int j = 0; j < c; j++){
			float quotient =(float)(i+1)/(float)(j+1);
			div_Array[i][j].div = quotient;

			cout << div_Array[i][j].div << "  |  ";
		}
		cout <<  endl;
	}
}
/*
int main(int argc, char*argv[]){

bool again = false;

do{
	char *col = new char[2];

	char *row = new char[2];

	bool is_valid = false;

		while(!is_valid){
			cout << "please enter an intenger greater than 0 for column" << endl;
			cin >> col;

			cout << "please enter an integer greater than 0 for row" << endl;
			cin >> row;
	 
			if(isNonZeroInteger(row, col) == 1){

				is_valid = true;

			}else{

				cout << "Not valid inputs. Please enter non-zero integers" << endl;
			}
		}
	
		int rowInt = atoi(row);
	
		int colInt = atoi(col);
	
		mult_div_values** table = create_table (rowInt, colInt);
	
		set_mult_values(table, rowInt, colInt);

		set_div_values(table, rowInt, colInt);

		delete_table(table, rowInt, colInt);
		
		delete[] col;

		delete[] row;

		cout << endl;		

		again = false;

		cout << "Would you like to make another mult_div table?(Y/N)" << endl;

		string input;

		cin >> input;

		if(input == "Y" || input == "y"){
			again = true;
		}

} while (again == true);

return 0;

}
*/

