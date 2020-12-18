// avl.h
// Zachary Friedland
// K-AVL Tree header file

#ifndef AVL_H
#define AVL_H

#include <tuple>
#include <string>
using namespace std;

class AVL {
    public:
        AVL();      // constructor
        AVL(int k);
        ~AVL();     // destructor
        bool insert(tuple<int, int> target);
        bool remove(tuple<int, int> target);
        bool search(tuple<int, int> target);
        void approximateSearch(tuple<int, int> target);
        void printPreOrder();
        void printInOrder();

    
    private:
        struct Node {
            tuple<int, int> data;
            int height;
            int getHeight(Node* n){
                if(!n)
                    return 0;
                return n->height;
            }
            int getBalanceFactor(Node* n){
                if(!n)
                    return 0;
                return (n->getHeight(n->left)) - (n->getHeight(n->right));
            }

            Node* left;
            Node* right;
            Node* parent;

            Node(tuple<int,int> num = make_tuple(0, 0)) :
                         data(num), height(1), left(nullptr), right(nullptr), parent(nullptr) { }
        };
        
        int balanceConstraint;
        Node* root;
        void clear(Node* n);
        Node* insert(tuple<int, int> target, Node* n);
        Node* remove(tuple<int, int> target, Node* n);
        bool search(tuple<int, int> target, Node* n);
        void approximateSearch(tuple<int, int> target, Node* n, double &minDiff, tuple<int, int> &minDiffNodeValue);
        Node* getNode(tuple<int, int> target, Node* n);
        Node* getPredecessorNode(tuple<int, int> target);
        Node* getSuccessorNode(tuple<int, int> target);
        void printPreOrder(Node* n);
        void printInOrder(Node* n);
        Node* rotateLeft(Node* n);
        Node* rotateRight(Node* n);
        Node* minNode(Node* n);
        tuple<int, int> getPredecessor(Node* n, Node* &predecessor, tuple<int, int> target);
        tuple<int, int> getSuccessor(Node* n, Node* &successor, tuple<int, int> target);

};




#endif