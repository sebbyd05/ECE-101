/*
Name: Sebastian Dziedzic
Date: 4/29/2025
I/O: Movie data / Movies that fit criteria selected by user
Reads file, sorts movies so they pring in cottect order, then lets the user search for what they want
*/

#include<stdio.h>
#include<string.h>

typedef struct movie_s {  
    char title[100]; 
    double rating; //rating from 1 - 10 
    int duration; //in minutes 
    int year; 
} movies;

void readDatabase(movies movieList[], FILE* fileIn, int size) {
    for(int i = 0; i < size; i++) {
        //Store the movie's name into the title section
        fgets(movieList[i].title, 100, fileIn);
        
        //Sometimes fgets only grabs the newline, if it does that i'm having it run again
        if(movieList[i].title[0] == '\n') {
            fgets(movieList[i].title, 100, fileIn);
        }

        //Append \0 to where the newline is now
        int length = strlen(movieList[i].title);
        movieList[i].title[(length - 1)] = '\0';

        //Get the rating
        fscanf(fileIn, "%lf", &movieList[i].rating);
        fscanf(fileIn, "%d", &movieList[i].duration);
        fscanf(fileIn, "%d", &movieList[i].year);
    }

    //Return once finished
    return;
}

//Function that swaps two pieces of an array
void swap(movies *x, movies *y){  
    movies temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}

//A function that sorts the movie array
void selection_sort(movies x[], int size){  
    int i, j, max;  
    for (i = 0; i < size; i++) {  
        max = i;
        for (j = i; j < size; j++) {  
            if (x[j].rating > x[max].rating) { 
                max = j;
            }
        }
        swap(&x[i], &x[max]);  
    }  
}  
   

    
int main() {
    //Ask the user how many movies they want to compute:
    int userNum = 0;
    printf("Enter number of movies you want to use from the database: ");
    scanf("%d", &userNum);
    
    //Create the movie array
    movies movieList[userNum];

    //Opens the file to read from
    FILE* inFile = NULL;
    inFile = fopen("movies_database.txt", "r");

    //Have the read database function put all the movies into a database
    readDatabase(movieList, inFile, userNum);

    //Sort the movies by rating
    selection_sort(movieList, userNum);

    return 0;
}