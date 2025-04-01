#include<stdio.h>
#include<string.h>

int main() {
    char name[100];
    char reverseName[100];
    int length;

    scanf("%s", name);
    length = strnlen(name, 100);

    for(int i = 0; i < length; i++) {
        reverseName[(length - (1 + i))] = name[i];
    }

    reverseName[length] = '\0';

    printf("Original name: %s\nReversed name: %s", name, reverseName);
}