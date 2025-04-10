#include <stdio.h>
#define size 5
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void InsertionSort(int numbers[], int numbersSize) { 
	int j, temp; // Temporary variable for swap 
	for (int i = 1; i < numbersSize; ++i) { 
		j = i; // Insert numbers[i] numbers[i] in correct position 
		while (j > 0 && numbers [j] < numbers[j - 1]) { 
			// Swap numbers[j] and numbers[j - 1] 
			temp = numbers[j]; 
			numbers[j] = numbers[j - 1]; 
			numbers[j - 1] = temp; 
			printArray(numbers, numbersSize);
			--j; 
			}
			
		} 
	}



int main() {
    int arr[] = {64, 25, 12, 22, 11};
    printf("Original array: ");
    printArray(arr, size);
    InsertionSort(arr, size);
    printf("Sorted array (ascending): ");
    printArray(arr, size);
    return 0;
}
