#include<stdio.h>

void gradeDist(char letter, int *pA, int *pB, int *pC, int *pD) {
    if(letter == 'a' || letter == 'A') {
        *pA = *pA + 1;
    } else if(letter == 'b' || letter == 'B') {
        *pB = *pB + 1;
    } else if(letter == 'c' || letter == 'C') {
        *pC = *pC + 1;
    } else if(letter == 'd' || letter == 'D') {
        *pD = *pD + 1;
    }
}

int main() {
    int countA = 0, countB = 0, countC = 0, countD = 0, countTotal = 0;
    double percentA, percentB, percentC, percentD;
    char inLetter;

    while(1==1) {
        printf("Enter A/a, B/b, C/c or D/d (Q/q to stop): ");
        scanf("%c%*c", &inLetter);

        if (inLetter == 'q' || inLetter == 'Q') {
            break;
        } else {
            gradeDist(inLetter, &countA, &countB, &countC, &countD);
            printf("\n");
        }
    }

    //Calculate percentage makeup of grades
    countTotal = countA + countB + countC + countD;
    percentA = ((double)countA / (double)countTotal) * 100.0;
    percentB = ((double)countB / (double)countTotal) * 100.0;
    percentC = ((double)countC / (double)countTotal) * 100.0;
    percentD = ((double)countD / (double)countTotal) * 100.0;

    //Print results
    if(countTotal == 0) {
        printf("No grade entered\n");
    } else {
    printf("\nGrade");
    printf("\nA:\t%.2lf%%", percentA);
    printf("\nB:\t%.2lf%%", percentB);
    printf("\nC:\t%.2lf%%", percentC);
    printf("\nD:\t%.2lf%%\n", percentD);
    }

    return 0;
}