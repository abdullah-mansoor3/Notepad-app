#include "../headers/Frontend.h"
#include "../headers/Backend.h"
#include "../headers/globalVars.h"
#include<ncurses.h>
#include<iostream>
#include<string>

using namespace std;

Frontend::Frontend(Backend *backendPointer) :
    backend(backendPointer)
    {}

void Frontend::initScreen(){
    initscr();           // Initialize screen
    raw();               // Disable line buffering, so input is available immediately
    keypad(stdscr, TRUE); // Enable special keys like arrow keys
    noecho();            // Disable echoing of typed characters
    curs_set(1);         // Make the cursor visible
}

void Frontend::display(){

    string text = backend->getText(); //get the text stored in the list

    int rows, cols;
    getmaxyx(stdscr, rows, cols);  //get screen size

    //dimensions for the notepad box
    int box_height = rows - 10; //space for recommendations at the bottom
    int box_width = cols - 2;   //space for box border
    int box_start_y = 5;
    int box_start_x = 1;

    mvprintw(0, 1, "\tnotepad.txt\n\n\tLoad: Ctrl + L\t\tSave: Ctrl + S\t\tExit: Esc\t\tDelete Last Letter: Backspace\t\tChoose suggestion:1,2,3,4");
    //window for the text box
    WINDOW *textwin = newwin(box_height, box_width, box_start_y, box_start_x);
    box(textwin, 0, 0); //draw the box border

    
    //display text with wrapping
    int text_x = 1, text_y = 1;
    for (char ch : text){
        //enter new line when box width is reached
        if (text_x >= box_width - 2 || ch=='\n') {  //-2 for padding inside the box
            text_x = 1; 
            text_y++;
        }

        //stop if we reach the bottom of the box
        if (text_y >= box_height - 1) {  //-1 for bottom box border
            break;
        }

        //display the character in the box window
        mvwaddch(textwin, text_y, text_x, ch);
        text_x++;
    }


    wrefresh(textwin);

    string *suggestions = backend->getSuggestions();

    //display word suggestions at the bottom of the screen
    int start_y = rows - 4;  //suggestions line position
    int start_x = 2;         
    for (int i = 0; i < NUM_OF_SUGGESTED_WORDS; i++) {
        if(suggestions[i] != "0" && suggestions[i]!="") //only print valid suggestions
            mvprintw(start_y+i, start_x , (to_string(i+1)+".\t" + suggestions[i]).c_str());
        else    
            mvprintw(start_y+i, start_x , (to_string(i+1) + "\t\t\t\t\t\t\t\t\t\t").c_str());
    }

    //clean up the window
    delwin(textwin);
    
    refresh();
}

bool Frontend::takeInput(){ //returns true if user wants to exit
    string input;
    int ch;
    ch = getch();  // Get a single character input

    if (ch == 27) {  // ESC key
        clear(); //clear the screen

        backend->exitNotepad(); //deallocate the memory
        return true;  //exit the app
    }
    else if (ch == 12) {  // Ctrl + L
        //load the file
        backend->loadFromFile();
    }
    else if (ch == 19) {  // Ctrl + S
        // save the file
        backend->saveToFile();
    }
    else if (ch == KEY_BACKSPACE || ch == 127) {  // Backspace (handle both common values)
        backend->deleteLastLetter();
    }
    else if(ch>='1' && ch<='4'){ //user selected a suggestion
        backend->processSuggestion(ch - '0');
    }
    else if((ch >= 32 && ch <= 126) || ch==' '){ //printable keys
        backend->insertLetter(ch);    
    }
    else if(ch == KEY_ENTER || ch == '\n'){
        //add \n when enter is pressed
        backend->insertLetter(10);
    }

    return false;
}
