#include "../headers/Stack.h"
#include<iostream>

using namespace std;

StackNode::StackNode(char c):
    letter(c), 
    next(nullptr)
    {}


Stack::Stack():
    head(nullptr)
    {}


Stack::~Stack(){
    deleteStack();
}

void Stack::insert(char c){

    StackNode *newNode = new StackNode(c);

    newNode->next = head;
    head = newNode;
}

char Stack::pop(){
    if(!head){
        return '\0';
    }

    char letter = head->letter;

    StackNode *deleted = head;

    head = head->next;

    delete deleted;

    return letter;
}

bool Stack::isEmpty(){
    return !head;
}

void Stack::deleteStack(){
    while(!isEmpty()){
        pop();
    }
}

void Stack::insertWord(std::string word){
    deleteStack();

    for(char c:word){
        insert(c);
    }
}