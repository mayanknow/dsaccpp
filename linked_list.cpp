// conversion of linked list c program(monolith) to c++(object oriented)
#include<iostream>

// Node class having data and addr as data members
class Node {
public:
    int data;
    Node *next;
};

// class LinkedList having first node
class LinkedList {
// making first node private as only the object can modify it
private:
    Node *first;
public:
    // constructor and destructors
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    int Length();
};

// creating a linked list using constructor
LinkedList::LinkedList(int A[], int x) {
    Node *last, *t;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < x; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

LinkedList::~LinkedList() {
    // making a node pointer p for deletion purpose
    Node *p = first;
    while(first) {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display() {
    Node *p = first;

    while(p != NULL) {
        std::cout << p->data << "\n";
        p = p->next;
    }
}

int LinkedList::Length() {
    Node *p = first;
    int counter = 0;

    while(p) {
        counter++;
        p = p->next;
    }

    return counter;
}

void LinkedList::Insert(int index, int x) {
    Node *t, *p = first;

    if(index < 0 || index > Length()) {
        return;
    }

    t = new Node;
    t->data = x;
    t->next = NULL;

    if(index == 0) {
        first = t;
    } else {
        for(int i = 0; i < index-1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void LinkedList::Delete(int index) {
    int counter = 0;
	struct Node *p = first, *q = NULL;
	// make p pointer move till location
	// make q pointer follow
	if(index == 0) {
		std::cout << "invalid location, element starts from 1\n";
		return;
	}
	if(index == 1) {
		first = first->next;
		delete p;
	} else {
		if(index > Length()) {
			std::cout << "invalid location\n";
			return;
		}
		while(p  && counter < index-1)
		{
			q = p;
			p = p->next;
			counter++;
		}
		q->next = p->next;
		delete p;
	}
}

int main()
{
    int A[] = {1, 2, 4, 5, 6 };
    LinkedList l(A, 5);

    l.Insert(2, 5);
    l.Delete(5);
    l.Display();

    return 0;
}