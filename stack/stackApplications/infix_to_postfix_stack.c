/*
    infix to postfix using stack in c
*/
#include<stdio.h>
#include<stdlib.h>

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


// int isBalanced(char *exp)
// {
//     int i;

//     for(i=0; exp[i] != '\0'; i++)
//     {
//         if(exp[i] == '('  || exp[i] == '[' || exp[i] == '{') {
//             push(exp[i]);
//         } else if(exp[i] == ')'  || exp[i] == ']' || exp[i] == '}') {
//             if(top == NULL) {
//                 return 0;
//             }
//             if(exp[i] == ')' && stackTop() == '(') { pop(); }
//             else if(exp[i] == '}' && stackTop() == '{') { pop(); }
//             else if(exp[i] == ']' && stackTop() == '[') { pop(); }
//             else return 0;
//         }
//     }

//     return (top==NULL)?1:0;
//     // is balanced 1
//     // not balanced 0
// }

int main()
{
    char *exp = "{([1+(5-3)]*11)}";

    // printf("%s ", isBalanced(exp)?"Balanced":"Not balanced");
    Display();
    
    return 0;
}