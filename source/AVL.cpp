#include "../headers/AVL.h"
#include <iostream>
// #include <string>
#include <cmath>

AVLNode::AVLNode(std::string Word) : word(Word), left(nullptr), right(nullptr), height(0) {}

AVL::AVL() :root(nullptr)   {}

AVL::~AVL(){
    deleteTree(root);
}

void AVL::deleteTree(AVLNode* node){
    if (node) {
        deleteTree(node->left);  // Recursively delete left subtree
        deleteTree(node->right);  // Recursively delete right subtree
        delete node;              // Delete the current node
    }
}

AVLNode* AVL::insertNode(std::string word, AVLNode *node){
    if(!node){

        //create and return a one node tree
        node = new AVLNode(word);
        return node;
    }

    if(word < node->word){
        node->left = insertNode(word, node->left);

        if( balanceFactor(node) == 2){ //if tree is unbalanced after insetion
            //here node will be heavier on the left side
            if(word < node->left->word){ //if node was inserted on the left of left
                node = rightRotate(node);
            }
            else //if node was inserted on the right of left
                node = leftRightRotate(node);
        }
    }
    else if(word > node->word){
        node->right = insertNode(word, node->right);

        if(balanceFactor(node) == -2){//if tree is right heavy
            if(word > node->right->word)//if node was inserted on the right of right
                node = leftRotate(node);
            else //if node was inserted on the left of right
                node = rightLeftRotate(node);
        }
    }

    //if node already exists then we will do nothing

    //update the height
    node->height = std::max(height(node->left), height(node->right)) + 1;

    return node;
}

void AVL::insertNode(std::string word){
    root = insertNode(word, root);
}

int AVL::height(AVLNode *node){
    if(node)
        return node->height;
    else{
        return -1;
    }
}

int AVL::balanceFactor(AVLNode *node){
    if(!node){
        return 0;
    }
    return height(node->left) - height(node->right);
}

AVLNode* AVL::leftRotate(AVLNode *node){
    if(!node)
        return node;

    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

AVLNode* AVL::rightRotate(AVLNode *node){
    if(!node)
        return node;

    AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;
    
    return newRoot;
}

AVLNode* AVL::leftRightRotate(AVLNode *node){
    if(!node)
        return node;

    node -> left = leftRotate(node->left);
    
    return rightRotate(node);
}

AVLNode* AVL::rightLeftRotate(AVLNode *node){
    if(!node)
        return node;

    node -> right = rightRotate(node->right);
    
    return leftRotate(node);
}