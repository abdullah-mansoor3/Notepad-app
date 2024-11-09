#include "headers/AVL.h"
#include "headers/Stack.h"
#include "headers/List.h"
#include<iostream>

using namespace std;

int main(){

    List l;

    l.insertString("Hello my name is Abdullah");

    cout<<l.lastWord();

    l.deleteLast();
    l.deleteLast();
    l.deleteLast();
    l.deleteLast();
    l.deleteLast();
    l.deleteLast();
    l.deleteLast();
    l.deleteLast();

    cout<<endl<<l.getInStringForm();

    return 0;
}