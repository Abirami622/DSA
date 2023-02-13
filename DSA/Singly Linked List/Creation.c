#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main(){
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
	
	return 0;
}

