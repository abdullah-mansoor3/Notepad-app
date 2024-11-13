#ifndef LIST_H
#define LIST_H

#include<string>

using namespace std;

struct ListNode{

    char letter;
    ListNode *next;
    ListNode *previous;

    ListNode(char c);
};

class List{
    ListNode *head;
    ListNode *tail;

    public:
    
    List();

    ~List();

    void insertAtEnd(char letter);

    char deleteLast();

    std::string lastWord(); //to insert in stack when a whole word is deleted

    char lastLetter();

    std::string getInStringForm(); //to store in file

    void insertString(std::string text); //to get the contents of a file and store it in the list

    bool isEmpty();

    void deleteList();

    void display();

    void updateLastWord(string word);

};

#endif