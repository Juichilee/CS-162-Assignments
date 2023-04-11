/*************************************************
 * Program Filename: netflix.cpp
 * Author: Juichi Lee
 * Date: 10/7/18
 * Description: Holds all the function definitions and code
 * 		for run_netflix.cpp and netflix.h
**************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "netflix.h"

using namespace std;

/**********************************************************
 *Function: get_movie_data
 *Description: Finds and stores movie data from fstream into a movie array
 *Parameters: movie* movieArray, int num_movies, fstream& infile
 *Pre-Conditions: Infile is in correct format
 *Post-Conditions: Inserts correct movie data from fstream into the movie array
**********************************************************/
void get_movie_data(movie* movieArray, int num_movies, fstream& infile){

	string suggested;	

	for(int i = 0; i < num_movies; i++){

		infile >> movieArray[i].title;

		infile >> movieArray[i].rating;

		infile >> movieArray[i].num_actors;
		
		movieArray[i].actors = new string[movieArray[i].num_actors];

		for(int j = 0; j < movieArray[i].num_actors; j++){

			infile >> movieArray[i].actors[j];

		}

		infile >> suggested;

		if(suggested == "true"){

			movieArray[i].suggested = true;

		}else{

			movieArray[i].suggested = false;

		}
	}

}

/**********************************************************
 *Function: get_genre_data
 *Description: Finds and stores genre data from fstream into a genre array
 *Parameters: genre* genreArray, int num_genres, fstream& infile
 *Pre-Conditions: Infile is correctly formmatted
 *Post-Conditions: Stores genre data into genre array correctly
**********************************************************/
void get_genre_data(genre* genreArray, int num_genres, fstream& infile){

	string firstLine;

	getline(infile, firstLine);

	for(int i = 0; i < num_genres; i++){	 

	   	infile >> genreArray[i].genre_name;

		infile >> genreArray[i].num_movies;

		genreArray[i].movies = new movie[genreArray[i].num_movies];

		get_movie_data(genreArray[i].movies, genreArray[i].num_movies, infile);

	 }
}

/**********************************************************
 *Function: get_g_with_most_movies
 *Description: Finds and returns the genre with most movies
 *Parameters: genre* genreArray, int num_genres
 *Pre-Conditions: genreArray has been formmated correctly
 *Post-Conditions: returns the correct genre with most movies
**********************************************************/
string get_g_with_most_movies(genre* genreArray, int num_genres){

	int max_genre = 0;

	for (int i = 0; i < num_genres - 1; i ++){

		if(genreArray[i].num_movies > genreArray[i+1].num_movies){

			max_genre = i;

		}else{

			max_genre = i+1;

		}

	}

	return genreArray[max_genre].genre_name;

}

/**********************************************************
 *Function: get_all_movies
 *Description: Sorts and stores all movies into a movie* array
 *Parameters: genre* genreArray, movie* all_movies, int num_genres, int num_all_movies
 *Pre-Conditions: genreArray has been formmated correctly, all_movies is the same size as num_all_movies
 *Post-Conditions: Successfully stores all movies into the movie* array
**********************************************************/
void get_all_movies(genre* genreArray, movie* all_movies, int num_genres, int num_all_movies){

	int end_index;

	int end;

	for (int i = 0; i < num_genres; i++){

		for(int j = 0; j < genreArray[i].num_movies; j++){

			all_movies[j + end_index] = genreArray[i].movies[j];

			end = j+1;

		}

		end_index = end;

	}	

}

/**********************************************************
 *Function: get_highest_mr
 *Description: Finds the movie with the highest movie rating
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns the movie with the highest rating
**********************************************************/
string get_highest_mr(movie* all_movies, int num_all_movies){

	string title;

	for(int i = 0; i < num_all_movies - 1; i++){

		if(all_movies[i].rating > all_movies[i+1].rating){

			title = all_movies[i].title;

		}else{

			title = all_movies[i+1].title;

		}

	}

	return title;

}

/**********************************************************
 *Function: get_avg_r_in_genre
 *Description: Finds and stores the avg rating of each genre in a float* array
 *Parameters: genre* genreArray, float* avg_rating_genre, int num_genres
 *Pre-Conditions: genreArray has been formmated correctly, avg_rating_genre size is equal to num_genres
 *Post-Conditions: Successfully stores the avg rating of each genre in avg_rating_genre
**********************************************************/
void get_avg_r_in_genre(genre* genreArray, float* avg_rating_genre, int num_genres){

	float avg_rating;

	for(int i = 0; i < num_genres; i++){

		float total = 0;

		for(int j = 0; j < genreArray[i].num_movies; j++){

			total += genreArray[i].movies[j].rating;

		}

		avg_rating = (total/(float)genreArray[i].num_movies);

		avg_rating_genre[i] = avg_rating;		

	}

}

/**********************************************************
 *Function: get_m_with_most_a
 *Description: Finds and returns the movie with the most actors and who those actors are
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: Successfully returns the movie with the most actors and who those actors are
**********************************************************/
string get_m_with_most_a(movie* all_movies, int num_all_movies){

	int max_movie;

	string output;

	for(int i = 0; i < num_all_movies - 1; i++){

		if(all_movies[i].num_actors > all_movies[i+1].num_actors){

			max_movie = i; 

		}else{

			max_movie = i+1;

		}

	}

	output = "Movie: " + all_movies[max_movie].title + "\nActors: ";

	for(int j = 0; j < all_movies[max_movie].num_actors; j++){

		output += (all_movies[max_movie].actors[j] + " ");

	}

	return output;

}

/**********************************************************
 *Function: get_all_m_sorted_r
 *Description: Sorts and returns a string of all movies and their rating from highest to lowest
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns the sorted string of all movies and their ratings from highest to lowest
**********************************************************/
string get_all_m_sorted_r(movie* all_movies, int num_all_movies){

	string output;

	stringstream m_rating_ss;

	int startScan, minIndex;

	movie min_r_movie;

	for(startScan = 0; startScan < (num_all_movies - 1); startScan++){

		minIndex = startScan;

		min_r_movie = all_movies[startScan];

		for(int index = startScan + 1; index < num_all_movies; index++){

			if(all_movies[index].rating < min_r_movie.rating){

				min_r_movie = all_movies[index];

				minIndex = index;

			}

		}

		all_movies[minIndex] = all_movies[startScan];

		all_movies[startScan] = min_r_movie;

	}

	for(int i = num_all_movies - 1; i > -1; i--){

		m_rating_ss << all_movies[i].rating;

		output +=  all_movies[i].title + " rating: " + m_rating_ss.str();

		output += "\n";

		m_rating_ss.str("");

		m_rating_ss.clear();

	}

	return output;

}

/**********************************************************
 *Function: get_all_s_movies
 *Description: Finds and returns all suggested movies
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns all suggested movies in a string
**********************************************************/
string get_all_s_movies(movie* all_movies, int num_all_movies){

	string output;

	for(int i = 0; i < num_all_movies; i++){

		if(all_movies[i].suggested == true){

			output += all_movies[i].title + "\n";

		}

	}

	return output;

}

/**********************************************************
 *Function: data_formatter
 *Description: Formats all the input data into a readable format by the user
 *Parameters: string g_with_most_movies, string highest_mr, 
			string* avg_rating_m_g, string*  g_avg_r_above, 
			string m_with_most_a, string all_m_sorted_r, 
			string all_s_movies, int num_genres, genre* genreArray)
 *Pre-Conditions: All parameters are of their data type
 *Post-Conditions: returns a string that displays all inputted data in a readable format.
**********************************************************/
string data_formatter(string g_with_most_movies, string highest_mr, 
			string* avg_rating_m_g, string*  g_avg_r_above, 
			string m_with_most_a, string all_m_sorted_r, 
			string all_s_movies, int num_genres, genre* genreArray){

	string output;

	// Genre with most movies

	output += "Genre with most movies: " + g_with_most_movies + "\n\n";

	// Movie with highest rating

	output += "Movie with highest rating: " + highest_mr + "\n\n";

	// Average rating for all movies in a genre

	output += "Average rating for all movies in a genre: \n"; 

	for(int i = 0; i < num_genres; i++){

		output += avg_rating_m_g[i] + "  ";

	}

	output += "\n\n";

	//Genre with an average movie rating above a certain amount

	output += "Genre with an average movie rating above a certain amount: \n";

	for(int j = 0; j < num_genres; j++){

		output += g_avg_r_above[j];

	}

	output += "\n";

	//Movie with the most actors and who those actors are

	output += "Movie with most actors: \n" + m_with_most_a;

	output += "\n\n";

	//All movies sorted by rating

	output += "All movies sorted by rating: \n" + all_m_sorted_r;

	output+= "\n";

	//All movies that are suggested

	output += "All suggested movies: \n" + all_s_movies;
	
	return output;

}

/**********************************************************
 *Function: delete_info
 *Description: Frees up memory from using dynamic memory
 *Parameters: genre* genreArray, int num_genres, movie* all_movies, float* avg_rating_genre, string* avg_rating_m_g, string* g_avg_r_above
 *Pre-Conditions: num_genres is the same size as genre_array
 *Post-Conditions: Successfully deletes all dynamic arrays and frees up memory
**********************************************************/
void delete_info(genre* genreArray, int num_genres, movie* all_movies, float* avg_rating_genre, string* avg_rating_m_g, string* g_avg_r_above){

	for(int i =  0; i < num_genres; i++){

		for(int j = 0; j < genreArray[i].num_movies; j++){

			delete[] genreArray[i].movies[j].actors;

		}

		delete[] genreArray[i].movies;

	}

	delete[] genreArray;

	delete[] all_movies;

	delete[] avg_rating_genre;

	delete[] avg_rating_m_g;

	delete[] g_avg_r_above;

}

