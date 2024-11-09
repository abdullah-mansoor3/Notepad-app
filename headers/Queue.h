#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode{

    char letter;
    QueueNode *next;

    QueueNode(char c);

}

class Queue{
    QueueNode *head;
    QueueNode *tail;

    public:

    Queue();

    ~Queue();

    void enqueue(char c);

    char dequeue();

    bool isEmpty();

    void deleteQueue();
};

#endif