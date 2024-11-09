#ifndef QUEUE_H
#define QUEUE_H

#include <string>

struct StackNode{

    char letter;
    StackNode *next;

    StackNode(char c);

};

class Stack{
    StackNode *head; 

    public:

    Stack();
    ~Stack();

    void insert(char c);

    char pop();

    bool isEmpty();

    void deleteStack();

    void insertWord(std::string word);

    void display();
};

#endif