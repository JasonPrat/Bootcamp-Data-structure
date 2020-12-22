#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    node *next;
} *head, *tail, *current;

node *createNode(int num) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int num) {
    node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    } 
}

void pushTail(int num) {
    node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    } 
}

void printList() {
    node *current = head;
    while (current) {
        printf("%d->", current->num);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    pushHead(3);
    pushHead(2);
    pushTail(4);
    pushTail(5);
    printf("Number after sorted: ");
    printList();
    return 0;
}