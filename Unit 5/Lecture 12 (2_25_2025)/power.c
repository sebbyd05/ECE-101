#include<stdio.h>

int thing(int x, int y) {
    int outResult = x;
    int i;

    for (i=1; i < y; i++) {
        outResult *= x;
    }

    return outResult;
}

int main() {
    int finalResult;

    finalResult = thing(7,3);
    
    printf("%d", finalResult);

    return 0;
}



