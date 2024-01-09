#include<stdio.h>
#include<stdlib.h>

// create a structure Node
struct Node {
    int front;
    int rear;
    int size;
    int* Q;
};

// create node function
// setting front and rear to -1
void create(struct Node* st, int n)
{
    st->size = n;
    st->front = -1;
    st->rear = -1;
    st->Q = (int *) malloc(sizeof(int)*st->size);
}

// insert function
// add element and increment
// rear == size : queue is full
// else just add
void insert_from_front(struct Node* st, int x)
{
    // check if front and rear is -1
    if(st->front == -1 && st->rear) {
        st->front = 0;
        st->rear = 0;
        st->Q[st->rear] = x;
        st->rear = st->rear + 1;
    } else if(st->rear == st->size) {
        printf("Queue is full\n");
    } else {
        st->Q[st->rear] = x;
        st->rear = st->front + 1;
    }
}

// delete from back
void del_from_back(struct Node* st, int x)
{
    if(st->front == -1 && st->rear == -1) {
        printf("Queue is empty\n");
    } else {
        if(st->rear < st->front) {
            printf("Queue is empty\n");
            st->front = -1;
            st->rear = -1;
        } else {
            printf("%d is deleted element\n", st->Q[st->rear-1]);
            st->rear = st->rear - 1;
            st->size = st->size - 1;
        }
    }
}

void del_from_front(struct Node* st)
{
    if(st->rear == -1 && st->front == -1) {
        printf("Queue is empty\n");
        st->front = -1;
        st->rear = -1;
    } else if(st->front == st->rear) {
        printf("Queue is empty\n");
        st->front = -1;
        st->rear = -1;
    } else {
        printf("%d is deleted element:\n", st->Q[st->front]);
        st->front = st->front+1;
    }
}

void insert_from_back(struct Node *st,int x)
{
    if(st->front==-1 && st->rear==-1){
    st->front=0;
    st->rear=0;
    st->Q[st->rear]=x;
    st->rear=st->rear+1;
}else if(st->rear==st->size)
{
    printf("Queue is full:");
} else {
    st->Q[st->rear]=x;
    st->rear=st->rear+1;
    }
}

void display(struct Node st){
    int i=st.front;
    for(;i!=st.rear;i++){
    printf("%d\t",st.Q[i]);
}
    printf("\n");
}


int main()
{
    struct Node st;
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    create(&st,n);
    insert_from_front(&st,10);
    insert_from_front(&st,20);
    insert_from_front(&st,30);
    insert_from_front(&st,40);
    insert_from_front(&st,50);
    insert_from_front(&st,60);
    display(st);
    del_from_front(&st);
    del_from_front(&st);
    del_from_front(&st);
    insert_from_back(&st,600);
    insert_from_back(&st,700);
    del_from_back(&st);
    display(st);
    insert_from_front(&st,10);
    insert_from_front(&st,20);
    insert_from_front(&st,1000);
    del_from_back(&st);
    display(st);
    return 0;
}
