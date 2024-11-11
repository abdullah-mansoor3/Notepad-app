#ifndef AVL_H
#define AVL_H

#include<string>

using namespace std;


struct AVLNode{

    std::string word;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(std::string Word);

};

class AVL{

    AVLNode *root;

    public:

    AVL();

    ~AVL();

    void deleteTree(AVLNode *node);

    void deleteTree();

    AVLNode* insertNode(std::string word, AVLNode *node);

    void insertNode(std::string word);

    bool search(string word);
    
    AVLNode* rightRotate(AVLNode *node);

    AVLNode* leftRotate(AVLNode *node);
    
    AVLNode* rightLeftRotate(AVLNode *node); //first right then left
    
    AVLNode* leftRightRotate(AVLNode *node); //first left then right

    int height(AVLNode *node);

    int balanceFactor(AVLNode *node);

    string *getSuggestions(string word); //returns at max NUM_OF_SUGGESTED_WORDS suggestions for the word

    //these funcs will return "0" if no suggestion was found
    string searchBySubstitution(string word);

    string searchByOmission(string word);

    string searchByInsertion(string word);

    string searchByReversal(string word);

};

#endif