#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert_begin(struct node **head, int d)
{
	struct node *ptr = malloc(sizeof(struct node));
	
	ptr->data = d;
	ptr->next = NULL;
	
	ptr->next = *head;
	*head = ptr;
}

int main()
{
	struct node *head = malloc(sizeof(struct node));
	head->data=10;
	head->next=NULL;
	
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data=20;
	ptr->next= NULL;
	head->next=ptr;
	
	head->next=ptr;
	
	int data = 15;
		
	insert_begin(&head, data);
	ptr = head;
	while(ptr!=NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	return 0;
}

