#include<stdio.h>
//We need this for it to understand strings
#include<string.h>

int main() {
    //Define the string array
    char string2[100];
    int y, size, length;

    //If spaces (there's a way with scanf but its obtuse)
    fgets(string2, 100, stdin);

    //There is a function to find the size of a string
    size = sizeof(string2);

    //You can find string length too!!
    length = strnlen(string2, 100);
    
    //You can set an int to the value of a charecter, but it's going to be its ASCI value
    y = string2[0];

    printf("Size: %d\nLength: %d", size, length);

}