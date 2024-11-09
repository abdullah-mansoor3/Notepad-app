#ifndef BACKEND_H
#define BACKEND_H

//for file handling
#include<fstream>

#include<string>


//data structures
#include "AVL.h"
#include "List.h"
#include "Stack.h"

class Backend{

    AVL dictionary;
    List text;
    Stack currentWord;

    public:

    Backend();

    ~Backend();

    void initDictionary();

    void saveToFile();

    void loadFromFile();

    void exitNotepad();

    std::string *getSuggestions(); //returns a dynamic array of 5 strings

    void insertLetter(char letter);

    void deleteLastLetter();

    void display();
};

#endif