#include<stdio.h>

int main() {
    float *p;
    float i=14.3;

    p = &i;
    i++;
    
    printf("%lf\n",p);
    printf("%lf\n",*p);
    printf("%lf\n",i);
    return 0;
}