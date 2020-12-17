// avl.cpp
// Zachary Friedland 
// K-AVL Tree cpp file

#include "avl.h"
#include <tuple>
#include <iostream>
#include <string>

using namespace std;

// DONE
AVL::AVL() : root(nullptr) { }  

// DONE
AVL::~AVL(){
    clear(root);
} 

// DONE
void AVL::clear(Node* n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// DONE
bool AVL::insert(tuple<int, int> target){
    if(!root){
        root = new Node(make_tuple(get<0>(target), get<1>(target)));
        cout << get<0>(root->data) << "." << get<1>(root->data) << " inserted" << endl;
        return true;
    }
    return insert(target, root);
}

bool AVL::insert(tuple<int, int> target, Node* n){
    // TO DO ---------------------
    return false;
}

// DONE
bool AVL::search(tuple<int, int> target){
    if(!root){
        cout << get<0>(root->data) << "." << get<1>(root->data) << " not found" << endl;
        return false;
    }
    else if(this->getNode(target, root) != 0){
        cout << get<0>(root->data) << "." << get<1>(root->data) << " found" << endl;
        return true;
    }
    return false;
}

// DONE??
// bool AVL::search(tuple<int, int> target, Node* n){
//     if(!n){
//         return false;
//     }
//     if(n){
//         if(n->data == target){
//             cout << get<0>(n->data) << "." << get<1>(n->data) << " found" << endl;
//             return true;
//         }
//         else if(target < n->data){
//             return search(target, n->left);
//         }
//         else if(target > n->data){
//             return search(target, n->right);
//         }
//     }
//     return false;
// }

bool AVL::approximateSearch(tuple<int, int> target){
    // TO DO
    return approximateSearch(target, root);
}

bool AVL::approximateSearch(tuple<int, int> target, Node* n){
    // TO DO
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

void AVL::printInOrder(){
    printInOrder(root);
}

void AVL::printInOrder(Node* n){
    if(n){
        printPreOrder(n->left);
        cout << get<0>(n->data) << "." << get<1>(n->data) << " ";
        printPreOrder(n->right);
    }
}

AVL::Node* AVL::getNode(tuple<int, int> target, Node* n){
    if(n){
        if(n->data == target){
            return n;
        }
        else if(target < n->data){
            return getNode(target, n->left);
        }
        else if(target > n->data){
            return getNode(target, n->right);
        }
    }
    return 0;
}

AVL::Node* AVL::getPredecessorNode(tuple<int, int> target){
    Node* t = this->getNode(target, root);
    if(!t){
        return 0;
    }
    else if(t->left){
        t = t->left;
        while(t->right){
            t = t->right;
        }
        return t;
    }

    while(t->parent && t->parent->left == t){
        t = t->parent;
    }
    return t->parent;
}

AVL::Node* AVL::getSuccessorNode(tuple<int, int> target){
    Node* t = this->getNode(target, root);
    if(!t){
        return 0;
    }
    else if(t->right){
        t = t->right;
        while(t->left){
            t = t->left;
        }
        return t;
    }

    while(t->parent && t->parent->right == t){
        t = t->parent;
    }
    return t->parent;
}

void AVL::rotate(Node* n){
    // TO DO
}

bool AVL::remove(tuple<int, int> target){
    // TO DO
    return false;
}


