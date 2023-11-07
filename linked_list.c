// Implementing linked list in C


#include<stdio.h>
#include<stdlib.h>

// Creating the node
struct Node
{
	int data;
	struct Node *next;
} *first;

// create_node takes array and number of elements
void create_node(int A[], int n)
{
	int i; //for iterator
	struct Node *t; // Temporary node pointer
	struct Node *last; // Pointing to last node
	// declaring first node
	first = (struct Node*) malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;


	// Loop to get data from the array
	// Starting i = 1 as 0th element is already added
	for(i = 1; i < n; i++)
	{
		// creating a declaring temporary node
		t = (struct Node*) malloc(sizeof(struct Node));
		// adding the data
		t->data = A[i];
		t->next = NULL;
		last->next = t; // didn't get this line**
		last = t; // pointing last towards t
	}
}

// display linked list using loop
void display_linkedlist(struct Node *p)
{
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

// display linked list using recursion
void display_recursive(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d\n", p->data);
		display_recursive(p->next);
	}
}

int main()
{
	int A[] = {3, 4, 6, 1, 7, 9};
	create_node(A, 6);
	display_linkedlist(first);
	printf("Display recursively\n");
	display_recursive(first);
	return 0;
}
