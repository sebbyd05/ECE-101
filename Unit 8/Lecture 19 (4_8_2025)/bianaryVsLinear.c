#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int size, int key) {
    // add linear search function
    for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search Function (for sorted arrays)
int binarySearch(int arr[], int size, int key, int *storeItration) {
    // binary search function
    int high = (size-1), low = 0, midPoint;
    while(high >= low) {
        midPoint=(high + low)/2;
        if(arr[midPoint] > key) {
            high = midPoint;
        } else if(arr[midPoint] < key) {
            low = midPoint;
        } else if(arr[midPoint] == key) {
            return midPoint;
        }

        *storeItration = (*storeItration + 1);
    }
    
    return -1;
}
#define size 20
int main() {
    // Larger sorted array
    int arr[] = {2, 5, 8, 12, 16, 23, 29, 34, 41, 45, 50, 54, 60, 65, 70, 75, 80, 85, 90, 95};
    int key = 90;
    int storeItration = 0;

    int linIterations = 0, binIterations = 0;

    int linIndex = linearSearch(arr, size, key, &linIterations);
    int binIndex = binarySearch(arr, size, key, &binIterations);

    printf("Linear Search: Found at index %d in %d iterations.\n", linIndex, linIterations);
    printf("Binary Search: Found at index %d in %d iterations.\n", binIndex, binIterations, &storeItration);

    return 0;
}
