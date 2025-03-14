#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 410

typedef struct Tile{
    float x;                
    float y;                
    float width;           
    float height;
    bool reached;
    bool IsWall;
}Tile;

typedef struct {
    Tile items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue* q) { return (q->front == q->rear - 1); }

bool isFull(Queue* q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue* q, Tile value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

void dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

Tile peek(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return q->items[0]; // return some default value or handle
                   // error differently
    }
    return q->items[q->front + 1];
}