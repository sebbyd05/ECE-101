#include<stdio.h>

int main() {
    FILE *inFile = NULL;
    FILE *outFile = NULL;
    double minGrade, maxGrade, totalGrade, averageGrade, gradeIn;
    int gradeCount = 0;

    inFile = fopen("grades.txt", "r");
    outFile = fopen("stats.txt", "w");

    if (inFile == NULL) {
        printf("The input file failed to open!");
        return -1;
    }

    while(fscanf(inFile, "%lf", &gradeIn) != EOF) {
        gradeCount += 1;
        totalGrade +=gradeIn;
        if (gradeIn > maxGrade) {
            maxGrade = gradeIn;
        }
        if (gradeIn < minGrade) {
            minGrade = gradeIn;
        }
    }

    averageGrade = totalGrade / gradeCount;

    fprintf(outFile, "The class average was equal to %.1lf", averageGrade);
    fprintf(outFile, "The maximum score was equal to %.1lf", )
}