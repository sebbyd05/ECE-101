#include <stdio.h>
int linearSearchChar(const char str[], char target) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == target) {
            return i;
        }
    }
    return -1;
}
int main() {
    char word[] = "Gleem";
    char search_ch = 'm';
    int index = linearSearchChar(word, search_ch );
    if (index != -1)
        printf("Character '%c' found at index %d\n", search_ch , index);
    else
        printf("Character '%c' not found in the string.\n", search_ch );
    return 0;
}