#include "../headers/Backend.h"

#include<iostream>
#include<string>

using namespace std;

Backend::Backend():
    currentSuggestions(nullptr)
    {
        maxWordLength = 0;
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

        if(!line.empty()){
            //first remove escape chaarcters
            size_t start = 0;
            size_t end = line.length() - 1;

            while( (start < line.length()) && ( (line[start] == '\t') || (line[start] == '\n') || (line[start] == '\r') )  ){
                ++start;
            }

            while (end > start && (line[end] == '\t' || line[end] == '\n' || line[end] == '\r')) {
                --end;
            }

            line = line.substr(start, end - start + 1);
            int lineLength = line.length();

            if(lineLength>maxWordLength)
                maxWordLength = lineLength;

            dictionary.insertNode(line);
        }
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


    ifstream file("notepad.txt");

    if(!file) //do nothing if file doesnt exist
        return;

    
    currentWord.deleteStack(); //delete the current word
    text.deleteList(); //delete the text

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
    if(currentSuggestions != nullptr)
        delete[] currentSuggestions; //delete the previous suggestions array
    
    //dont get suggestions if the last letter is space 
    if(text.lastLetter() == ' '){ 
        return dictionary.getSuggestions("");
    }

    string word = text.lastWord();

    currentSuggestions = dictionary.getSuggestions(word);// get suggestions for the current word i.e last word

    return currentSuggestions;
}

void Backend::processSuggestion(int suggestionNumber){
    if(suggestionNumber<1 || suggestionNumber>4 || !currentSuggestions){ //index out of bound or no suggestions yet
        return;
    }

    suggestionNumber--; //for indexing

    //no suggestion found at current index
    if(currentSuggestions[suggestionNumber] == "0"){
        return;
    }

    string suggestion = currentSuggestions[suggestionNumber];
    text.updateLastWord(suggestion);
    text.insertAtEnd(' ');
    string lastWord = text.lastWord();
    currentWord.insertWord(lastWord);
}