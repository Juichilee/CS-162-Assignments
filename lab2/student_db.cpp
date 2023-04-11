#include <iostream>
#include <fstream>
#include <string>
#include "student_db.h"
using namespace std;

using std::cout;
using std::endl;

void get_student_db_info(student* array, int studentNum, fstream& input){	
	string firstLine;
	getline(input,firstLine);
	for(int i = 0; i < studentNum; i++){	 
	   	 input >> array[i].idNumber;
		 input >> array[i].firstName;
		 input >> array[i].lastName;
		 input >> array[i].majorName;
	}
}

void sort_student_lastnames(string* lastNameArray, int num_students){
	int startScan, minIndex;
	string minValue;
	for(startScan = 0; startScan < (num_students - 1); startScan++){
		minIndex = startScan;
		minValue = lastNameArray[startScan];
		for(int index = startScan + 1; index < num_students; index++){
			if(lastNameArray[index] < minValue){
				minValue = lastNameArray[index];
				minIndex = index;
			}
		}
		lastNameArray[minIndex] = lastNameArray[startScan];
		lastNameArray[startScan] = minValue;
	}
}

void sort_student_ID(int* IDArray, int num_students){
	int startScan, minIndex;
	int minValue;
	for(startScan = 0; startScan < (num_students - 1); startScan++){
		minIndex = startScan;
		minValue = IDArray[startScan];
		for(int index = startScan + 1; index < num_students; index++){
			if(IDArray[index] < minValue){
				minValue = IDArray[index];
				minIndex = index;
			}
		}
		IDArray[minIndex] = IDArray[startScan];
		IDArray[startScan] = minValue;
	}
}

int find_unique_majors(string* majorsArray, int num_students){
	int startScan, minIndex;
	int unique = 1;
	string currentMajor;
	for(startScan = 0; startScan < num_students-1; startScan++){
		minIndex = startScan;
		currentMajor = majorsArray[startScan];
		unique++;
		for(int index = startScan + 1; index < num_students; index++){
			if(majorsArray[index] == currentMajor){
				unique--;
			}
		}
	}
	return unique;
}
/*
void delete_student_db_info(student* array, string* ln_array, int* ID_array){
	delete [] array;
	delete [] ln_array;
	delete [] ID_array;
}
*/


