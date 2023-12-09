// Implementing linked list in C


#include<stdio.h>
#include<stdlib.h>

// Creating the node
struct Node
{
	int data;
	struct Node *next;
} *first;

// miscellinous(adding tab)
void tab()
{
	printf("\n--------------------------------------\n");
}

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

// display data and address using node pointer
void display_one(struct Node *p)
{
	if(p != NULL) {
		printf("data: %d -- addr: %p", p->data, &p);
	} else {
		printf("key not found...");
	}
}

// count the number of nodes in a linked list using loop
int count_nodes(struct Node *p)
{
	int counter = 0;
	while(p != NULL)
	{
		counter++;
		p = p->next;
	}

	return counter;
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

// find maximum number in the linke(non-recursive)
int max_LL(struct Node *p)
{
	// declared max as the least 32 bit number c compiler has
	int max = INT32_MIN;
	
	// checking till the last node hits
	while(p)
	{
		// comparing p->data with max
		// if number is bigger than max, set it to the new max
		if(p->data > max) {
			max = p->data;
		}
		// shifting p pointer to next node
		p = p->next;
	}

	return max;
}

// linear search in linked list
struct Node* search_LL(struct Node *p, int key)
{
	// traversing and checking if the element exist
	while(p != NULL) {
		if(p->data == key) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// linear search using recursion
struct Node* search_LL_recursive(struct Node *p, int key)
{
	if(p == NULL) {
		return NULL;
	}
	if(p->data == key) {
		return p;
	} else {
		return search_LL_recursive(p->next, key);
	}
}

// linear search improved using move to header/front
struct Node* search_LL_mvtohead(struct Node *p, int key)
{
	struct Node *q = NULL;

	while(p != NULL)
	{
		if(key == p->data) {
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
// fuction to insert a new node at certain location
void insert_new_node(struct Node *p, int index, int x)
{
	int i;
	struct Node *t;
	if(index < 0 || index > count_nodes(p)) {
		return; // this exit the function and take it back to the caller
	}

	// initializing new node
	// type casting to struct Node * pointer
	t = (struct Node *)malloc(sizeof(struct Node));

	// adding data to the node
	t->data = x;
	
	// for adding node in the front
	if(index == 0) {
		t->next = first;
		first = t;
	} else {

		// moving pointer p to the desired position
		for(i = 0; i < index-1; i++) {
			p = p->next;

		}
		// linking the node
		t->next = p->next;
		p->next = t;

	}
}

// inserting a new node at the last of linked list
void insert_last(struct Node *p, int x)
{
	// creating a temporary node t, allocating memory in heap and pointing t to it
	struct Node *t;
	struct Node *last;
	t = (struct Node *) malloc(sizeof(struct Node));
	// adding data
	t->data = x;
	// making data to null
	t->next = NULL;

	// if the linked list is empty
	if(first == NULL) {
		// point both first and last towards t
		first = last = t;
	} else {
		// get the last pointer and point its data to t
		// set last to t
		last->next = t;
		last = t;
	}

}

int main()
{
	int A[] = {};
	create_node(A, 0);
	// display_linkedlist(first);
	// printf("Display recursively\n");
	// display_recursive(first);
	// count_nodes(first);
	// printf("%d\n", count_nodes_recursion(first));
	// printf("%d\n", count_nodes_recursion_single_variable(first));
	// sum_LL(first);
	// printf("%d\n", max_LL(first));
	// display_one(search_LL(first, 22));
	// display_linkedlist(first);
	// display_one(search_LL_mvtohead(first, 9));
	// printf("\n -----------------\n");
	// display_linkedlist(first);
	// printf("\n -----------------\n");
	// display_one(search_LL_mvtohead(first, 7));
	// printf("\n -----------------\n");
	// display_linkedlist(first);
	insert_last(first, 4);
	insert_last(first, 11);
	display_linkedlist(first);
	return 0;
}
