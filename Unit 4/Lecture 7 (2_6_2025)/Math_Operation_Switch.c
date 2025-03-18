#include <stdio.h>

int main(void) {
    double x, y;
    char op;
    printf("Enter 2 real number: ");
    scanf("%lf%lf", &x, &y);
    printf("Enter an operator (+,-,*,/): ");
    scanf("%*c%c", &op);
    printf("%.3lf %c %.3lf = ", x, op, y);

    switch(op) {
        case '+':
            printf("%.3lf\n", x + y);
            break;
        case '-':
            printf("%.3lf\n", x - y);
            break;
        case '*':
            printf("%.3lf\n", x*y);
            break;
        case '/':
            printf("%.3lf\n", x / y);
            break;
        default:
            printf("wrong operator\n");
    }

    return 0;
}