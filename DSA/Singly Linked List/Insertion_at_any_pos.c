#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

int getCurrSize (struct Node *node)
{
  int size = 0;

  while (node != NULL)
	{
      node = node->next;
      size++;
    }
  return size;
}

void insertPosition (int pos, int data, struct Node **head)
{
  int size = getCurrSize (*head);

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (pos < 0 || pos > size)
    printf ("Invalid position to insert\n");

  else if (pos == 0)
    {
      newNode->next = *head;
      *head = newNode;
    }

  else
    {
      struct Node *temp = *head;

      while (--pos)
	temp = temp->next;

      newNode->next = temp->next;
 
      temp->next = newNode;
    }
}

void display (struct Node *node)
{
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int main ()
{

  struct Node *head = NULL;
  struct Node *node2 = NULL;
  struct Node *node3 = NULL;
  struct Node *node4 = NULL;

  head = (struct Node *) malloc (sizeof (struct Node));
  node2 = (struct Node *) malloc (sizeof (struct Node));
  node3 = (struct Node *) malloc (sizeof (struct Node));
  node4 = (struct Node *) malloc (sizeof (struct Node));


  head->data = 10;	 
  head->next = node2;	

  node2->data = 20;
  node2->next = node3;

  node3->data = 30;
  node3->next = node4;

  node4->data = 40;
  node4->next = NULL;


  display (head);

  insertPosition (2, 15, &head);

  display (head);

  return 0;
}
