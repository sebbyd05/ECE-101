#include<stdio.h>

int main(void){
    int var1, var2;

    // declare two pointers name pt1 and pt2 of type integer
    int *pt1, *pt2;
    
    // point pt1 to var1 and pt2 to var2
    pt1 = &var1;
    pt2 = &var2;

    // change the value of var1 to 10 via pt1
    *pt1 = 10;

    // change the value of var2 to var1 + 10 via pt1, pt2 
    *pt2 = *pt1 + 10;
    // print the values of var1 and var2 (var1 via the pointer)
    printf("%d, %d", *pt1, var2);
    // print the addresses of var1, var2 and pt1.    
    printf("\n%d, %d, %d", &var1, &var2, pt1);
    
    return 0;
}