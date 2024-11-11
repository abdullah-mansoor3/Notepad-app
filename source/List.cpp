#include "../headers/List.h"

#include<iostream>

using namespace std;

ListNode::ListNode(char c) :
    letter(c),
    next(nullptr),
    previous(nullptr)
    {}

List::List():
    head(nullptr),
    tail(nullptr)
    {}

List::~List() {
    while(!isEmpty()){
        deleteLast();
    }
}

void List::insertAtEnd(char letter){
    ListNode *newNode = new ListNode(letter);

    if(!head){
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
}

char List::deleteLast(){
    if(!head){
        return '\0';
    }

    ListNode *deleted = tail;

    char letter = deleted->letter;
    tail = tail->previous;
    if(tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete deleted;
    return letter;
}

string List::lastWord(){
    if(!head){
        return "";
    }

    string lastWord = "";

    ListNode *curr = tail;
    //move past the spaces at the end
    while(curr && curr->letter==' '){
        curr = curr->previous;
    }

    //store the word till a space is encountered
    while(curr && curr->letter != ' '){
        lastWord = curr->letter + lastWord;
        curr = curr->previous;
    }

    return lastWord;
}

char List::lastLetter(){
    if(!tail){
        return '\0';
    }

    return tail->letter;
}

string List::getInStringForm(){
    string text = "";

    ListNode *curr = head;

    while(curr){
        text = text + curr->letter;
        curr = curr->next;
    }

    return text;
    
}

void List::insertString(string text){
    deleteList(); //delete the existing text and then load the new text

    for(char c : text){
        insertAtEnd(c);
    }
}

bool List::isEmpty(){
    return !head;
}

void List::deleteList(){
    while(!isEmpty()){
        deleteLast();
    }
}

void List::display(){
    ListNode *curr = head;
    cout<<"\n";
    while(curr){
        cout<<curr->letter;
        curr = curr->next;
    }
    cout<<endl;
}