#include <stdio.h>
#define size 5
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1 ; i++) {               // outer loop for passes
        for (int j = 0; j < n - i-1 ; j++) {       // inner loop for comparisons
            if (arr[j] > arr[j + 1]) {              // swap if out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                  printArray(arr, size);
            }
        }
    }
}




int main() {
    int arr[] = {64, 25, 12, 22, 11};
    
    printf("Original array: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array (ascending): ");
    printArray(arr, size);

    return 0;
}
