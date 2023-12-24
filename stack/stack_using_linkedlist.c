// for the array part, I added elements from the right side
// this time we'll use the very left side
#include<stdio.h>
#include<stdlib.h>

/*
    empty condition 
    if(top == NULL)

    full condition
    Node *t = new Node;
    if(t == NULL)

*/

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

// function to push
void push(int x)
{
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));

    if(t == NULL)
    {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// pop function
int pop()
{
    int x = -1;
    struct Node *t;
    if(top == NULL)
    {
        printf("Stack is empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// display function
void Display()
{
    struct Node *p;
    p = top;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    printf("%d \n", pop());

    Display();
    return 0;
}