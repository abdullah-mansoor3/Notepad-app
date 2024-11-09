#include "../headers/AVL.h"
#include <iostream>

using namespace std;

AVLNode::AVLNode(string Word) : word(Word), leftChild(nullptr), rightChild(nullptr), height(0) {}

int AVLNode::height(){
    if()
}

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

void AVL::insertNode(string name){

}