#include<stdio.h> 
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertLast(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
        newNode->prev = NULL;
        return;
    }

    struct Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertStart(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    
    if(*head !=NULL)
        (*head)->prev = newNode;
        
    *head = newNode; 
}

void display(struct Node* node) 
{ 
    struct Node *end;
    printf("\nBefore insertion\n ");
    
    while (node != NULL) { 
        printf(" %d ", node->data); 
        end = node;
        node = node->next; 
    }

    printf("\nAfter insertion at end\n ");

    while (end != NULL) { 
        printf(" %d ", end->data); 
        end = end->prev; 
    }
}

int main()
{
    struct Node* head = NULL;
    
    insertStart(&head,50);
    insertStart(&head,60);
    insertStart(&head,70);

    insertLast(&head,40);
    insertLast(&head,30);
    insertLast(&head,20);
    insertLast(&head,10);
    
    display(head); 
    return 0; 
}
