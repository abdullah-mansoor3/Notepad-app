#include "../headers/Backend.h"

#include<iostream>
#include<string>

using namespace std;

Backend::Backend(){
    // initDictionary();
}

Backend::~Backend(){
    exitNotepad();
}

void Backend::initDictionary(){
    ifstream file("dictionary.txt");

    if(!file){
        cerr << "\nError: could not read dictionary.txt\n";
        return;
    }

    string line;

    while(getline(file, line)){

        if(!line.empty())
            dictionary.insertNode(line);
    }

    file.close();
}

void Backend::saveToFile(){
    string textToSave = text.getInStringForm();

    ofstream file("notepad.txt");

    if(!file){
        cerr << "\nCounld not save file to notepad.txt\n";
        return;
    }

    file<<textToSave;

    file.close();
}

void Backend::exitNotepad(){
    dictionary.deleteTree();
    text.deleteList();
    currentWord.deleteStack();
}

void Backend::insertLetter(char letter){

    text.insertAtEnd(letter);

    //get the last letter from the text and insert it in the stack
    currentWord.insertWord(text.lastWord());
}

void Backend::deleteLastLetter(){

    text.deleteLast();

    //update the last word
    currentWord.insertWord(text.lastWord());

}

void Backend::display(){
    cout<<"\n\nCurr word:";
    currentWord.display();

    cout<<"\nText:\n";
    text.display();
}