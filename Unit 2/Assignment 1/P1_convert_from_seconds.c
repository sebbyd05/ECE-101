#include <stdio.h>

int main(void) {
   int seconds;
   int minutes;
   int hours; 
   int inTime, postHr;
   
   //Get Input
   scanf("%d", &inTime);

   //Perform math
   hours = inTime / 3600;
   postHr = inTime - (3600 * hours);
   minutes = postHr / 60;
   seconds = postHr - (60 * minutes);

   //Print result
   printf("Hours: %d", hours);
   printf("\nMinutes: %d", minutes);
   printf("\nSeconds: %d\n", seconds);
   
   return 0;
}