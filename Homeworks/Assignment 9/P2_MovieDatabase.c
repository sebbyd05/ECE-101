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

//Function that prints the adderessed of movieList that appear in the adderessedToPrint list
void printMovie(movies movieList[], int adderessesToPrint[], int numToPrint) {
    //Print the movies called for
    for(int i = 0; i < numToPrint; i++) {
        printf("%.2lf %s(%d, %d mins)\n", movieList[adderessesToPrint[i]].rating, movieList[adderessesToPrint[i]].title, movieList[adderessesToPrint[i]].year, movieList[adderessesToPrint[i]].duration);
    }

    //Once it's done, return.
    return;
}

int searchName(movies movieList[], int size) {
    //Declare variables for later 
    char searchString[100];
    int numPrinted = 0, numMatch = 0;
    int addressToPrint[10] = {0,0,0,0,0,0,0,0,0,0};

    //Ask the user for what they want to search for
    printf("\nEnter the keyword: ");
    //Dispose of newline
    getchar();
    fgets(searchString, 100, stdin);
    
    //Ensure that the last letter of the string is a null terminator instead of a newline
    searchString[(strlen(searchString) - 1)] = '\0'; //Test this, it might not work right

    //Now search the database for movies that match the criteria
    for(int i = 0; i < size; i++) {
        if(strstr(movieList[i].title, searchString) != NULL) {
            numMatch++;
            //Store the memmory adderess of the cells that should be printed to the addressToPrint array for later, and increase how many need to be printed if less than 10 have been seen so far
            if(numPrinted < 10) {
                addressToPrint[numPrinted] = i;
                numPrinted++;
            }
        }
    }

    //Tell the user no results were found if there is nothing to print
    if(numMatch == 0) {
        printf("\nNo movies with %s\n", searchString);
    } else if (numMatch <= 10) {
        printf("\n%d Movies with %s\n", numMatch, searchString);
        printMovie(movieList, addressToPrint, numPrinted);
    } else if (numMatch > 10) {
        printf("\n%d Movies with %s\n", numMatch, searchString);
        printf("First 10 movies sorted by rating are\n");
        printMovie(movieList, addressToPrint, 10);
    }

    //Ask the user if they want to quit
    char userSelection;
    printf("Continue (Q/q to quit)? ");
    scanf(" %c", &userSelection);
    if(userSelection == 'Q' || userSelection == 'q') {
        return 1;
    } else {
        return 0;
    }
}

//A function that searches for movies with a rating above a given number
int searchRating(movies movieList[], int size) {
    //Declare variables for later 
    double ratingToFind;
    int numPrinted = 0, numMatch = 0;
    int addressToPrint[10] = {0,0,0,0,0,0,0,0,0,0};
    
    //Ask the user for what they want to search for
        printf("\nEnter rating: ");
        scanf("%lf", &ratingToFind);
    
        //Now search the database for movies that match the criteria
        for(int i = 0; i < size; i++) {
            if(movieList[i].rating >= ratingToFind) {
                numMatch++;
                //Store the memmory adderess of the cells that should be printed to the addressToPrint array for later, and increase how many need to be printed if less than 10 have been seen so far
                if(numPrinted < 10) {
                    addressToPrint[numPrinted] = i;
                    numPrinted++;
                }
            }
        }
    
        //Tell the user no results were found if there is nothing to print
        if(numMatch == 0) {
            printf("\nNo movies with a rating higher than %.2lf\n", ratingToFind);
        } else if (numMatch <= 10) {
            printf("\n%d Movies with a rating higher than %.2lf\n", numMatch, ratingToFind);
            printMovie(movieList, addressToPrint, numPrinted);
        } else if (numMatch > 10) {
            printf("\n%d Movies with a rating higher than %.2lf\n", numMatch, ratingToFind);
            printf("First 10 movies sorted by rating are\n");
            printMovie(movieList, addressToPrint, 10);
        }
    
        //Ask the user if they want to quit
        char userSelection;
        printf("Continue (Q/q to quit)? ");
        scanf(" %c", &userSelection);
        if(userSelection == 'Q' || userSelection == 'q') {
            return 1;
        } else {
            return 0;
        }
}

int searchYear(movies movieList[], int size) {
    //Declare variables for later 
    int yearToFind;
    int numPrinted = 0, numMatch = 0;
    int addressToPrint[10] = {0,0,0,0,0,0,0,0,0,0};

    //Ask the user for what they want to search for
    printf("\nEnter year: ");
    scanf("%d", &yearToFind);

    //Now search the database for movies that match the criteria
    for(int i = 0; i < size; i++) {
        if(movieList[i].year == yearToFind) {
            numMatch++;
            //Store the memmory adderess of the cells that should be printed to the addressToPrint array for later, and increase how many need to be printed if less than 10 have been seen so far
            if(numPrinted < 10) {
                addressToPrint[numPrinted] = i;
                numPrinted++;
            }
        }
    }

    //Tell the user no results were found if there is nothing to print
    if(numMatch == 0) {
        printf("\nNo movies with year %d\n", yearToFind);
    } else if (numMatch <= 10) {
        printf("\n%d Movies with year %d\n", numMatch, yearToFind);
        printMovie(movieList, addressToPrint, numPrinted);
    } else if (numMatch > 10) {
        printf("\n%d Movies with year %d\n", numMatch, yearToFind);
        printf("First 10 movies sorted by rating are\n");
        printMovie(movieList, addressToPrint, 10);
    }

    //Ask the user if they want to quit
    char userSelection;
    printf("Continue (Q/q to quit)? ");
    scanf(" %c", &userSelection);
    if(userSelection == 'Q' || userSelection == 'q') {
        return 1;
    } else {
        return 0;
    }
}

int searchDuration(movies movieList[], int size) {
    //Declare variables for later 
    int durationAbove;
    int numPrinted = 0, numMatch = 0;
    int addressToPrint[10] = {0,0,0,0,0,0,0,0,0,0};

    //Ask the user for what they want to search for
    printf("\nEnter duration (in mins): ");
    scanf("%d", &durationAbove);

    //Now search the database for movies that match the criteria
    for(int i = 0; i < size; i++) {
        if(movieList[i].duration >= durationAbove) {
            numMatch++;
            //Store the memmory adderess of the cells that should be printed to the addressToPrint array for later, and increase how many need to be printed if less than 10 have been seen so far
            if(numPrinted < 10) {
                addressToPrint[numPrinted] = i;
                numPrinted++;
            }
        }
    }

    //Tell the user no results were found if there is nothing to print
    if(numMatch == 0) {
        printf("\nNo movies with duration higher than %d minutes\n", durationAbove);
    } else if (numMatch <= 10) {
        printf("\n%d Movies with duration higher than %d minutes\n", numMatch, durationAbove);
        printMovie(movieList, addressToPrint, numPrinted);
    } else if (numMatch > 10) {
        printf("\n%d Movies with duration higher than %d minutes\n", numMatch, durationAbove);
        printf("First 10 movies sorted by rating are\n");
        printMovie(movieList, addressToPrint, 10);
    }

    //Ask the user if they want to quit
    char userSelection;
    printf("Continue (Q/q to quit)? ");
    scanf(" %c", &userSelection);
    if(userSelection == 'Q' || userSelection == 'q') {
        return 1;
    } else {
        return 0;
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

    //Ask the user what they want to do
    while (1 == 1) {
        int selection;
        //Give the user their options
        printf("1: search movie(s) with a keyword\n2: search movie(s) by above rating\n3: search movie(s) by year\n4: search movie(s) by above duration\n");

        //Now ask the user for thier input untill they enter a valid option
        while (1 == 1) {
            printf("\nChoose 1-4 from the above options: ");
            scanf("%d", &selection);
            if(selection == 1) {
                if(searchName(movieList, userNum) == 1) {
                    return 0;
                } else {
                    break;
                }
            } else if(selection == 2) {
                if(searchRating(movieList, userNum) == 1) {
                    return 0;
                } else {
                    break;
                }
            } else if(selection == 3) {
                if(searchYear(movieList, userNum) == 1) {
                    return 0;
                } else {
                    break;
                }
            } else if(selection == 4) {
                if(searchDuration(movieList, userNum) == 1) {
                    return 0;
                } else {
                    break;
                }
            }
        }
    }
    
    return 0;
}