#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    node *next;
} *head, *tail;
node *createnode(int num){
    node *newnode=(node*)malloc(sizeof(node));
    newnode -> num = num;
    newnode -> next = NULL;
    return newnode;
}
void pushhead (int num){
    node *temp = createnode(num);
    if (!head){
        head = tail = temp;
    }
    else{
        temp -> next = head;
        head = temp;
    }
}
void pushtail (int num){
    node *temp = createnode (num);
    if (!head){
        head = tail = temp;
    }
    else {
        tail-> next = temp;
        tail = temp;
    }
}
void printLinkedlist (){
    node *curr = head;
    while (curr){
        printf (" %d",curr -> num);
        curr = curr->next;
    }
}
void duplicate (){
    node *curr = head;
    node *next_next;
    if (curr == NULL){
        return;
    }
    while (curr -> next != NULL){
        if (curr -> num == curr -> next -> num ) {
            next_next = curr -> next -> next;
            free (curr -> next);
            curr -> next = next_next;
        }
        else {
            curr = curr -> next;
        }
    }
}

int main (){
    pushhead (19);
    pushhead (19);
    pushhead (17);
    pushhead (17);
    pushtail (21);
    pushtail (21);
    pushtail (23);
    pushtail (23);
    printf ("Before Duplicate removal:");
    printLinkedlist ();
    puts("");
    duplicate ();
    printf ("After Duplicate Removal:");
    printLinkedlist ();
}
