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

// count the number of nodes in a linked list using loop
void count_nodes(struct Node *p)
{
	int counter = 0;
	while(p != NULL)
	{
		counter++;
		p = p->next;
	}

	printf("%d\n", counter);
}

// count the number of nodes in a linked list using recursion
int count_nodes_recursion(struct Node *p)
{
	if(p == NULL)
	{
		return 0;
	} else {
		return count_nodes_recursion(p->next) + 1;
	}
}

// count the number of nodes in a linked list using recursion counter variable
int count_nodes_recursion_single_variable(struct Node *p)
{
	int counter = 0;
	if(p)
	{
		counter = count_nodes_recursion_single_variable(p->next);
		return counter + 1;
	} else {
		return counter;
	}

}

// sum of all elements in a linked list using loop
void sum_LL(struct Node *p)
{
	// sum counter;
	int sum = 0;

	// while loop with continuation condition
	while(p)
	{
		sum += p->data;
		p = p->next;
	}

	printf("Sum is: %d\n", sum);
}

// sum of all elements in a linked list using recursion
int sum_LL_recursion(struct Node *p)
{
	// termination condition
	if(p == NULL)
	{
		return 0;
	} else {
		return p->data + sum_LL_recursion(p->next);
	}
}

// find maximum number in the linke

int main()
{
	int A[] = {3, 4, 6, 1, 7, 9};
	create_node(A, 6);
	// display_linkedlist(first);
	// printf("Display recursively\n");
	// display_recursive(first);
	// count_nodes(first);
	// printf("%d\n", count_nodes_recursion(first));
	// printf("%d\n", count_nodes_recursion_single_variable(first));
	// sum_LL(first);
	printf("%d\n", sum_LL_recursion(first));
	return 0;
}
