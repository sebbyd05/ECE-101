#include<stdio.h>

void multDiv(int x, int y, int* multed, float* dived) {
    *multed = x * y;
    *dived = (float)x / (float)y;
}

int main() {
    int x, y, mResult;
    float dResult;

    scanf("%d %d", &x, &y);
    multDiv(x, y, &mResult, &dResult);

    printf("%d * %d = %d, %d / %d = %.2lf\n", x, y, mResult, x, y, dResult);

    return 0;
}