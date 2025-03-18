#include<stdio.h>

void fn(int a, int b, int* sum, int* diff) {
    *sum = a + b;
    *diff = a - b;
}

int main() {
    int x = 10, y = 5;
    fn(x,y, &x, &y);
    printf("X and Y is equal to %d\n", x);
    printf("X - Y is equal to %d", y);

    return 0;
}


