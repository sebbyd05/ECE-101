#include<stdio.h>
#include<string.h>

void appendString(char string[], char appendix[]) {
    int originalLength, appendixLength;

    //if(sizeof(string) < (strlen(string) + strlen(appendix) + 1)) { (This doesn't work :( )
    //    return;
    //}
    
    
    originalLength = strlen(string);
    appendixLength = strlen(appendix);

    for(int i = originalLength; (i - originalLength) < appendixLength; i++) {
        string[i] = appendix[(i - originalLength)];
    }
}

int main() {
    char string[50] = "Hello ";
    char appendix[50] = "world";
    
    //Manually creating a function
    //appendString(string, appendix);

    //Using strcat
    strcat(string, appendix);
    
    printf("%s", string);

    return 0;
}