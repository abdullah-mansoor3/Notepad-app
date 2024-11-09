#include "headers/AVL.h"
#include "headers/Stack.h"
#include<iostream>

using namespace std;

int main(){

    Stack s;
    s.insertWord("abcdef");
    cout<<s.isEmpty();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.isEmpty();

    return 0;
}