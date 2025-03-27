#include<stdio.h>

int main() {
    char table[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int playerMove, playerRowSelect, playerColSelect;
    char playerTurn = 'X';

    while(1==1) {
        printf("| %c | %c | %c |\n", table[0][0], table[0][1], table[0][2]);  
        printf("+---+---+---+\n");  
        printf("| %c | %c | %c |\n", table[1][0], table[1][1], table[1][2]);   
        printf("+---+---+---+\n");  
        printf("| %c | %c | %c |\n", table[2][0], table[2][1], table[2][2]);  
    
        printf("Player %c's Turn, enter a row then a collumn", playerTurn);
        
    }

    
}