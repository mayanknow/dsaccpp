/*

    program to evaluate postfix expression

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 1. create Stack
struct Stack{
    int size;
    int top;
    char* S;
};

// 2. create Node
struct Node {
    int data;
    struct Node* next;
}*top = NULL;

// 3. push(char x) create node, allocate, if not fill, t->data = x, t->next = top
// top = t;
void push(int x)
{
    struct Node* t;
    t = (struct Node*) malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next =top;
        top = t;
    }
}

//  4. pop if not null, t = top, top=t->next, x=t->data, free(t)
int pop()
{
    struct Node* t;
    int x = -1;

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

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}

// 5. stack top if not null, return top->data
char stackTop()
{
    if(top == NULL) {
        return '0';
    }
    return top->data;
}

// 6. display while p!=null, print
void Display()
{
    struct Node* p;
    p = top;
    while(p != NULL) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

// function to evaluate postfix expression
int Eval(char* postfix)
{
    int i = 0;
    int x1, x2, r;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        // check if the char is an operand
        if(isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char* postfix = "234*+82/-";
    printf("Result is %d\n", Eval(postfix));
    return 0;
}
