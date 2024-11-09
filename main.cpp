#include "headers/Backend.h"

#include<iostream>


using namespace std;

int main(){

    Backend notepad;

    notepad.insertLetter('h');
    notepad.insertLetter('e');

    notepad.display();

    notepad.insertLetter('l');
    notepad.insertLetter('l');
    notepad.insertLetter('o');
    notepad.insertLetter(' ');

    notepad.display();

    notepad.insertLetter('w');
    notepad.insertLetter('o');
    notepad.insertLetter('r');
    notepad.insertLetter('l');
    notepad.insertLetter('d');

    notepad.display();

    notepad.deleteLastLetter();
    notepad.deleteLastLetter();
    notepad.deleteLastLetter();

    notepad.display();

    notepad.saveToFile();

    return 0;
}