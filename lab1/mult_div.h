#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

struct mult_div_values{
	int mult;
	float div;
};

bool isNonZeroInteger(char *, char*);

mult_div_values** create_table(int, int);

void set_mult_values(mult_div_values**, int, int);

void set_div_values(mult_div_values**, int, int);

void delete_table(mult_div_values**, int, int);

	
int main(int argc, char*argv[]){

bool again = false;

do{
	char *col = new char[2];

	char *row = new char[2];

	bool is_valid = false;

	int rowInt = atoi(argv[0]);
	
	int colInt = atoi(argv[1]);
	
	if(colInt == 0 || rowInt == 0){

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
		rowInt = atoi(row);
		colInt = atoi(col);
	}
	
	
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

