#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    Node *nextNode;
} Node;

int main() {
    Node* head = NULL;

    Node* firstNode = (Node*)malloc(sizeof(Node));
    
    firstNode->nextNode = NULL;
    firstNode->data = 20;
    head->nextNode = firstNode;

    Node* secNode = (Node*)malloc(sizeof(Node));

    secNode->nextNode = NULL;
    secNode->data = 30;
    firstNode->nextNode = secNode;
    
}