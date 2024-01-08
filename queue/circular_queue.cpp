#include<iostream>

#include "./include/queue.hpp"

void Queue::enqueue(int x)
{
    if((rear + 1) % size == front)
    {
        std::cout << "Queue is full" << std::endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if(front == rear)
    {
        std::cout << "Queue is empty" << std::endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::Display()
{
    int i = front + 1;
    do {
        std::cout << Q[i] << std::endl;
        i = (i + 1) % size;
    } while(i != (rear + 1) % size);
}

int main()
{
    Queue q('c', 7);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.Display();

    std:: cout << "---------------------------------" << std::endl;

    q.dequeue();
    q.dequeue();
    q.Display();


    return 0;
}