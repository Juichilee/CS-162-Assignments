/*************************************************
 * Program Filename: run_netflix.cpp
 * Author: Juichi Lee
 * Date: 10/7/18
 * Description: The main for running the program
**************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "netflix.h"

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

		int num_genres;

		infile >> num_genres; 

		genre* genreArray = new genre[num_genres];

		get_genre_data(genreArray, num_genres, infile); //Parses the database.txt

		infile.close();

		//The genre with most movies

		string g_with_most_movies;

		g_with_most_movies = get_g_with_most_movies(genreArray, num_genres);

		//Get all movies

		int num_all_movies = 0;

		for(int c = 0; c < num_genres; c++){

			num_all_movies	+= genreArray[c].num_movies;

		}	

		movie* all_movies = new movie[num_all_movies];

		get_all_movies(genreArray, all_movies, num_genres, num_all_movies);

		//Movie with highest rating

		string highest_mr;

		highest_mr = get_highest_mr(all_movies, num_all_movies);

		//Average rating for all movies in a genre

		float* avg_rating_genre = new float[num_genres];
		
		string* avg_rating_m_g = new string[num_genres];
		
		get_avg_r_in_genre(genreArray, avg_rating_genre, num_genres);	
		
		stringstream  avg_rating_ss;

		for(int i = 0; i < num_genres; i++){
				
			avg_rating_ss << avg_rating_genre[i];

			avg_rating_m_g[i] = genreArray[i].genre_name + ": " + avg_rating_ss.str();

			avg_rating_ss.str("");

			avg_rating_ss.clear();
			
		}
			
		//Genre with an average movie rating above certain amount
	
		float amount;
	
		string* g_avg_r_above =  new string[num_genres];

		cout << "Enter desired avg. movie rating in a genre" << endl;

		cin >> amount;

		cout << endl;

		for(int j = 0; j < num_genres; j++){

			if(avg_rating_genre[j] > amount){

				avg_rating_ss << avg_rating_genre[j];

				g_avg_r_above[j] = genreArray[j].genre_name + ": " + avg_rating_ss.str() + "\n";

				avg_rating_ss.str("");

				avg_rating_ss.clear();

			}

		}
	
		//Movie with the most actors and who those actors are

		string m_with_most_a;

		m_with_most_a = get_m_with_most_a(all_movies, num_all_movies);

		//All movies sorted by rating

		string all_m_sorted_r;

		all_m_sorted_r = get_all_m_sorted_r(all_movies, num_all_movies);

		//All movies that are suggested

		string all_s_movies;

		all_s_movies = get_all_s_movies(all_movies, num_all_movies);
	
		//Output to file or print

		string answer;

		cout << "Would you like to print to file? Y/N (Defaulted to print to terminal)" << endl;

		cin >> answer;

		cout << endl;

		if(answer == "Y" || answer == "y"){
		
			string outfile_name;

			ofstream output;

			cout << "Insert (filename.txt) to output data to." << endl;

			cin >> outfile_name;

			output.open(outfile_name.c_str());

			if(output.is_open()){

				cout << endl;

				cout << "Successfully created file" << endl;

				string parsed_to_file;

				parsed_to_file = data_formatter(g_with_most_movies, highest_mr,
								 avg_rating_m_g, g_avg_r_above, 
								 m_with_most_a, all_m_sorted_r, 
								 all_s_movies, num_genres, genreArray); 

				output << parsed_to_file;

				output.close();

			}else{

				cout << endl;

				cout << "Failed to create file..";

			}

		}else{

			cout << "========================" << "\n  [Printed to Terminal]\n" << "========================" << endl;

			string parsed_to_terminal;

			parsed_to_terminal = data_formatter(g_with_most_movies, highest_mr, 
						  	 avg_rating_m_g, g_avg_r_above, 
							 m_with_most_a, all_m_sorted_r, 
							 all_s_movies, num_genres, genreArray); 

			cout << parsed_to_terminal;

		}

		delete_info(genreArray, num_genres, all_movies, avg_rating_genre, avg_rating_m_g, g_avg_r_above);	
	
	}else{

		cout << "Failed to open file..";

	}

	cout << "\n========================\n";

		return 0;

}
