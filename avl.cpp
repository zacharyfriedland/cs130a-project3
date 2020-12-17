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

// TO DO ROTATION
bool AVL::insert(tuple<int, int> target, Node* n){
    if(target == n->data)
        return false;
    else if(target < n->data){
        if(n->left){
            return insert(target, n->left);
        }
        else{
            tuple<int,int> t = make_tuple(get<0>(target), get<1>(target));
            n->left = new Node(t);
            n->left->parent = n;
            // CHECK ROTATION??
            return true;
        }
    }
    else{   // target > n->data
        if(n->right){
            return insert(target, n->right);
        }
        else{
            tuple<int,int> t = make_tuple(get<0>(target), get<1>(target));
            n->right = new Node(t);
            n->right->parent = n;
            // CHECK ROTATION??
            return true;
        }
    }
}

// DONE
bool AVL::search(tuple<int, int> target){
    if(!root){
        cout << get<0>(target) << "." << get<1>(target) << " not found" << endl;
        return false;
    }
    else if(this->getNode(target, root) != 0){
        cout << get<0>(target) << "." << get<1>(target) << " found" << endl;
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

tuple<int, int> AVL::getPredecessor(Node* n, Node* &predecessor, tuple<int, int> target){
    while(n){
        // target exists
        if(n->data == target){
            if(n->left){
                n = n->left;
                while(n->right){
                    n = n->right;
                }
                predecessor = n;
                return predecessor->data;
            }
            return target;
        }
        // whole of target less than current Node
        if(get<0>(target) < get<0>(n->data)){
            n = n->left;
        }
        // whole is the same and decimal of current Node is greater than decimal of target
        else if(get<0>(target) == get<0>(n->data) && get<1>(n->data) > get<1>(target)){
            n = n->left;
        }
        // whole is less than whole of target
        else if(get<0>(n->data) < get<0>(target)){
            predecessor = n;
            n = n->right;
        }
        // decimal is greater
        else{
            predecessor = n;
            n = n->right;
        }
    }
    return predecessor->data;
}

tuple<int, int> AVL::getSuccessor(Node* n, Node* &successor, tuple<int, int> target){
    while(n){
        // target exists
        if(n->data == target){
            if(n->right){
                n = n->right;
                while(n->left){
                    n = n->left;
                }
                successor = n;
                return successor->data;
            }
            return target;
        }
        // whole of target greater than current Node
        if(get<0>(target) > get<0>(n->data)){
            n = n->right;
        }
        // whole is the same and decimal of current Node is less than decimal of target
        else if(get<0>(target) == get<0>(n->data) && get<1>(n->data) < get<1>(target)){
            n = n->right;
        }
        // whole is greater than whole of target
        else if(get<0>(n->data) > get<0>(target)){
            successor = n;
            n = n->left;
        }
        // decimal is greater
        else{
            successor = n;
            n = n->left;
        }
    }
    return successor->data;
}

void AVL::approximateSearch(tuple<int, int> target){
    if(root){
        tuple<int, int> pred = getPredecessor(root, root, target);
        tuple<int, int> suc = getSuccessor(root, root, target);

        if(pred == target && suc == target){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        int pred0diff = abs(get<0>(target) - get<0>(pred));
        int pred1diff = abs(get<1>(target) - get<1>(pred));
        int suc0diff = abs(get<0>(target) - get<0>(suc));
        int suc1diff = abs(get<1>(target) - get<1>(suc));
        if(pred0diff == suc0diff && pred1diff == suc1diff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        else if(pred0diff < suc0diff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        else if(suc0diff > pred0diff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(suc) << "." << get<1>(suc) << endl;
        }
        else if(pred1diff < suc1diff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        else if(pred1diff > suc1diff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(suc) << "." << get<1>(suc) << endl;
        }
        else{
            cout << "Error, case missed" << endl;
        }
    }
}

// void AVL::approximateSearch(tuple<int, int> target, Node* n, double &minDiff, tuple<int, int> &minDiffNodeValue){
//     // TO DO
//     // if(!root){
//     //     return;
//     // }
//     // else if((!root->left) && (!root->right)){
//     //     cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(root->data) << "." << get<1>(root->data) << endl;
//     // }
//     // else if(this->getNode(target, root) != 0){
//     //     Node* t = this->getNode(target, root);
//     //     cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(t->data) << "." << get<1>(t->data) << endl;
//     // }
//     // else{
//     //     if(n)
//     // }

//     if(!n)
//         return;
    
    
// }

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