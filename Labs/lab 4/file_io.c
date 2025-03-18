#include<stdio.h>

int main() {
    FILE *inFile;
    int bits, bytes, kBytes;

    inFile = fopen("data.txt", "r");

    if (inFile == NULL) {
        printf("File failed to open");
        return -1;
    }

    while (fscanf(inFile, "%d", &bits) != EOF) {
        printf("%d\t", bits);
        if (bits > 0) {
            printf("Data: ");
        }
        bytes = bits / 8;
        bits -= (bytes * 8);
        kBytes = bytes / 1024;
        bytes -= (kBytes * 1024);
        if (kBytes > 0) {
            printf("%d Kbytes ", kBytes);
        }
        if (bytes > 0) {
            printf("%d bytes ", bytes);
        }
        if (bits > 0) {
            printf("%d bits ", bits);
        }
        printf("\n");
    }
    
    return 0;

}