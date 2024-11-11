#include "headers/Notepad.h"

#include<iostream>


using namespace std;

int main(){

    Notepad notepad;;

    bool exit = false;

    while(!exit){
        exit = notepad.doEverything();
    }

    return 0;
}