/*
    C++ class implementation of the stack using linked list
*/
#include<iostream>

// node class
class Node {
public:
    int data;
    Node *next;
};

// stack class
class Stack {
private:
    Node *top;
public:
    Stack() { top = NULL; } // No args constructor
    void push(int x);
    int pop();
    void Display();
};

// push function
void Stack::push(int x)
{
    // create a new node
    Node *t = new Node;

    // check if the stack is full
    if(t == NULL)
    {
        std::cout << "Stack is full\n";
    } else {
        // the stack is not full
        // enter data
        t->data = x;
        t->next = top;
        top = t;
    }
}

// pop function
int Stack::pop()
{
    int x = -1;
    // check if stack is not empty
    if(top == NULL) {
        std::cout << "Stack is empty\n";
    } else {
        // get the top data
        x = top->data;

        // get a pointer to the node that has to be deleted
        Node *t = top;

        // change the position of top pointer
        top = top->next;

        // delete/free the t pointer
        delete t;
    }
    return x;
}

// display function
void Stack::Display()
{
    Node *p = top;
    while(p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.Display();

    std::cout << stk.pop() << std::endl;

    stk.Display();
        
    return 0;
}