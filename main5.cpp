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
void nth(int n){
    node *main = head ;
    node *ref = head ;
    int count = 0; 
    if(head != NULL) { 
        while( count < n ) { 
            if(ref == NULL) { 
                printf("%d is not in the number of nodes in list\n", n); 
                return; 
            } 
            ref = ref->next; 
            count++; 
        } 
        if(ref == NULL) { 
            head = head->next; 
            if(head != NULL) 
                printf("Node number %d from last is %d \n", n, main->num); 
        }
        else { 
            while(ref != NULL) { 
                main = main->next; 
                ref = ref->next; 
            } 
            printf("Node number %d from last is %d \n", n, main->num); 
        } 
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
    pushhead (20);
    pushhead (4);
    pushhead (15);
    pushhead (35);
    pushtail (45);
    pushtail (65);
    pushtail (55);
    print();
    nth(4);
}