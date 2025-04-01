#include<stdio.h>
#include<string.h>

int main() {
    char sentence[200];
    int vowels = 0, constanents = 0, chars;

    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    chars = strnlen(sentence, 200);

    for(int i = 0; i < chars; i++) {
        if((sentence[i] >= 'A' || sentence[i] <= 'Z') || (sentence[i] >= 'a' || sentence[i] <= 'z')) {
            if(sentence[i] == 'a' || sentence[i] == 'A' || sentence[i] == 'e' || sentence[i] == 'E' || sentence[i] == 'i' || sentence[i] == 'I' || sentence[i] == 'o' || sentence[i] == 'O' || sentence[i] == 'u' || sentence[i] == 'U') {
                vowels++;
            } else {
                constanents++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", constanents);
}