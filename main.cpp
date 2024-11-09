#include "headers/AVL.h"

using namespace std;

int main(){

    AVL dictonary;
    string s = "a";

    dictonary.insertNode(s);

    s= "b";
    dictonary.insertNode(s);
    s= "c";
    dictonary.insertNode(s);
    s= "e";
    dictonary.insertNode(s);
    s= "d";
    dictonary.insertNode(s);
    s= "f";
    dictonary.insertNode(s);
    return 0;
}