#include "../headers/Notepad.h"

Notepad::Notepad() :
    backend(new Backend),
    frontend(new Frontend(backend))
    {
        frontend->initScreen();
    }

Notepad::~Notepad(){
    delete backend;
    delete frontend;
}

bool Notepad::doEverything(){ //will return false when user wants to exit
    frontend->display();
    return frontend->takeInput();
}