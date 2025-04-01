#include<stdio.h>
//We need this for it to understand strings
#include<string.h>

int main() {
    //Define the string array
    char string[] = {"Hello World"};
    char string2[100];

    //If no spaces
    //scanf("%s", string2);

    //If spaces (there's a way with scanf but its obtuse)
    fgets(string2, 100, stdin);

    //Use %s for printing a string.
    printf("%s", string2);

    //Or you can print one charecter
    printf("%c", string2[0]);

}