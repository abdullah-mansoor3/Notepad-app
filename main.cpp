#include "headers/Frontend.h"

#include<iostream>


using namespace std;

int main(){

    Backend *backend = new Backend;

    Frontend frontend(backend);

    frontend.initScreen();
    frontend.display();

    bool exit = false;

    while(!exit){
        frontend.display();
        exit = frontend.takeInput();
    }

    return 0;
}