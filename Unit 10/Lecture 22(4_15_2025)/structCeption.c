#include<stdio.h>
#include<stdbool.h>

typedef struct date {
    int month;
    int day;
    int year;
} date;

typedef struct event {
    char title[20];
    date eventDate;
} event;

int main() {
    event newEvent;
    printf("Enter an event name:\n");
    scanf("%s", newEvent.title);
    printf("\nEnter month number of %s: ", newEvent.title);
    scanf("%d", &newEvent.eventDate.month);
    printf("\nEnter day number of %s: ", newEvent.title);
    scanf("%d", &newEvent.eventDate.day);
    printf("\nEnter year number of %s: ", newEvent.title);
    scanf("%d", &newEvent.eventDate.year);
    
    printf("\nThe event %s is on %d/%d/%d", newEvent.title, newEvent.eventDate.month, newEvent.eventDate.day, newEvent.eventDate.year);
}
