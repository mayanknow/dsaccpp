// implementing circular liknked list in C

#include<stdio.h>
#include<stdlib.h>

//  creating a structure Node
// declaring a head pointer
struct Node {
    int data;
    struct Node *next;
} *Head;

// function for creating circular linked list
void create_circular_LL(int A[], int n)
{
    // declaring an iterator
    int i;

    // creating a new node
    struct Node *t, *last;

    // alloating data and enter teh first value
    Head = (struct Node *) malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }

}

// displaying circular linkedlist
void Display(struct Node *p)
{
    // this is very different from printing a linear linked list
    do {
        printf("%d\n", p->data);
        p = p->next;
    } while(p != Head);
    
}

// displaying linkedlist using recursion
void Display_recursion(struct Node *p)
{
    static int flag = 0;
    if(p != Head || flag == 0) {
        flag = 1;
        printf("%d\n", p->data);
        Display_recursion(p->next);
    }
    flag = 0;    // flag must be zero at the end as it is a static variable cant be used unless
}

// insert in a circular linked list
void insert_circular(int value, int pos)
{
    // there will be two cases
    // 1. before the head node
    // 2. Anywhere else
    int i;
    struct Node *p;
    struct Node *t;

    // if the postion is first node
    if(pos == 0) {
        //  creating a new node t
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = value;
        // if list is empty
        if(Head == NULL) {
            Head = t;
            t->next = Head;
        } else {
            p = Head;
            // this will get the last node to link to the head node
            // if this is not impelement, infinite loop will form
            while(p->next != Head) {
                p = p->next;
            } // here the pointer has been reached to the last node
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        p = Head;
        // going to the postion where insert
        for(i = 0; i < pos-1; i++) {
            p = p->next;
        }
        // reached the certain pos
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
    



}

int main()
{
    int A[] = {1, 2, 4, 6, 8};
    create_circular_LL(A, 5);
    insert_circular(9, 0);
    Display(Head);
    return 0;
}