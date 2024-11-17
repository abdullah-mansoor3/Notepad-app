#include "../headers/globalVars.h"
#include "../headers/AVL.h"
#include <iostream>
#include <string>

using namespace std;

AVLNode::AVLNode(std::string Word) :
    word(Word),
    left(nullptr),
    right(nullptr),
    height(1)
    {}


AVL::AVL() :
    root(nullptr)
    {}

AVL::~AVL(){
    deleteTree();
}

void AVL::deleteTree(AVLNode* node){
    if (node){
        deleteTree(node->left);  // Recursively delete left subtree
        deleteTree(node->right);  // Recursively delete right subtree
        delete node;              // Delete the current node
    }
}

void AVL::deleteTree(){
    deleteTree(root);
    root = nullptr;
}

AVLNode* AVL::insertNode(string word, AVLNode *node){
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

void AVL::insertNode(string word){
    root = insertNode(word, root);
}


bool AVL::search(string word){

    AVLNode *curr = root;

    while(curr){

        string currWord = curr->word;

        if(currWord == word)
            return true;
        else if(word > currWord)
            curr = curr->right;
        else
            curr = curr->left;
    }

    return false; //not found
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
    if(!node || !node->left)
        return node;

    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

AVLNode* AVL::rightRotate(AVLNode *node){
    if(!node || !node->right)
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

string* AVL::getSuggestions(string word){

    string *suggestions = new string[NUM_OF_SUGGESTED_WORDS];

    if(word == "") //if we got an empty word
        for(int i = 0;i<NUM_OF_SUGGESTED_WORDS;i++)
            suggestions[i] = "0";
    else{
        suggestions[0] = searchByInsertion(word);
        suggestions[1] = searchBySubstitution(word);
        suggestions[2] = searchByOmission(word);
        suggestions[3] = searchByReversal(word);
    }

    return suggestions;
}

string AVL::searchByInsertion(string word){

    string correctedWord = word;

    for(char c = 'a'; c <= 'z'; c++){
        for(size_t i = 0; i <= (word.length()); i++){
            correctedWord.insert(i, 1, c); // (position, num of chars, chars)

            if(search(correctedWord)){ //if the word is in the dictionary
                return correctedWord;
            }

            correctedWord = word; //revert to original word
        }
    }

    return "0"; //no suggestion found
}

string AVL::searchBySubstitution(string word){

    string correctedWord = word;

    for(char c = 'a'; c <= 'z'; c++){
        for(size_t i = 0; i < (word.length()); i++){
            correctedWord[i] = c; //replace

            if(search(correctedWord)){ //if the word is in the dictionary
                return correctedWord;
            }

            correctedWord = word; //revert to original word
        }
    }

    return "0"; //no suggestion found

}

string AVL::searchByOmission(string word){

    string correctedWord = word;

    for(size_t i = 0; i < (word.length()); i++){
        correctedWord.erase(i, 1); //remove the char at i

        if(search(correctedWord)){ //if the word is in the dictionary
            return correctedWord;
        }

        correctedWord = word; //revert to original word
    }

    return "0"; //no suggestion found

}

string AVL::searchByReversal(string word){

    string correctedWord = word;

    for (size_t i = 0; i < (word.length()) - 1; i++){
        
        swap(correctedWord[i], correctedWord[i + 1]);  //swap adjacent characters
        if (search(correctedWord)) {
            return correctedWord;
        }
        correctedWord = word; //revert to original word 
    }

    return "0"; //no suggestion found

}