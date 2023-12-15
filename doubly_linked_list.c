// impelementation of doubly linked list in c

#include<stdio.h>
#include<stdlib.h>

// creating a node struct for doubly linked list
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void CreateDll(int A[], int n)
{
    struct Node *t, *last;
    int i;

    // creating first node and allocating space
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    // adding other values
    for(i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// display linked list
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// length of doubly linked list
int LengthDll(struct Node *p)
{
    int counter = 0;
    while(p != NULL)
    {
        counter++;
        p = p->next;
    }

    return counter;
}

// insert a new element in an index
// ** revisit later **
void InsertDll(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > LengthDll(p)) return;

    if(index == 0) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for(i = 0; i < index-1; i++) {
            p = p->next;
        }
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = x;

        t->prev = t;
        t->next = p->next;
        if(p->next) p->next->prev = t;
        p->next = t;
    }

}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    CreateDll(A, 5);
    InsertDll(first, 0, 25);
    Display(first);
    return 0;
}