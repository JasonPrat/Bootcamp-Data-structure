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
void mid(){
    node *low = head ;
    node *high = head ;
    if (head!=NULL){
        while (high != NULL && high->next != NULL){
            high = high->next->next;
            low = low->next;
        }
        printf ("THe middle Element of the given linked list is %d\n",low->num);
    }
}
void print(){
    node *curr = head;
    while (curr){
        printf ("%d->",curr -> num);
        curr = curr->next;
    }
    printf ("NULL\n");
}

int main (){
    
    for (int i=10;i>0;i--){
        printf ("Linked list:");
        pushtail(i+5);
        pushhead(i+5);
        print();
        mid();
    }
    
}
