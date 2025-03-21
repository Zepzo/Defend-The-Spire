#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 510

typedef struct GridPos{
    int x;
    int y;
}GridPos;

typedef struct Tile{
    int x;
    int y;
    int direction;
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

void enqueue(Queue* q, int x, int y)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear].x = x;
    q->items[q->rear].y = y;
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

bool peek(Queue* q, GridPos* g)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return true;    // return some default value or handle
                   // error differently
    }
    g->x = q->items[q->front + 1].x;
    g->y = q->items[q->front + 1].y;
    return false;
}