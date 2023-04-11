/*************************************************
 * Program Filename: netflix.h
 * Author: Juichi Lee
 * Date: 10/7/18
 * Description: The header file for run_netflix.cpp and netflix.cpp
 * 
**************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct movie{
	string title; //movie title
	int num_actors; //number of actors in the film
	string* actors; //array of actors
	float rating;
	bool suggested; //true/false of whether this movie was suggested for you
};
struct genre{
	string genre_name; //name of genre
	movie* movies; //array of movie structs
	int num_movies; //number of movies in this category
};

/**********************************************************
 *Function: get_movie_data
 *Description: Finds and stores movie data from fstream into a movie array
 *Parameters: movie* movieArray, int num_movies, fstream& infile
 *Pre-Conditions: Infile is in correct format
 *Post-Conditions: Inserts correct movie data from fstream into the movie array
**********************************************************/
void get_movie_data(movie*, int, fstream&);

/**********************************************************
 *Function: get_genre_data
 *Description: Finds and stores genre data from fstream into a genre array
 *Parameters: genre* genreArray, int num_genres, fstream& infile
 *Pre-Conditions: Infile is correctly formmatted
 *Post-Conditions: Stores genre data into genre array correctly
**********************************************************/
void get_genre_data(genre*, int, fstream&);

/**********************************************************
 *Function: get_g_with_most_movies
 *Description: Finds and returns the genre with most movies
 *Parameters: genre* genreArray, int num_genres
 *Pre-Conditions: genreArray has been formmated correctly
 *Post-Conditions: returns the correct genre with most movies
**********************************************************/
string get_g_with_most_movies(genre*, int);

/**********************************************************
 *Function: get_all_movies
 *Description: Sorts and stores all movies into a movie* array
 *Parameters: genre* genreArray, movie* all_movies, int num_genres, int num_all_movies
 *Pre-Conditions: genreArray has been formmated correctly, all_movies is the same size as num_all_movies
 *Post-Conditions: Successfully stores all movies into the movie* array
**********************************************************/
void get_all_movies(genre*, movie*, int, int);

/**********************************************************
 *Function: get_highest_mr
 *Description: Finds the movie with the highest movie rating
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns the movie with the highest rating
**********************************************************/
string get_highest_mr(movie*, int);

/**********************************************************
 *Function: get_avg_r_in_genre
 *Description: Finds and stores the avg rating of each genre in a float* array
 *Parameters: genre* genreArray, float* avg_rating_genre, int num_genres
 *Pre-Conditions: genreArray has been formmated correctly, avg_rating_genre size is equal to num_genres
 *Post-Conditions: Successfully stores the avg rating of each genre in avg_rating_genre
**********************************************************/
void get_avg_r_in_genre(genre*, float*, int);

/**********************************************************
 *Function: get_m_with_most_a
 *Description: Finds and returns the movie with the most actors and who those actors are
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: Successfully returns the movie with the most actors and who those actors are
**********************************************************/
string get_m_with_most_a(movie*, int);

/**********************************************************
 *Function: get_all_m_sorted_r
 *Description: Sorts and returns a string of all movies and their rating from highest to lowest
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns the sorted string of all movies and their ratings from highest to lowest
**********************************************************/
string get_all_m_sorted_r(movie*, int);

/**********************************************************
 *Function: get_all_s_movies
 *Description: Finds and returns all suggested movies
 *Parameters: movie* all_movies, int num_all_movies
 *Pre-Conditions: all_movies stores all the movies
 *Post-Conditions: returns all suggested movies in a string
**********************************************************/
string get_all_s_movies(movie*, int);

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
string data_formatter(string, string, 
			string*, string*, 
			string, string, 
			string, int, genre*);

/**********************************************************
 *Function: delete_info
 *Description: Frees up memory from using dynamic memory
 *Parameters: genre* genreArray, int num_genres, movie* all_movies, float* avg_rating_genre, string* avg_rating_m_g, string* g_avg_r_above
 *Pre-Conditions: num_genres is the same size as genre_array
 *Post-Conditions: Successfully deletes all dynamic arrays and frees up memory
**********************************************************/
void delete_info(genre*, int, movie*, float*, string*, string*);

