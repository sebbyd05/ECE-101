#include<stdio.h>

int main() {
    int V = 101;
    unsigned int *P = (unsigned int *) &V;
    printf("%d", *P);

    return 0;
}