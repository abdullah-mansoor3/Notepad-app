#ifndef AVL_H
#define AVL_H

struct AVLNode{

    string word;
    AVLNode *leftChild;
    AVLNode *rightChild;
    int height;

    AVLNode();

    int height();

};

class AVL{

    AVLNode *root;

    public:

    AVL();

    ~AVL();

    void deleteTree(AVLNode *Node);

    void insertNode(string word);
    
    void rightRotate(AVLNode *Node);

    void leftRotate(AVLNode *Node);
    
    void rightLeftRotate(AVLNode *Node); //first right then left
    
    void leftRightRotate(AVLNode *Node); //first left then right


};

#endif