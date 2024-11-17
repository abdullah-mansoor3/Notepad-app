#ifndef BACKEND_H
#define BACKEND_H

//for file handling
#include<fstream>

#include<string>

//data structures
#include "AVL.h"
#include "List.h"
#include "Stack.h"
#include "globalVars.h"

using namespace std;

class Backend{

    AVL dictionary;
    List text;
    Stack currentWord;
    string *currentSuggestions;

    public:

    Backend();

    ~Backend();

    void initDictionary();

    void saveToFile();

    void loadFromFile();

    void exitNotepad();

    string *getSuggestions(); //returns a dynamic array of NUM_OF_SUGGESTED_WORDS strings

    void insertLetter(char letter);

    void deleteLastLetter();

    void display();

    string getText();

    void processSuggestion(int suggestionNumber);
};

#endif