#include<stdio.h>
#include<string.h>

void sortArray(int array[], int size) {
    int smallestSeen;
    int temp;
    for(int i = 0; i < (size - 1); i++) {
        smallestSeen = i;
        for(int j = i + 1; j < size; j++) {
            if(array[j] < array[smallestSeen]) {
                smallestSeen = j;
            } 
        }
        temp = array[i];
        array[i] = array[smallestSeen];
        array[smallestSeen] = temp;
    }
}

int main() {
    int size = 0;
    
    //Ask the user how big to make the array beforehand
    while(1==1) {
        printf("Enter the number of elements:\n");
        scanf("%d", &size);
        if(size == 0) {
            printf("Number of elements must be greater than 0.\n");
        } else {
            break;
        }
    }

    //Create the array using that size
    int array[size];
    
    //Prompt the user for array values
    printf("Enter %d elements: ", size);
    
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    sortArray(array, size);

    //Print the results
    printf("The sorted array is: {%d", array[0]);
    for(int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("}");
    printf("\nSmallest item: %d\nLargest item: %d\n", array[0], array[(size-1)]);

}