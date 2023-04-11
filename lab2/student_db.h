#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student{

	int idNumber;
	string firstName;
	string lastName;
	string majorName;
};

void get_student_db_info(student*, int, fstream&);	

void sort_student_lastnames(string*, int);

void sort_student_ID(int*, int);

int find_unique_majors(string*, int);
/*
void delete_student_db_info(student*, string*, int*);
*/
