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

int main(void) {
   int size;

   // Input # of customers and create parallel arrays
   scanf("%d", &size);
   char names[size][25];
   char states[size][25];
   double debts[size];

   // Fill arrays with data from external file (described in another section. DO NOT MODIFY.)
   ReadCustomerData(names, states, debts, size);

   /* Type your code here */
   // Input debt limit, search phrase, and state

   return 0;
}