#ifndef RAIDX_SORT_LINKEDQUEUE_H
#define RAIDX_SORT_LINKEDQUEUE_H

#define FALSE 0
#define TRUE 1

typedef struct QueueNodeType //linkedlist
{
    int data;
    struct QueueNodeType *pLink;
}QueueNode;

typedef struct QueueType //queue
{   
    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
}Queue;

Queue *createQueue();
void deleteQueue(Queue *pQueue);
int enqueue(Queue *pQueue, QueueNode node);
QueueNode *dequeue(Queue *pQueue);
QueueNode *peek(Queue *pQueue);
int isQueueEmpty(Queue *pQueue);

#endif //RAIDX_SORT_LINKEDQUEUE_H