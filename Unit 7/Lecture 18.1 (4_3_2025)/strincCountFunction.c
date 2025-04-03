#include<stdio.h>
#include<string.h>

int countChar(char string[]) {
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int main() {
    char string[] = "Hello world";

    printf("The string length is: %d", countChar(string));
}