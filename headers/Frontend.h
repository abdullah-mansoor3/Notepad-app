#ifndef FRONTEND_H
#define FRONTEND_H

#include "Backend.h"
#include <ncurses.h> //for terminal display

class Frontend{

    Backend *backend; //reference to backend for interacting with data structures

    public:

    Frontend(Backend *backendPointer);

    void initScreen();

    void display();

    bool takeInput(); //returns false when the notepad is exited

};

#endif