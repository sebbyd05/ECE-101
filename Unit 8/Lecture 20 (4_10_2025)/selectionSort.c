#include <stdio.h>
#define size 5
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void SelectionSort(int numbers[], int numbersSize) { 
      int indexSmallest; 
      for (int i = 0; i < numbersSize - 1; ++i) { 
             // Find index of smallest remaining element 
             indexSmallest = i; 
             for (int j = i + 1; j < numbersSize; ++j) { 
                     if ( numbers[j] < numbers[indexSmallest] ) { 
                              indexSmallest = j; 
                     } 
             
              } // Swap array of index indexSmallest values 
             int temp = numbers[i]; 
             numbers[i] = numbers[indexSmallest]; 
             numbers[indexSmallest] = temp;
             printArray(numbers, size);
             
        }
 }


int main() {
    int arr[] = {64, 25, 12, 22, 11};
    printf("Original array: ");
    printArray(arr, size);
    SelectionSort(arr, size);
    printf("Sorted array (ascending): ");
    printArray(arr, size);
    return 0;
}
