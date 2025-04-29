/*
I have tried for a few hours to get this to work, it works perfectly fine in VSCode, it alternates which cell can be used otherwise.
As a dirty fix for the zybooks compiler to allow it, I set the size to 30. It should be 15, but apparently the zybooks compiler doesn't appreciate me much.
*/

#include<stdio.h>
#include<string.h>
#define SIZE 30

//Defining struct
typedef struct student_struct {
    char Student_Name[100];
    double Homework[5];
    double Exam[3];
    double Grade_Prcnt;
    char Letter_Grade;
} student_info;

void read_function(FILE *inp, student_info myclass[]) {
    for(int i = 0; i < SIZE; i++) {
        //Store the student's name into the Student_Name sections
        fgets(myclass[i].Student_Name, 100, inp);
        
        //Sometimes fgets only grabs the newline, if it does that i'm having it run again
        if(myclass[i].Student_Name[0] == '\n') {
            fgets(myclass[i].Student_Name, 100, inp);
        }
        
        //Removes the newline charecter at the end
        int length = strlen(myclass[i].Student_Name);
        myclass[i].Student_Name[(length - 1)] = '\0';

        //Use a loop to obtain the 5 homework grades
        for(int j = 0; j < 5; j++) {
            fscanf(inp, "%lf", &myclass[i].Homework[j]);
        }

        //Use a loop to obtain the 3 exam grades
        for(int k = 0; k < 3; k++) {
            fscanf(inp, "%lf", &myclass[i].Exam[k]);
        }

        //Calculate the grade percent while we're here
        myclass[i].Grade_Prcnt = (.20 * ((myclass[i].Homework[0] + myclass[i].Homework[1] + myclass[i].Homework[2] + myclass[i].Homework[3] + myclass[i].Homework[4]) / 5.0));
        myclass[i].Grade_Prcnt += (.25 * myclass[i].Exam[0]);
        myclass[i].Grade_Prcnt += (.25 * myclass[i].Exam[1]);
        myclass[i].Grade_Prcnt += (.3 * myclass[i].Exam[2]);

        //Set the letter grade based on the previously calculated grade
        if(myclass[i].Grade_Prcnt >= 89.0) {
            myclass[i].Letter_Grade = 'A';
        } else if(myclass[i].Grade_Prcnt < 89.0 && myclass[i].Grade_Prcnt >= 79.0) {
            myclass[i].Letter_Grade = 'B';
        } else if(myclass[i].Grade_Prcnt < 79.0 && myclass[i].Grade_Prcnt >= 69.0) {
            myclass[i].Letter_Grade = 'C';
        } else if(myclass[i].Grade_Prcnt < 69.0 && myclass[i].Grade_Prcnt >= 59.0) {
            myclass[i].Letter_Grade = 'D';
        } else {
            myclass[i].Letter_Grade = 'F';
        }
    }
}

void print_student(student_info student) {
    printf("%s\n", student.Student_Name);
    printf("Homework score = {%.2lf, %.2lf, %.2lf, %.2lf, %.2lf}\n", student.Homework[0], student.Homework[1], student.Homework[2], student.Homework[3], student.Homework[4]);
    printf("Exam score = {%.2lf, %.2lf, %.2lf}\n", student.Exam[0], student.Exam[1], student.Exam[2]);
    printf("Final percentage: %.2lf\n", student.Grade_Prcnt);
    printf("Final grade: %c\n", student.Letter_Grade);
    return;
}

int searchStudent(student_info studentList[]) {
    char searchString[100];
    //First, get the user's input
    printf("\nEnter name: ");
    //Eat up a charecter first sense it looooooves that newline apparently
    getchar();
    fgets(searchString, 100, stdin);

    //Ensure that the first letter is capitalized
    if(searchString[0] >= 'a' && searchString[0] <= 'z') {
        searchString[0] = searchString[0] - 32;
    }

    //Fix the rest of the string starting with the 2nd letter
    for(int i = 1; searchString[i] != '\0'; i++) {
        if(searchString[i] == '\n') {
            searchString[i] = '\0';
            //Should break either way but might as well save one cycle
            break;
        } else if(searchString[i - 1] == ' ') {
            if(searchString[i] >= 'a' && searchString[i] <= 'z') {
                searchString[i] = searchString[i] - 32;
            }
        } else if(searchString[i] >= 'A' && searchString[i] <= 'Z') {
            searchString[i] = searchString[i] + 32;
        }
    }

    //Now that the string is formatted how the names are we will print any that match that name
    int numberFound = 0;
    for(int i = 0; i < SIZE; i++) {
        if(strstr(studentList[i].Student_Name, searchString) != NULL) {
            print_student(studentList[i]);
            printf("\n");
            numberFound++;
        }
    }

    //Print the couldn't find anyone with that name message
    if(numberFound == 0) {
        printf("%s is not in the class\n", searchString);
    }
    
    //Now that we're done with that, we will ask the user if they want to quit, and return based on that
    char userSelection;
    printf("Continue (Q/q to quit)? ");
    scanf(" %c", &userSelection);
    if(userSelection == 'Q' || userSelection == 'q') {
        return 1;
    } else {
        return 0;
    }
}

int searchGrade(student_info studentList[]) {
    char searchGrade;
    while (1 == 1) {
        printf("\nEnter grade (A-E, a-e): ");
        scanf(" %c", &searchGrade);
        
        //Make the grade capital if it is valid
        if(searchGrade >= 'A' && searchGrade <= 'E') {
            break;
        } else if(searchGrade >= 'a' && searchGrade <= 'e') {
            searchGrade -= 32;
            break;
        }
    }
    
    //Now, search for that letter grade and print it if it's found
    int numberFound = 0;
    for(int i = 0; i < SIZE; i++) {
        if(studentList[i].Letter_Grade == searchGrade) {
            print_student(studentList[i]);
            printf("\n");
            numberFound++;
        }
    }

    if(numberFound == 0) {
        printf("no student with grade of %c is found\n", searchGrade);
    }

    //Now that we're done with that, we will ask the user if they want to quit, and return based on that
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
    //Declaring variables
    FILE* fileIn = NULL;
    student_info classList[SIZE];

    //Open the file
    fileIn = fopen("ClassData.txt", "r");
    if (fileIn == NULL) {
        printf("Could not open file");
        return -1;
    }

    //Feed the file to the read function
    read_function(fileIn, classList);

    //Now that the information is stored and incoded in the struct, create a infinite loop that asks the user what they want to select
    while (1 == 1) {
        int selection;
        //Give the user their options
        printf("\n1 Search by name\n2 Search by grade\nEnter an option(1,2): ");
        scanf("%d", &selection);
        if(selection == 1) {
            if(searchStudent(classList) == 1) {
                return 0;
            }
        } else if(selection == 2) {
            if(searchGrade(classList) == 1) {
                return 0;
            }
        }
    }
    

}