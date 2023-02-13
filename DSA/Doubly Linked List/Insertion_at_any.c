#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertLast(struct Node** head, int data);
void insertStart(struct Node** head, int data);

int calcSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}
void insertPosition(int pos, int data, struct Node** head)
{
    int size = calcSize(*head);

    if(pos < 0 || size < pos) 
    {
        printf("Invalid position\n"); 
        return; 
    } 
    if(pos == 0) 
        insertStart(head, data); 

    else if(pos == size) 
        insertLast(head, data); 

    else { 
        struct Node* temp = *head; 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 

        newNode->data = data;
        newNode->next = NULL;

        while(--pos)
            temp=temp->next;
        
        struct Node* temp2 = temp->next;
        
        newNode->next= temp->next;
        
        newNode->prev = temp;
       
        temp->next = newNode;
        
        temp2->prev = newNode;
       
    }
}

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
    printf("Before Insertion\n ");
    
    while (node != NULL) { 
        printf(" %d ", node->data); 
        end = node;
        node = node->next; 
    }

    printf("\nAfter Insertion\n");

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

    insertPosition(1,25,&head);
  
    display(head); 
    return 0; 
}
