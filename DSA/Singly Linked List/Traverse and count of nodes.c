#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


void count_no_of_nodes(struct node *head)
{
	int count=0;
	if(head==NULL)
	{
		printf("Linked list is empty");
	}
	struct node *ptr = NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	printf("No of nodes: %d", count);
	

}

int main()
{
	struct node *head = malloc(sizeof(struct node));
	head->data=10;
	head->next=NULL;
	
	struct node *curr = malloc(sizeof(struct node));
	curr->data=20;
	curr->next= NULL;
	head->next=curr;
	
	curr = malloc(sizeof(struct node));
	curr->data=30;
	curr->next=NULL;
	head->next->next=curr;
	
	curr = malloc(sizeof(struct node));
	curr->data=40;
	curr->next=NULL;
	head->next->next->next=curr;
	count_no_of_nodes(head);
	
	return 0;
}

