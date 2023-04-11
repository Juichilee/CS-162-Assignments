#include <iostream>
#include <fstream>
#include <string>
#include "student_db.h"
using namespace std;

int main(int argc, char* argv[]){
	
	cout << "==========================\n";

	if(argc > 1){
			
		cout << "You inputted:  " << argv[1] << endl;

	}else{

		cout << "No file name entered. Exiting..."<< endl;
		return -1;

	}
	fstream infile;
	infile.open(argv[1]); //file opener
	
	if(infile.is_open()){
		cout << "\nFile is now open!" << endl;
		cout << endl;

		int num_students;
		infile >> num_students; 
		student* studentArray = new student[num_students];
		get_student_db_info(studentArray, num_students, infile);
		infile.close();
		ofstream outfile("output.txt");
	
		//Sort Last Names
		string lastNameArray[num_students];
		for(int i = 0; i < num_students; i++){
			lastNameArray[i] = studentArray[i].lastName;
		}
		sort_student_lastnames(lastNameArray, num_students);
		outfile << "Last Names Sorted: " << endl;
		for(int i = 0; i < num_students; i++){
			outfile << lastNameArray[i] << " ";
		}
		outfile << "\n" << "\n";	
	
		//Sort ID Number
		int IDArray[num_students];
		for(int i = 0; i < num_students; i++){
			IDArray[i] = studentArray[i].idNumber;
		}
		sort_student_ID(IDArray, num_students);
		outfile << "ID Numbers Sorted: " << endl;
		for(int i = 0; i < num_students; i++){
			outfile << IDArray[i] << " ";
		}
		outfile << "\n" << "\n";
	
		//Number Unique Majors
		string majorsArray[num_students];
		int num_unique_majors;
		for(int i = 0; i < num_students; i++){
			majorsArray[i] = studentArray[i].majorName;
		}		
		num_unique_majors = find_unique_majors(majorsArray, num_students);
		outfile << "Number of Unique Majors: \n" << num_unique_majors << endl;
		outfile.close();
		cout << "Sorting Completed!\n";
		
		delete[] studentArray;
		
		//delete_student_db_info(studentArray, lastNameArray, IDArray);
	}else{
		cout << "Failed to open file..";
	}
	cout << "==========================\n";
	return 0;
}
