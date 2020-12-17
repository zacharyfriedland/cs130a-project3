// avl.cpp
// Zachary Friedland 
// K-AVL Tree cpp file

#include "avl.h"
#include <tuple>
#include <iostream>

using namespace std;

AVL::AVL() : root(nullptr) { }  

AVL::~AVL(){
    clear(root);
} 

void AVL::clear(Node* n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

bool AVL::insert(tuple<int, int> target){
    if(!root){
        root = new Node(make_tuple(get<0>(target), get<1>(target)));
        cout << get<0>(root->data) << "." << get<1>(root->data) << " inserted" << endl;
        return true;
    }
    return insert(target, root);
}

bool AVL::insert(tuple<int, int> target, Node* n){return false;}

bool AVL::search(tuple<int, int> target){
    if(!root){
        cout << get<0>(root->data) << "." << get<1>(root->data) << " not found" << endl;
        return false;
    }
    return search(target, root);
}

bool AVL::search(tuple<int, int> target, Node* n){
    if(!n){
        return false;
    }
    if(n){
        if(n->data == target){
            cout << get<0>(n->data) << "." << get<1>(n->data) << " found" << endl;
            return true;
        }
        else if(target < n->data){
            return search(target, n->left);
        }
        else if(target > n->data){
            return search(target, n->right);
        }
    }
    return false;
}

bool AVL::approximateSearch(tuple<int, int> target){
    return false;
}

void AVL::printPreOrder(){
    printPreOrder(root);
}

void AVL::printPreOrder(Node* n){
    if(n){
        cout << get<0>(n->data) << "." << get<1>(n->data) << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}
// void AVL::printInOrder();

// bool AVL::remove(tuple<int, int> target);


