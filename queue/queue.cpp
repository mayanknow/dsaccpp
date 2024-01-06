#include<iostream>

#include "./include/queue.hpp"

void Queue::enqueue(int x)
{
    if(rear == size-1) {
        std::cout << "Queue full" << std::endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(front == rear) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        x = Q[front];
        front++;
    }
    return x;
}

void Queue::Display()
{
    for(int i = front+1; i <= rear; i++)
    {
        std::cout << Q[i] << std::endl;
    }
    std::cout << std::endl;

}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.Display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.Display();

    return 0;
}