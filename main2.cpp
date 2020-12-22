#include <stdio.h>
#include <stdlib.h>
struct node {
    int num,flag;
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
int detectcycle(node *k){
    while (k!=NULL){
        if (k->flag ==1){
            return 1;
        }
        k-> flag = 1;
        k = k -> next;
    }
    return 0;;
}
int main (){
    pushhead(20);
    pushhead(4);
    pushhead(15);
    pushhead(10);
    pushtail(40);
    pushtail(45);
    head -> next -> next -> next -> next = head;
    if (detectcycle(head)==1){
        printf ("Cycle was found");
    }
    else{
        printf("Cycle wasn't found");
    }
}