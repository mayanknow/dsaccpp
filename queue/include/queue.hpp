#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
private:
    int front;
    int rear;
    int size;
    int* Q;
public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    };
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};

#endif