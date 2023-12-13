// Implementing linked list in C


#include<stdio.h>
#include<stdlib.h>

// Creating the node
struct Node
{
	int data;
	struct Node *next;
} *first, *second, *third;

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

// create_node second
void create_node2(int A[], int n)
{
	int i; //for iterator
	struct Node *t; // Temporary node pointer
	struct Node *last; // Pointing to last node
	// declaring first node
	second = (struct Node*) malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;


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

// insert elements in a sorted liked list
void inser_sorted_LL(struct Node *p, int x)
{
	// create two pointers, one for node and one chasing pointer
	// set pointer q to null
	struct Node *t, *q = NULL;

	// allocalte space for t
	t = (struct Node *) malloc(sizeof(struct Node));

	// add data to t and set t->next to NULL
	t->data = x;
	t->next = NULL;

	// check if the list is empty
	if(first == NULL) {
		first = t;
	} else {
		// get pointer to reach x < data pointer value
		while(p && p->data < x)
		{
			// use referencing fist and then move the pointer
			q = p;
			p = p->next;
		}
		//check if p is the first node
		// the ** is used when only one node is present
		// to add before the one node, t->next should be pointed at first addr
		// and first should be pointed to t
		if(p == first) {
			t->next = first; // **
			first = t;
		} else {
			t->next = q->next;
			q->next = t;
		}	
	}
}

// deleting first node of a linked list
void delete_first()
{
	// create a node * pointing to first node
	struct Node *p = first;

	//changing first node pointing to second node
	first = first->next; // same as first = p->next as they both are same
	printf("-----number deleted %d-------\n", p->data);
	free(p);

}

void delete_nth_LL(struct Node *p, int loc)
{
	int counter = 0;
	struct Node *q = NULL;
	// make p pointer move till location
	// make q pointer follow
	if(loc == 0) {
		printf("invalid location, element starts from 1\n");
		return;
	}
	if(loc == 1) {
		p = first;
		first = first->next;
		free(p);
	} else {
		if(loc > count_nodes(first)) {
			printf("invalid location\n");
			return;
		}
		while(p  && counter < loc-1)
		{
			//printf("%d", p->data);
			q = p;
			p = p->next;
			counter++;
		}
		q->next = p->next;
		free(p);
	}
}

// check whether linked list is sorted or not
int isLL_sorted(struct Node *p)
{
	if(count_nodes(first) < 2) {
		printf("only one element present\n");
		return 1;
	}
	// setting max as the least possbile integer
	int min = INT32_MIN;
	while(p)
	{
		// writing the failure condition instead of passing
		// in sorted list p->data have to be greater than ">" min
		// check opposite p->data < min
		if(p->data < min) {
			return 2;
		}
		// setting min as the value p->data has
		min = p->data;
		p = p->next;
	}
	// return 1 = sorted
	// return 2 = not sorted
	return 1;
}

// delete all the elements in a sorted linked list
void delete_duplicates_sortedLL()
{
	struct Node *p = first;
	struct Node *q = first->next;

	// check if list is sorted
	if(isLL_sorted(first) != 1) {
		printf("list is not sorted\n");
		return;
	}
	// traverse thru the linked list
	while(q != NULL)
	{
		if(q->data != p->data)
		{
			p = q;
			q = q->next;
		} else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		
	}
}

// reverse linked list
// using array
void reverseLL_array(struct Node *p)
{
	// creating an array in heap
	// **** important ****
	int *A;
	A = (int *) malloc(sizeof(int)*count_nodes(first));
	int i = 0;
	// adding all the values in an array
	while(p != NULL)
	{
		// adding p->data into the array
		A[i] = p->data;
		p = p->next;
		i++;
	}
	// pointing p towards first node and decrement the i
	// i got out of bounds
	p = first;
	i--;

	// looping throught the array in reverse order
	while(p != NULL)
	{
		// changing p->data from reverse array
		p->data = A[i];
		i--;
		p = p->next;
	}
}

// reverse linked list
// sliding pointer
void reverseLL_sliding_pointers()
{
	// get three pointers p, q and r
	// set p and r to null
	struct Node *p = first;
	struct Node *q = NULL;
	struct Node *r = NULL;

	// looping through the linkedlist until null pointer
	while(p != NULL)
	{
		// make the pointers follow each other r<-q<-p->next
		r = q;
		q = p;
		p = p->next;
		// linking the middle pointer to the last pointer addr eg. r<-q q->next = r
		q->next = r;
	}
	first = q;
}

// reversing linked list using recusrion
void reverseLL_recursion(struct Node *q, struct Node *p)
{
	if(p != NULL)
	{
		reverseLL_recursion(p, p->next);
		// this will be executed returning time
		p->next = q;
	} else {
		// point first towards q as list starts from here
		first = q;
	}
}

// concatinating linked list
// getting params as list a, b
void concatinationLL(struct Node *p, struct Node *q)
{
	// traversing node p till last
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	q = NULL;
}

// merge two sorted linked list
void merge2_sorted_LL(struct Node *f, struct Node *s)
{
	// first, second -> which is the comparison pointer
	// third -> points towards the first node of sorted & merged list
	// last -> points at last compared node and used for nullification

	// declaring required pointers
	struct Node *last;

	//starting the list
	// if second(s) data is bigger
	if(f->data < s->data)
	{
		third = last = f;
		f = f->next;
		last->next = NULL;
	} else {
		// if first(f) data is bigger
		third = last = s;
		s = s->next;
		last->next = NULL;
	}

	// looping and adding values untill one of first and last becames null
	// any of first and last becomming null means one of the node is empty
	while(f && s) {
		if(f->data < s->data)
		{
			// joining last with f
			last->next = f;
			// making f as last
			last = f;
			// moving f to next node
			f = f->next;
			// make last next to null
			last->next = NULL;
		} else {
			// joining last node to second
			last->next = s;
			// making second node as last
			last = s;
			// moving the last node a step
			s = s->next;
			// making last node poninting to null
			last->next = NULL;
		}
	}
	// one of the node must have been reached to the last pointer
	
	// if s has nulled(s == NULL)
	if(f) {
		// set the last node pointing to f
		last->next = f;
	}
	// if f has nulled(f == NULL)
	if(s) {
		// set the last node pointing to s
		last->next = s;
	}
}

// check whether the list contanins loop or not
void isLoop(struct Node *f)
{
	// make two pointer p and q pointing top first node
	struct Node *p, *q;
	
	// making all point at the first node
	p = q = f;

	// make a do while loop here
	// while condition until p and q are not null and not equal
	do {
		// move p one time and q two times
		p = p->next;
		q = q->next;

		// add q moving statements twice and check if (n != NULL)
		q = q ? q->next : q;
	} while (p && q && p != q);

	// if p and q gets equal
	if(p == q)
	{
		printf("is loop\n");
	} else {
		printf("not loop\n");
	}
}

int main()
{
	struct Node *t1, *t2;
	int A[] = {1, 4, 6, 7, 8, 9, 17};
	create_node(A, 7);

	// making a infinite linked list
	// t1 = first->next->next;
	// t2 = first->next->next->next->next->next;
	// t2->next = t1;
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
	// display_linkedlist(first);
	// tab();
	// inser_sorted_LL(first, 4);
	// inser_sorted_LL(first, 11);
	// display_linkedlist(first);
	// tab();
	// inser_sorted_LL(first, 3);
	// display_linkedlist(first);
	// tab();
	// display_linkedlist(first);
	// tab();
	// delete_nth_LL(first, 3);
	// display_linkedlist(first);
	// isLL_sorted(first);
	// display_linkedlist(first);
	// tab();
	// delete_duplicates_sortedLL();
	// display_linkedlist(first);
	// display_linkedlist(first);
	// tab();
	// display_linkedlist(second);
	// tab();
	// merge2_sorted_LL(first, second);
	// display_linkedlist(first);
	// tab();
	// // reverseLL_array(first);
	// reverseLL_recursion(NULL, first);
	// display_linkedlist(first);
	isLoop(first);
	return 0;
}
