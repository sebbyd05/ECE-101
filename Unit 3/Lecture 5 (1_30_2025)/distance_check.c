#include<stdio.h>
#include<math.h>

int main() {
    double y1, y2, x1, x2, yt, xt, z, zt;

    y1 = 1;
    y2 = 3;
    x1 = 1;
    x2 = 3;
    
    yt = y2 - y1;
    xt = x2 - x1;

    xt = pow(xt , 2);
    yt = pow(yt, 2);

    zt = xt + yt;
    z = sqrt(zt);
    
    if(z < 10) {
        printf("true");
    }

    return 0;
}