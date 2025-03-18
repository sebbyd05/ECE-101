#include<stdio.h>
#include<math.h>
#include<string.h>

int main() {

    const double HOMEWORK_MAX = 800.0;
    const double QUIZZES_MAX = 400.0;
    const double MIDTERM_MAX = 150.0;
    const double FINAL_MAX = 200.0;

    char studentType, letterGrade;
    double homeworkPts, quizPts, midtermPts, finalPts, courseAvg;

    //Obtain User Input
    scanf("%c", &studentType);
    scanf("%lf", &homeworkPts);
    scanf("%lf", &quizPts);
    scanf("%lf", &midtermPts);
    scanf("%lf", &finalPts);

    //Make all percentages not over 100
    if (homeworkPts > HOMEWORK_MAX) {
        homeworkPts = homeworkPts - (homeworkPts - HOMEWORK_MAX);
    }
    if (quizPts > QUIZZES_MAX) {
        quizPts = quizPts - (quizPts - QUIZZES_MAX);
    }
    if (midtermPts > MIDTERM_MAX) {
        midtermPts = midtermPts - (midtermPts - MIDTERM_MAX);
    }
    if (finalPts > FINAL_MAX) {
        finalPts = finalPts - (finalPts - FINAL_MAX);
    }

    //Calculate Percentages
    homeworkPts = (homeworkPts / HOMEWORK_MAX) * 100.0;
    quizPts = (quizPts / QUIZZES_MAX) * 100.0;
    midtermPts = (midtermPts / MIDTERM_MAX) * 100.0;
    finalPts = (finalPts / FINAL_MAX) * 100.0;

    //Calculate Course Average
    if (studentType == 'U') {
        courseAvg = (homeworkPts * .2) + (quizPts * .2) + (midtermPts * .3) + (finalPts * .3);
    } else if (studentType == 'G') {
        courseAvg = (homeworkPts * .15) + (quizPts * .05) + (midtermPts * .35) + (finalPts * .45);
    } else if (studentType == 'D') {
        courseAvg = (homeworkPts * .05) + (quizPts * .05) + (midtermPts * .4) + (finalPts * .5);
    }

    //Calculate Letter Grade
    if (courseAvg < 60.0) {
        letterGrade = 'F';
    } else if (courseAvg >= 60.0 && courseAvg < 70.0) {
        letterGrade = 'D';
    } else if (courseAvg >= 70.0 && courseAvg < 80.0) {
        letterGrade = 'C';
    } else if (courseAvg >= 80.0 && courseAvg < 90.0) {
        letterGrade = 'B';
    } else {
        letterGrade = 'A';
    }

    //Output Results
    if (studentType == 'U' || studentType == 'D' || studentType == 'G') {
        printf("Homework: %.1lf%%\n", homeworkPts);
        printf("Quizzes: %.1lf%%\n", quizPts);
        printf("Midterm: %.1lf%%\n", midtermPts);
        printf("Final Exam: %.1lf%%\n", finalPts);
        printf("%c average: %.1lf%%\n", studentType, courseAvg);
        printf("Course grade: %c\n", letterGrade);
    } else {
        printf("Error: student status must be U, G or D\n");
    }
    
    return 0;
}