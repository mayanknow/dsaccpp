#include<stdio.h>
#include<stdlib.h>

// struct Queue
// As this is an array, so the front and rear are the position
// of the elements in the array
struct Queue {
    int size;
    int front;
    int rear;
    int* Q;
};

// create a queue
void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *) malloc(q->size*sizeof(int));
}

// enqueue function
// this function add the elements in the queue
void enqueue(struct Queue* q, int x)
{
    // check if the queue is full
    // rear element is equal to the size
    if(q->rear == q->size-1)
    {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// dequeue function
// remove the first element of 
int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// display queue
void Display(struct Queue q)
{
    int i;
    for(i = q.front+1; i <= q.rear; i++)
    {
        printf("%d\n", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 30);

    Display(q);

    printf("\nDequeued: %d\n", dequeue(&q));

    enqueue(&q, 80);

    Display(q);

    return 0;
}