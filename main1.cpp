#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    node *next;
};
void pushhead(struct node** head_ref, int number) { 
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->num  = number; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
node* SortedMerge(node* a, node* b){ 
    node* result = NULL; 
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    if (a->num < b->num){ 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return(result); 
} 
void printlist (node *node){
    while (node != NULL){
        printf ("%d ",node -> num);
        node = node -> next;
    }
}
int main (){
    node *a=NULL;
    node *b=NULL;
    node *res =NULL;
    pushhead (&a,15);
    pushhead (&a,10);
    pushhead (&a,5);
    pushhead (&b,20);
    pushhead (&b,3);
    pushhead (&b,2);

    res = SortedMerge(a,b);
    printf ("Merged Linked list :");
    printlist(res);
}