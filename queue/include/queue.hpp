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
    Queue(char s, int size)
    {
        if(s == 'c')
        {
            front = rear = 0;
            this->size = size;
            Q = new int[this->size];
        } else {
            std::cout << "Wrong queue flag" << std::endl;
        }
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};

#endif