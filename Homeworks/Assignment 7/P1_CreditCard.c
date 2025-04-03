#include <stdio.h>
#include <string.h>

// Fill arrays with data from external file (described in another section. DO NOT MODIFY.)
void ReadCustomerData(char names[][25], char states[][25], double debts[], int size) {
  int n;
  FILE* dataFile = NULL;
  char dataFileName[25] = "CustomerData.tsv";
  // Open the data file
  dataFile = fopen(dataFileName, "r");
  if (dataFile == NULL) {
     printf("Could not open file %s for reading.\n", dataFileName);
     return;
  }

  // Read the customer information
  for (n = 0; n < size; n++) {
     fscanf(dataFile, "%s %s %lf", names[n], states[n], &debts[n]);
  }

  // Close the data file
  fclose(dataFile);
}

//Function that returns the memmory location of the highest debt of the entire dataset
int findHighestDebt(double debts[], int size) {
    //Variable to store the memmory location of the hightst debt
    int highestDebtMem = 0;

    //Begin scanning
    for(int i = 0; i < size; i++) {
        //Check if the debt cell that is being scanned is higher than the highest seen thus far
        if(debts[i] > debts[highestDebtMem]) {
            //Sets the location it will return later to the cell with a higher value
            highestDebtMem = i;
        }
    }

    //Return the highest value cell
    return highestDebtMem;
}


int main(void) {
   int size;
   int debtLimit, highestDebtMem;
   char firstLetter;
   char state[2];

   // Input # of customers and create parallel arrays
   scanf("%d", &size);
   char names[size][25];
   char states[size][25];
   double debts[size];

   // Fill arrays with data from external file (described in another section. DO NOT MODIFY.)
   ReadCustomerData(names, states, debts, size);

   // Input debt limit, search phrase, and state
    scanf("%d", &debtLimit);
    scanf("%c ", &firstLetter);
    scanf("%s", state);

    //Find the cell with the highest debt
    highestDebtMem = findHighestDebt(debts, size);

    //Print the findings
    printf("U.S. Report\n");
    printf("Customers: %d\n", size);
    printf("Highest debt: %s\n", names[highestDebtMem]);
   
   
    return 0;
}