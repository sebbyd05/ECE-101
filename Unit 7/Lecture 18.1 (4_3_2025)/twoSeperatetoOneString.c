#include <stdio.h>
#include <string.h>
int main() {
    char s1[100], s2[100], combined[200];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);           
    // Step 1: copy string 1 to the new combined string
    strcpy(combined, s1);
    // Step2: add a space (optional)
    strcat(combined, " ");
    // Step 3: add S2 after S1 in the new combined string
    strcat(combined, s2);
    
    printf("Combined: %s\n", combined); 
    printf("Length of combined: %lu\n", strlen(combined)); 
return 0;
}
