/*
    infix to postfix using stack in c

    STEPS:
    1. init a stack
    2. create a postfix array in heap with length l+1
    3. create two interators i and j
    4. **loop until theend start**
    5. chck if the char is operant or not
    6. if operant add to postfix array and increment both
    7. else not operant check te precedence (op > stackTop) push and increment
    8. else push to array and increment
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// stack struct
struct Stack {
    int size;
    int top;
    char *S;    // this was initially int before
};

struct Node {
    char data;
    struct Node *next;
}*top = NULL;

// push
void push(char x)
{
    // craete a node t and allocate size
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));

    // check if t == NULL
    // stack is full
    if(t == NULL) {
        printf("Stack is full\n");
    } else {
        // else add data and move the pointer
        t->data = x;
        t->next = top;
        top = t;
    }    
}

// pop
char pop()
{
    struct Node *t;
    char x = -1;

    if(top == NULL) {
        printf("Stack is empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

char stackTop()
{
    if(top == NULL) {
        return '0';
    }
    return top->data;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// function to find precedence
int pre(char x)
{
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    else return 0;
}

// function to return if the char is operand or not
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}

char* IntToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    
    // array in heap to store postfix expression
    postfix = (char *) malloc((len+2)*sizeof(char));

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i])) {
            // if letter
            postfix[j++] = infix[i++];
        } else {
            // check the precedence
            if(top == NULL || pre(infix[i]) > pre(stackTop())) {
                // push in to stack
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = IntToPost(infix);
    printf("%s", postfix);
    
    return 0;
}

/*

dryrun


a + b * c      +- 1 div mul 2     
postfix arr = abc*+
st = +*



*/