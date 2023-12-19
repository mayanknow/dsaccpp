// stack using dynamic array
#include<stdio.h>
#include<stdlib.h>

// making stack struct
struct Stack {
    int size;
    int top;
    int *S;
};

void tab()
{
    printf("---------------\n");
}

// function to create a stack
void create(struct Stack *st)
{
    // getting user input for size
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);

    // setting top as -1 (empty)
    st->top = -1;

    // initialize a dynamic arrar and link it to the *s
    st->S = (int *) malloc(st->size*sizeof(int));

}

// function to create a stack
void display(struct Stack st)
{
    int i;
    for(i = st.top; i >= 0; i--)
    {
        printf("%d\n", st.S[i]);
    }
}

// function to push an element in stack
void push(struct Stack *st, int x)
{
    // check if stack is not full
    if(st->top == st->size-1)
    {
        printf("Stack overflow\n");
    } else {
        // increase the top pointer
        st->top++;

        // insert the element using the top pointer
        st->S[st->top] = x;

    }
}

// function to pop an element
int pop(struct Stack *st)
{
    int x = -1;

    // check if stack is empty
    if(st->top == -1)
    {
        printf("Stack underflow\n");
    } else {
        x = st->S[st->top--];
    }
    return x;
}

// function to display element at a specific index
int peek(struct Stack st, int index)
{
    int x = -1;
    // formula to find the position using the index
    // pos = top-index+1
    if(st.top-index+1 < 0)
    {
        printf("Invalid index\n");
    }
    x = st.S[st.top-index+1];
    return x;
}

// function tp check if the stack is empty
int isEmpty(struct Stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    return 0;
}

// function to check if the stack is full
int isFull(struct Stack st)
{
    return st.top == st.size-1;
}

// function to return topmost element
int stackTop(struct Stack st)
{
    // check if the stack is not empty
    if(!isEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}


int main()
{

    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);

    display(st);

    tab();

    push(&st, 30);
    push(&st, 40);

    display(st);
    tab();


    printf("%d", pop(&st));
    printf("%d", pop(&st));

    display(st);

    tab();

    printf("%d", peek(st, 2));

}