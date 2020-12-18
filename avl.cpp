// avl.cpp
// Zachary Friedland 
// K-AVL Tree cpp file

#include "avl.h"
#include <tuple>
#include <iostream>
#include <string>
#include <cmath>

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
    // if(!root){
    //     root = new Node(make_tuple(get<0>(target), get<1>(target)));
    //     cout << get<0>(root->data) << "." << get<1>(root->data) << " inserted" << endl;
    //     return true;
    // }
    return insert(target, root);
}

// TO DO ROTATION
AVL::Node* AVL::insert(tuple<int, int> target, Node* n){
    if(!root){
        root = new Node(make_tuple(get<0>(target), get<1>(target)));
        cout << get<0>(root->data) << "." << get<1>(root->data) << " inserted" << endl;
        return root;
    }

    if(!n){
        Node* in = new Node(target);
        cout << get<0>(in->data) << "." << get<1>(in->data) << " inserted" << endl;
        return in;
    }

    if(target == n->data)
        return n;
    else if(target < n->data){
        n->left = insert(target, n->left);
    }
    else{   // target > n->data
        n->right = insert(target, n->right);
    }

    n->height = max(n->getHeight(n->left), n->getHeight(n->right)) + 1;
    int balance = n->getBalanceFactor(n);

    // If unbalanced, 4 cases

    // Left left rotation
    if(balance > 1 && target < n->left->data){
        return rotateRight(n);
    }

    // Right right rotation
    if(balance < -1 && target > n->right->data){
        return rotateLeft(n);
    }

    // Left right rotation
    if(balance > 1 && target > n->left->data){
        n->left = rotateLeft(n->left);
        return rotateRight(n);
    }

    // Right left rotation
    if(balance < -1 && target < n->right->data){
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

    return n;

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
    else{
        cout << get<0>(target) << "." << get<1>(target) << " not found" << endl;
    }
    return false;
}

// DONE
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

// DONE
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

// DONE - NEEDS CHECKING
void AVL::approximateSearch(tuple<int, int> target){
    if(root){
        tuple<int, int> pred = getPredecessor(root, root, target);
        tuple<int, int> suc = getSuccessor(root, root, target);

        if(pred == target && suc == target){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        string predString = to_string(get<0>(pred)) + "." + to_string(get<1>(pred));
        string sucString = to_string(get<0>(suc)) + "." + to_string(get<1>(suc));
        string targetString = to_string(get<0>(target)) + "." + to_string(get<1>(target));
        double predNum = stod(predString);
        double sucNum = stod(sucString);
        double targetNum = stod(targetString);

        double predDiff = fabs(targetNum - predNum);
        double sucDiff = fabs(targetNum - sucNum);
        if(predDiff == sucDiff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        else if(predDiff < sucDiff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(pred) << "." << get<1>(pred) << endl;
        }
        else if(predDiff > sucDiff){
            cout << "closest to " << get<0>(target) << "." << get<1>(target) << " is " << get<0>(suc) << "." << get<1>(suc) << endl;
        }
        else{
            cout << "Error, case missed" << endl;
        }
    }
}

// DONE
void AVL::printPreOrder(){
    printPreOrder(root);
}

// DONE
void AVL::printPreOrder(Node* n){
    if(n){
        cout << get<0>(n->data) << "." << get<1>(n->data) << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// DONE
void AVL::printInOrder(){
    printInOrder(root);
}

// DONE
void AVL::printInOrder(Node* n){
    if(n){
        printInOrder(n->left);
        cout << get<0>(n->data) << "." << get<1>(n->data) << " ";
        printInOrder(n->right);
    }
}

// DONE
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

// DONE
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

// DONE
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

AVL::Node* AVL::rotateLeft(Node* x){
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(x->getHeight(x->left), x->getHeight(x->right)) + 1;
    y->height = max(y->getHeight(y->left), y->getHeight(y->right)) + 1;

    return y;
}

AVL::Node* AVL::rotateRight(Node* y){
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(y->getHeight(y->left), y->getHeight(y->right)) + 1;
    x->height = max(x->getHeight(x->left), x->getHeight(x->right)) + 1;

    return x;
}

bool AVL::remove(tuple<int, int> target){
    // TO DO
    return false;
}