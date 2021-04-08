#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};
int size = 0;
struct Queue* q1, *q2, *temp;

struct Queue* createQueue(int n)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = n;
    queue->front = queue->size = 0;

    queue->rear = n - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
void swap(struct Queue* q1, struct Queue* q2) {
    int sz = q1->size;
    for(int i = 0; i < sz; i++) {
        enqueue(temp, front(q1));
        dequeue(q1);
    }
    sz = q2->size;
    for(int i = 0; i < sz; i++) {
        enqueue(q1, front(q2));
        dequeue(q2);
    }
    sz = temp->size;
    for(int i = 0; i < sz; i++) {
        enqueue(q2, front(temp));
        dequeue(temp);
    }


}


void push(int x) {
    size++;
    enqueue(q2, x);

    while(!isEmpty(q1)) {

        enqueue(q2,front(q1));
        dequeue(q1);
    }
    swap(q1,q2);
}

void pop() {
    dequeue(q1);
    size--;
}

void print() {
    printf("%d\n",front(q1));
}
int main() {

    int n;
    scanf("%d",&n);

    char command[6];
    int x;
int size = 0;
q1 = createQueue(N);
q2 = createQueue(N);
temp = createQueue(N);
    for(int i = 0; i < n; i++) {
        scanf("%s",command);
        if(command[0] == 'P' && command[1] == 'U') {
            scanf("%d",&x);
            push(x);
        }
        else if(command[0] == 'P' && command[1] == 'O')
            pop();
        else
            print();

    }
}