#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    int repeatedTimes = 1;

    printf("Enter data stream: ");
    scanf("%s", input);

    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] >= '0' && input[i] <= '9') {
            printf("%c", input[i]);
        } else {
            if(input[i] == input[(i + 1)]) {
                repeatedTimes++;
            } else {
                if(repeatedTimes == 1) {
                    printf("%c", input[i]);
                } else {
                    printf("%d%c", repeatedTimes, input[i]);
                    repeatedTimes = 1;
                }
            }
        }
    }

    return 0;

}