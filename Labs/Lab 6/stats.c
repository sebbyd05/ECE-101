#include<stdio.h>

void read_ar(FILE *in, int x[][9]) {
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 9; col++){
            fscanf(in, "%d", &x[row][col]);
        }
    }
}

int main() {
    FILE *inFile = NULL;
    int votes[5][9];
    int candate[5]={0,0,0,0,0};
    int precinct[9]={0,0,0,0,0,0,0,0,0};
    int maxcandatePos = 0, maxPrecinctPos = 0;
    char str[10];

    //Ask user for a string
    printf("Enter file name: ");
    scanf("%s", &str);
    printf("\n");

    //Open file
    inFile = fopen(str, "r");
    if(inFile == NULL) {
        printf("File failed to open");
        return -1;
    }

    //Put the votes in the array
    read_ar(inFile, votes);

    //Begin doing math on the array for candates
    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 9; col++) {
            candate[row] += votes[row][col];
        }
    }

    //Begin doing the math on the array for presincts
    for(int col = 0; col < 9; col++) {
        for(int row = 0; row < 5; row++) {
            precinct[col] += votes[row][col];
        }
    }

    //Begin printing main table
    printf("Precinct\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    printf("Candidate\n");

    for(int row = 0; row < 5; row++) {
        printf("%d\t\t", (row + 1));
        for(int col = 0; col < 9; col++) {
            printf("%d\t", votes[row][col]);
        }
        printf("\n");
    }

    //Print candate votes while finding the candate with max votes
    printf("\nTotal votes by candidate:\n");
    for(int row = 0; row < 5; row ++){
        printf("%d ", candate[row]);
        if(candate[row] > candate[maxcandatePos]) {
            maxcandatePos = row;
        }
    }

    //Print max stats
    printf("\n");
    printf("\nCandidate %d has a max total of %d", (maxcandatePos + 1), candate[maxcandatePos]);

    //Print votes by presinct while calculating max stats
    printf("\n");
    printf("\nTotal votes by precinct\n");
    for(int row = 0; row < 9; row++) {
        printf("%d ", precinct[row]);
        if(precinct[row] > precinct[maxPrecinctPos]) {
            maxPrecinctPos = row;
        }
    }

    //Print max stats again
    printf("\n");
    printf("\nPrecinct %d has a max total of %d\n\n", (maxPrecinctPos + 1), precinct[maxPrecinctPos]);

    return 0;
}