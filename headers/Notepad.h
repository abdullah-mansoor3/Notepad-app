#ifndef NOTEPAD_H
#define NOTEPAD_H

#include  "Frontend.h"
#include  "Backend.h"

class Notepad{

    Backend *backend;
    Frontend *frontend;

    public:

    Notepad();

    ~Notepad();

    bool doEverything();

};

#endif