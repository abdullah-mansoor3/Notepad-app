#ifndef AVL_H
#define AVL_H

#include<string>


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
    
    AVLNode* rightRotate(AVLNode *node);

    AVLNode* leftRotate(AVLNode *node);
    
    AVLNode* rightLeftRotate(AVLNode *node); //first right then left
    
    AVLNode* leftRightRotate(AVLNode *node); //first left then right

    int height(AVLNode *node);

    int balanceFactor(AVLNode *node);


};

#endif