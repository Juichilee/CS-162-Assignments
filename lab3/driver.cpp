#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(int argc, char  *argv[]){
	
	char *input = NULL;
	int i = 0;
	
	cin >> input;

	for(i = strlen(input); i >= 0; i--){
		cout << input[i];
	}
	cout << endl;
	
	return 0;
}
/*
	#ifdef DEBUG
		cout << "Debugging On!" << endl;
	#else
		cout << "Debugging Off!" << endl;
	#endif
*/

