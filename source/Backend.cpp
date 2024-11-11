#include "../headers/Backend.h"

#include<iostream>
#include<string>

using namespace std;

Backend::Backend():
    currentSuggestions(nullptr)
{
    initDictionary();
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
    if(currentSuggestions)
        delete currentSuggestions;
}

void Backend::insertLetter(char letter){

    text.insertAtEnd(letter);

    //get the last letter from the text and insert it in the stack
    //thsi will automatically handle spaces
    currentWord.insertWord(text.lastWord());
}

void Backend::deleteLastLetter(){

    text.deleteLast();

    //update the last word
    currentWord.insertWord(text.lastWord());

}

string Backend::getText(){
    return text.getInStringForm();
}

void Backend::display(){
    cout<<"\n\nCurr word:";
    currentWord.display();

    cout<<"\nText:\n";
    text.display();
}

void Backend::loadFromFile(){

    currentWord.deleteStack(); //delete the current word

    ifstream file("notepad.txt");

    if(!file) //do nothing if file doesnt exist
        return;

    string fileText = "";

    string line;

    while(getline(file, line)){
        fileText += line;
    }

    file.close();

    text.insertString(fileText);

    currentWord.insertWord(text.lastWord()); //update the current word
}

string* Backend::getSuggestions(){
    if(currentSuggestions)
        delete currentSuggestions; //delete the previous suggestions array
    
    // get suggestions for the current word
    currentSuggestions = dictionary.getSuggestions(text.lastWord());

    return currentSuggestions;
}